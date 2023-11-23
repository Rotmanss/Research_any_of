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
    std::cout << "��� ������ �i��i�������� ��������� ��� ���i����: " << np.GetDuration() << " ���" << std::endl;

    WithPolicy wp({ 1, 3, 5, 7, 2, 9 });
    std::cout << "��� ������ �i��i�������� ��������� � ���i����� seq: " << wp.GetDurationParallel() << " ���" << std::endl;
    std::cout << "��� ������ �i��i�������� ��������� � ���i����� par: " << wp.GetDurationSequenced() << " ���" << std::endl;

    auto start_time = std::chrono::high_resolution_clock::now();
    bool result = parallel_any_of(d.begin(), d.end(), [](int x)
        {
            return x % 2 == 0;
        }, 4);


    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "��� ������ �i��i�������� ��������� � ���i����� par: " << duration.count() << " ���" << std::endl;
    return 0;
}
