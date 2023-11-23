#include "CustomAlgorithm.h"

template <typename Iterator, typename Predicate>
bool ParallelAlgorithm::processSubrange(Iterator begin, Iterator end, Predicate pred) {
    return std::any_of(begin, end, pred);
}

template <typename Iterator, typename Predicate>
bool ParallelAlgorithm::parallel_any_of(Iterator begin, Iterator end, Predicate pred, int num_threads) {
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