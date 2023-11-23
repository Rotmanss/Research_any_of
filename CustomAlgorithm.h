#pragma once

#include <algorithm>
#include <vector>
#include <chrono>
#include <thread>
#include <semaphore>
#include <syncstream>
#include <iostream>
#include <execution>

class CustomAlgorithm
{
public:
    CustomAlgorithm(std::vector<int> new_data)
        : data(new_data), sem(0), result(false)
    {
        threads.reserve(25);
    }

    std::chrono::microseconds::rep GetDuration(int k) const;

    std::vector<std::vector<int>> splitVector(int k) const;

    void launchThreadProcess(int threadId, std::vector<int> data);

private:
    std::vector<int> data;

    std::vector<std::jthread> threads;
    std::binary_semaphore sem;
};