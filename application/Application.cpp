// Compiler - Microsoft Visual C++


#include <iostream>
#include <map>
#include "NoPolicy.h"
#include "WithPolicy.h"
#include "CustomAlgorithm.h"


int main()
{
    setlocale(LC_ALL, "ukrainian");

    NoPolicy np({ 1, 3, 5, 7, 2, 9 });
    std::vector<int> d = { 1, 3, 5, 7, 2, 9 };
    std::cout << "Час роботи бiблiотечного алгоритму без полiтики: " << np.GetDuration() << " мкс" << std::endl;

    WithPolicy wp({ 1, 3, 5, 7, 2, 9 });
    std::cout << "Час роботи бiблiотечного алгоритму з полiтикою seq: " << wp.GetDurationParallel() << " мкс" << std::endl;
    std::cout << "Час роботи бiблiотечного алгоритму з полiтикою par: " << wp.GetDurationSequenced() << " мкс" << std::endl;

    ParallelAlgorithm pa;
    
    std::map<int, long long> performanceMap;
    for (int i = 5; i <= 40; i += 5)
    {
        auto start_time = std::chrono::high_resolution_clock::now();
        bool result = pa.parallel_any_of(d.begin(), d.end(), [](int x)
            {
                return x % 2 == 0;
            }, i);


        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        performanceMap[i] = duration.count();
        std::cout << "Час роботи власного параелельного алгоритму з " << i << " потоків: " << duration.count() << " мкс" << std::endl;
    }

    auto minDuration = std::min_element(performanceMap.begin(), performanceMap.end(),
        [](const auto& lhs, const auto& rhs) {
            return lhs.second < rhs.second;
        });

    std::cout << "Найкраща швидкість була досягнута з : " << minDuration->first << "потоків: " << minDuration->second << " мкс" << std::endl;

    return 0;
}
