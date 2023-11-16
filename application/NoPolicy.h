#pragma once

#include <algorithm>
#include <vector>
#include <chrono>


class NoPolicy
{
public:
    NoPolicy(std::vector<int> new_data)
        : data(new_data)
    {
    }

    std::chrono::microseconds::rep GetDuration() const;

private:
    std::vector<int> data;
};