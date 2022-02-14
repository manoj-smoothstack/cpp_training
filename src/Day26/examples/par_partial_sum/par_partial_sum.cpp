
//          Copyright Anthony Williams
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)


#include <future>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cassert>
#include <cmath>
#include <numeric>

struct join_threads {
    std::vector<std::thread>& myvec;
    join_threads(std::vector<std::thread>& vec) : myvec(vec) {}
    ~join_threads() {
        for (auto& ele : myvec) {
            ele.join();
        }
    }
};

template<typename Iterator>
void parallel_partial_sum(Iterator first, Iterator last) {
    typedef typename Iterator::value_type value_type;
    struct process_chunk {
        void operator() (Iterator begin,Iterator last,
                        std::future<value_type>* previous_end_value,
                        std::promise<value_type>* end_value) {
            try {
                Iterator end = last;
                ++end;
                std::partial_sum(begin, end, begin);
                if (previous_end_value) {
                    const value_type& addend = previous_end_value->get();
                    *last += addend;
                    if(end_value) {
                        end_value->set_value(*last);
                    }
                    std::for_each(begin, last, [addend](value_type& item) { item += addend; });
                } else if (end_value) { end_value->set_value(*last); }
            } catch(...) {
                if (end_value) {
                    end_value->set_exception(std::current_exception());
                } else {
                    throw;
                }
            }
        }
    };

    unsigned long const length=std::distance(first,last);
    if(!length) return;
    unsigned long const min_per_thread=25;
    unsigned long const max_threads= (length+min_per_thread-1)/min_per_thread;
    unsigned long const hardware_threads= std::thread::hardware_concurrency();
    unsigned long const num_threads= std::min(hardware_threads!=0?hardware_threads:2,max_threads);
    unsigned long const block_size=length/num_threads;
    typedef typename Iterator::value_type value_type;

    std::vector<std::thread> threads(num_threads-1);
    std::vector<std::promise<value_type> > end_values(num_threads-1);
    std::vector<std::future<value_type> > previous_end_values;
    previous_end_values.reserve(num_threads-1);
    join_threads joiner(threads);

    Iterator block_start=first;
    for(unsigned long i = 0; i < (num_threads-1); ++i) {
        Iterator block_last = block_start;
        std::advance(block_last,block_size-1);
        threads[i]=std::thread(process_chunk(),
                               block_start, block_last,
                               (i!=0)?&previous_end_values[i-1]:0,
                               &end_values[i]);
        block_start=block_last;
        ++block_start;
        previous_end_values.push_back(end_values[i].get_future());
    }
    Iterator final_element=block_start;
    std::advance(final_element,std::distance(block_start,last)-1);
    process_chunk()(block_start, final_element,
                    (num_threads>1)?&previous_end_values.back():0,
                    0);
}

int main(void) {
    std::vector<int> myvec;
    for (int ii = 0; ii < 10000; ii++) {
        myvec.push_back(ii);
    }
    std::vector<int>::iterator iter = myvec.begin();
    iter += 5000;
    myvec.insert(iter, -1);
    parallel_partial_sum(myvec.begin(), myvec.end());
    assert(myvec[1] == 1);
    assert(myvec[2] == 3);
    assert(myvec[3] == 6);
}


