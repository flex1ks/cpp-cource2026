#include <iostream>
#include <memory>
#include <string>
#include "vector19.h"

int main()
{
    // 1. Пустой вектор
    Vector19<int> v;
    std::cout << "size=" << v.size()
              << ", cap=" << v.capacity() << "\n";

    // 2. pushBack и рост capacity
    for (int i = 1; i <= 5; ++i) v.pushBack(i * 10);
    std::cout << "after pushBack: size=" << v.size()
              << ", cap=" << v.capacity() << "\n";

    // 3. operator[] и range-for через begin/end
    for (int* p = v.begin(); p != v.end(); ++p)
        std::cout << *p << " ";
    std::cout << "\n";

    // 4. at() с исключением
    try {
        v.at(100);
    } catch (const std::out_of_range& e) {
        std::cout << "caught: " << e.what() << "\n";
    }

    // 5. Конструктор с размером и значением
    Vector19<std::string> names(3, "Bob");
    names[1] = "Alice";
    for (std::size_t i = 0; i < names.size(); ++i)
        std::cout << names[i] << " ";
    std::cout << "\n";

    // 6. Копирование
    Vector19<int> copy = v;
    copy.popBack();
    std::cout << "v.size=" << v.size()
              << ", copy.size=" << copy.size() << "\n";

    // 7. Перемещение
    Vector19<int> moved = std::move(v);
    std::cout << "moved.size=" << moved.size()
              << ", v.size=" << v.size() << "\n";

    // 8. resize (увеличение и уменьшение)
    moved.resize(8, -1);
    for (int x : moved) std::cout << x << " ";
    std::cout << "\n";
    moved.resize(2);
    std::cout << "after shrink: size=" << moved.size() << "\n";

    // 9. reserve — capacity растёт, size не меняется
    moved.reserve(100);
    std::cout << "after reserve: size=" << moved.size()
              << ", cap=" << moved.capacity() << "\n";

    // 10. popBack на пустом
    Vector19<int> e;
    try { e.popBack(); }
    catch (const std::out_of_range& ex) {
        std::cout << "caught: " << ex.what() << "\n";
    }

    return 0;
}