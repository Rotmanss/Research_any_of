#include "CustomAlgorithm.h"
#include <thread>
#include <algorithm>

bool ParallelAlgorithm::processSubrange(std::vector<int>::iterator begin, std::vector<int>::iterator end, bool (*pred)(int x)) {
    return std::any_of(begin, end, pred);
}

bool ParallelAlgorithm::parallel_any_of(std::vector<int>& data, bool (*pred)(int x), int num_threads) {
    const size_t size = data.size();
    const size_t chunk_size = size / num_threads;

    std::vector<std::thread> threads(num_threads);
    std::vector<bool> results(num_threads);

    for (int i = 0; i < num_threads; ++i) {
        auto subrange_begin = data.begin() + i * chunk_size;
        auto subrange_end = (i == num_threads - 1) ? data.end() : subrange_begin + chunk_size;

        threads[i] = std::thread([this, subrange_begin, subrange_end, &pred, &results, i]() {
            results[i] = processSubrange(subrange_begin, subrange_end, pred);
            });
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return std::any_of(results.begin(), results.end(), [](bool result) { return result; });
}
