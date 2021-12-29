#include <vector>
#include <thread>
#include <numeric>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

template<typename Iterator,typename T> struct accumulate_block {
    void operator()(Iterator first, Iterator last, T& result) {
        result = std::accumulate(first,last,result);
    }
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init) {
    unsigned long const length=std::distance(first, last);
    if (!length)
        return init;
    unsigned long const min_per_thread = 25;
    unsigned long const max_threads = (length+min_per_thread-1)/min_per_thread;
    unsigned long const hardware_threads = std::thread::hardware_concurrency();
    unsigned long const num_threads = std::min(hardware_threads!=0?hardware_threads:2,max_threads);
    std::cout << "num_threads: " << num_threads << std::endl;
    unsigned long const block_size = length/num_threads;
    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads-1);
    Iterator block_start = first;
    for (unsigned long i = 0; i < (num_threads-1); ++i) {
        Iterator block_end = block_start;
        std::advance(block_end, block_size);
        threads[i] = std::thread(accumulate_block<Iterator,T>(), block_start, block_end,std::ref(results[i]));
        block_start = block_end;
    }
    accumulate_block<Iterator,T>() (block_start, last, results[num_threads-1]);
    for (auto& entry: threads)
           entry.join();
    return std::accumulate(results.begin(), results.end(), init);
}

int main(void) {
    constexpr long LEN = 20000;
    std::vector<checked_uint1024_t> myvec;
    for (long ii = 0; ii < LEN; ii++) {
        myvec.push_back(ii);
    }
    checked_uint1024_t sum = parallel_accumulate(myvec.begin(), myvec.end(), checked_uint1024_t(0));
    std::cout << "sum: " << sum << std::endl;
    assert(sum == checked_uint1024_t("199990000"));
}

