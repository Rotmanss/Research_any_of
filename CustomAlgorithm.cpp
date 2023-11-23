#include "CustomAlgorithm.h"


std::vector<std::vector<int>> CustomAlgorithm::splitVector(int k) const
{
    std::vector<std::vector<int>> result;

    size_t sizeOfSubvector = data.size() / k;

    size_t remainder = data.size() % k;

    auto it = data.begin();

    for (int i = 0; i < k; ++i) {
        size_t currentSize = sizeOfSubvector + (i < remainder ? 1 : 0);

        std::vector<int> subvector(it, it + currentSize);

        it += currentSize;

        result.push_back(subvector);
    }

    return result;
}

void CustomAlgorithm::launchThreadProcess(int threadId, std::vector<int> data)
{
    std::osyncstream(std::cout) << "Thread " << threadId << " is in process." << std::endl;
    /*result = std::any_of(std::execution::seq, data.begin(), data.end(), [](int x)
        {
            return x % 2 == 0;
        });*/
}

std::chrono::microseconds::rep CustomAlgorithm::GetDuration(int k) const
{
    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<std::vector<int>> splitData = splitVector(k);

    for (int i = 0; i < k; ++i)
    {
        threads.emplace_back([&]() 
            {
                launchThreadProcess(i, splitData[i]);

            });
    }

    for (int i = 0; i < k; ++i)
    {
        sem.acquire();
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "All threads done" << std::endl;

    return duration.count();
}
