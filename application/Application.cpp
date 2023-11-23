// Compiler - Microsoft Visual C++


#include <iostream>
#include "NoPolicy.h"
#include "WithPolicy.h"


int main()
{
    setlocale(LC_ALL, "ukrainian");

    NoPolicy np({ 1, 3, 5, 7, 2, 9 });
    std::cout << "Час роботи бiблiотечного алгоритму без полiтики: " << np.GetDuration() << " мкс" << std::endl;

    WithPolicy wp({ 1, 3, 5, 7, 2, 9 });
    std::cout << "Час роботи бiблiотечного алгоритму з полiтикою seq: " << wp.GetDurationParallel() << " мкс" << std::endl;
    std::cout << "Час роботи бiблiотечного алгоритму з полiтикою par: " << wp.GetDurationSequenced() << " мкс" << std::endl;

    

    return 0;
}
