#include "vector18.h"

#include <algorithm>
#include <iostream>
#include <utility>

int main()
{
    // Конструктор с размером и значением
    Vector18 a(5, 0.0);
    a[0] = 3.0;
    a[1] = 1.0;
    a[2] = 4.0;
    a[3] = 2.0;
    a[4] = 5.0;

    // sort через begin()/end()
    std::sort(a.begin(), a.end());

    std::cout << "a: ";
    for (std::size_t i = 0; i < a.size(); ++i)
        std::cout << a[i] << ' ';
    std::cout << '\n';

    // Копирование
    Vector18 b = a;
    b[0] = 99.0;
    std::cout << "a[0]=" << a[0] << ", b[0]=" << b[0] << '\n';

    // Перемещение
    Vector18 c = std::move(a);
    std::cout << "c.size()=" << c.size() << ", a.size()=" << a.size() << '\n';

    // popBack
    c.popBack();
    std::cout << "c.size() after popBack=" << c.size() << '\n';

    // popBack на пустом бросает исключение
    try
    {
        Vector18 empty;
        empty.popBack();
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "caught: " << e.what() << '\n';
    }

    return 0;
}