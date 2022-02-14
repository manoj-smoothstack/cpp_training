
//          Copyright Anthony Williams
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)


#include <iostream>
#include <future>
#include <exception>
#include <stdexcept>
#include <cassert>

void test_inactive_promise() {
    std::promise<int> pr;
}

void test_active_unused_promise() {
    std::promise<int> pr;
    auto fut = pr.get_future();
}

void test_too_many_futures() {
    std::promise<int> pr;
    auto fut1 = pr.get_future();
    auto fut2 = pr.get_future();  //   Error: "Future already retrieved"
}

int test_satisfied_promise() {
    std::promise<int> pr;
    auto fut = pr.get_future();
    {
        std::promise<int> pr2(std::move(pr));
        pr2.set_value(10);
    }
    return fut.get();
}

int test_too_much_satisfaction() {
    std::promise<int> pr;
    auto fut = pr.get_future();

    {
        std::promise<int> pr2(std::move(pr));
        pr2.set_value(10);
        pr2.set_value(10);  // Error: "Promise already satisfied"
    }
    return fut.get();
}

int test_exception() {
    std::promise<int> pr;
    auto fut = pr.get_future();
    {
        std::promise<int> pr2(std::move(pr));
        pr2.set_exception(std::make_exception_ptr(std::runtime_error("Booboo")));
    }
    return fut.get();
}

int test_broken_promise() {
    std::promise<int> pr;
    auto fut = pr.get_future();
    {
        std::promise<int> pr2(std::move(pr));
    }   // Error: "broken promise"
    return fut.get();
}

int main() {
    test_inactive_promise();
    test_active_unused_promise();
    try {
        test_too_many_futures();
    } catch (std::future_error const & e) {
        std::cout << "Future error: " << e.what() << " / " << e.code() << std::endl;
    }

    assert(test_satisfied_promise() == 10);

    try {
        test_too_much_satisfaction();
    } catch (std::exception const & e) {
        std::cout << "Standard exception: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Unknown exception." << std::endl;
    }

    try {
        test_exception();
    } catch (...) {
        std::cout << "Unknown exception." << std::endl;
    }

    try {
        test_broken_promise();
    } catch (...) {
        std::cout << "Unknown exception." << std::endl;
    }
}
