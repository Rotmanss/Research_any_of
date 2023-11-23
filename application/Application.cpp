// Compiler - Microsoft Visual C++


#include <iostream>
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

    auto start_time = std::chrono::high_resolution_clock::now();
    bool result = parallel_any_of(d.begin(), d.end(), [](int x)
        {
            return x % 2 == 0;
        }, 4);


    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "Час роботи бiблiотечного алгоритму з полiтикою par: " << duration.count() << " мкс" << std::endl;
    return 0;
}
