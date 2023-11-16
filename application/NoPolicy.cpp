#include "NoPolicy.h"


std::chrono::microseconds::rep NoPolicy::GetDuration() const
{
    auto start_time = std::chrono::high_resolution_clock::now();

    bool result = std::any_of(data.begin(), data.end(), [](int x)
    {
        return x % 2 == 0;
    });

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    return duration.count();
}
