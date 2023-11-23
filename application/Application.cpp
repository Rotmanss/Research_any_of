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
    std::cout << "��� ������ �i��i�������� ��������� ��� ���i����: " << np.GetDuration() << " ���" << std::endl;

    WithPolicy wp({ 1, 3, 5, 7, 2, 9 });
    std::cout << "��� ������ �i��i�������� ��������� � ���i����� seq: " << wp.GetDurationParallel() << " ���" << std::endl;
    std::cout << "��� ������ �i��i�������� ��������� � ���i����� par: " << wp.GetDurationSequenced() << " ���" << std::endl;

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
        std::cout << "��� ������ �������� ������������� ��������� � " << i << " ������: " << duration.count() << " ���" << std::endl;
    }

    auto minDuration = std::min_element(performanceMap.begin(), performanceMap.end(),
        [](const auto& lhs, const auto& rhs) {
            return lhs.second < rhs.second;
        });

    std::cout << "�������� �������� ���� ��������� � : " << minDuration->first << "������: " << minDuration->second << " ���" << std::endl;

    return 0;
}
