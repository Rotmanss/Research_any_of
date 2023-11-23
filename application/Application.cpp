// Compiler - Microsoft Visual C++


#include <iostream>
#include "NoPolicy.h"
#include "WithPolicy.h"


int main()
{
    setlocale(LC_ALL, "ukrainian");

    NoPolicy np({ 1, 3, 5, 7, 2, 9 });
    std::cout << "��� ������ �i��i�������� ��������� ��� ���i����: " << np.GetDuration() << " ���" << std::endl;

    WithPolicy wp({ 1, 3, 5, 7, 2, 9 });
    std::cout << "��� ������ �i��i�������� ��������� � ���i����� seq: " << wp.GetDurationParallel() << " ���" << std::endl;
    std::cout << "��� ������ �i��i�������� ��������� � ���i����� par: " << wp.GetDurationSequenced() << " ���" << std::endl;

    

    return 0;
}
