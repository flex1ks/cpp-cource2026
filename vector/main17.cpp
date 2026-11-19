#include "vector17.h"

#include <algorithm>
#include <iostream>

int main()
{
    Vector17 a(5);

    a.set(0, 3.0);
    a.set(1, 1.0);
    a.set(2, 4.0);
    a.set(3, 2.0);
    a.set(4, 5.0);

    std::cout << "size = " << a.size() << '\n';

    std::cout << "before sort: ";
    for (std::size_t i = 0; i < a.size(); ++i)
        std::cout << a.get(i) << ' ';
    std::cout << '\n';

    std::sort(a.begin(), a.end());

    std::cout << "after sort: ";
    for (std::size_t i = 0; i < a.size(); ++i)
        std::cout << a.get(i) << ' ';
    std::cout << '\n';

    a.popBack();
    std::cout << "after popBack size = " << a.size() << '\n';

    a.popBack();
    a.popBack();
    a.popBack();
    a.popBack();
    std::cout << "after popping all size = " << a.size() << '\n';
    std::cout << "begin == end: " << (a.begin() == a.end()) << '\n';

    a.popBack();
    std::cout << "popBack on empty, size = " << a.size() << '\n';

    return 0;
}