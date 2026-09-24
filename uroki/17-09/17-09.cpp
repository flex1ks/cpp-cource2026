#include <iostream>

const int N = 5;
static const int M = 6;
constexpr int K = 7;
constexpr int function()
{
    return K;
}

namespace my_space
{
    int r = 1;
    int function() 
    {
        return 0;
    }

    namespace other_space
    {
        namespace inner_space
        {
            int a = 4;
        }
    }
}

using namespace my_space::other_space::inner_space;

int main()
{
    my_space::r;
    std::cout << "" << std::endl;

    if(my_space::r = 4)
    {
        int t = 1;
    }
    else if (4 != 3)
    {
        int t = 2;
    }
    else
    {
        int y = 2;
    }

    // Начало main тут
    int x = 3;
    int y = 4;
    

    // Работа с кучей
    int& ref_int = x; // обращение к значению внутри ячейки памяти для переменной х по адресу
    int* pointer_int = &x; // адрес перемнной x в памяти
    std::cout << x << std::endl;
    std::cout << ref_int << std::endl;

    return 0;
}


