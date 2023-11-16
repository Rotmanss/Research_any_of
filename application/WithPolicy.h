#pragma once

#include <algorithm>
#include <vector>
#include <chrono>


class WithPolicy
{
public:
    WithPolicy(std::vector<int> new_data)
        : data(new_data)
    {
    }

    std::chrono::microseconds::rep GetDurationSequenced() const;
    std::chrono::microseconds::rep GetDurationParallel() const;

private:
    std::vector<int> data;
};