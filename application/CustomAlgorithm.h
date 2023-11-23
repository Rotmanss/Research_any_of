//#pragma once
//
//#include <algorithm>
//#include <vector>
//#include <chrono>
//#include <thread>
//#include <semaphore>
//#include <syncstream>
//#include <iostream>
//#include <execution>
//
//class CustomAlgorithm
//{
//public:
//    CustomAlgorithm(std::vector<int> new_data)
//        : data(new_data), sem(0)
//    {
//        threads.reserve(25);
//    }
//
//    std::chrono::microseconds::rep GetDuration(int k) const;
//
//    std::vector<std::vector<int>> splitVector(int k) const;
//
//    void launchThreadProcess(int threadId, std::vector<int> data);
//
//private:
//    std::vector<int> data;
//
//    std::vector<std::jthread> threads;
//    std::binary_semaphore sem;
//};



#include <thread>
#include <numeric>

template <typename Iterator, typename Predicate>
bool processSubrange(Iterator begin, Iterator end, Predicate pred) {
    return std::any_of(begin, end, pred);
}

template <typename Iterator, typename Predicate>
bool parallel_any_of(Iterator begin, Iterator end, Predicate pred, int num_threads) {
    const size_t size = std::distance(begin, end);
    const size_t chunk_size = size / num_threads;

    std::vector<std::thread> threads;
    std::vector<bool> results(num_threads);

    for (int i = 0; i < num_threads; ++i) {
        Iterator subrange_begin = begin + i * chunk_size;
        Iterator subrange_end = (i == num_threads - 1) ? end : subrange_begin + chunk_size;

        threads.emplace_back([subrange_begin, subrange_end, &pred, &results, i]() {
            results[i] = processSubrange(subrange_begin, subrange_end, pred);
            });
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return std::any_of(results.begin(), results.end(), [](bool result) { return result; });
}