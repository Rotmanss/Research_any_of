#include "WithPolicy.h"
#include <execution>


std::chrono::microseconds::rep WithPolicy::GetDurationSequenced() const
{
    auto start_time = std::chrono::high_resolution_clock::now();

    bool result = std::any_of(std::execution::seq, data.begin(), data.end(), [](int x)
    {
        return x % 2 == 0;
    });

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    return duration.count();
}


std::chrono::microseconds::rep WithPolicy::GetDurationParallel() const
{
    auto start_time = std::chrono::high_resolution_clock::now();
    bool result_par = std::any_of(std::execution::par, data.begin(), data.end(), [](int x)
    {
        return x % 2 == 0;
    });

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    return duration.count();
}
