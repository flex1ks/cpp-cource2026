#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include "vector19.h"

struct Person 
    {
    private:
        std::string name_;
        unsigned int age_;

    public:
        Person(const std::string name, int age) :name_(name), age_(age) {}

        std::string name() const {return name_;}
        int age() const {return age_;}
    };

std::ostream& operator<<(std::ostream& os, const Person& vp)
{
    return os << "(" << vp.name() << ", " << vp.age() << ") ";
}

int main()
{
    // 0. Задание Person
    std::cout << "======= Task Person =======\n";
    Vector19<Person> vp
    {
        {"Alex",  17}, {"Boris", 19}, {"Clara", 16},
        {"Dimon", 17}, {"Artyom",23}, {"Ilya",  27},
        {"Lev",   18}, {"Sergey",16}, {"Ilnur", 36}
    };
    std::cout << "vp before sorting:         ";
    for (std::size_t i = 0; i < vp.size(); ++i)
    {
        std::cout << vp[i];
    }
    std::cout << std::endl << std::endl;

        // 1) По убыванию возраста
    std::sort(vp.begin(), vp.end(), [](const Person& a, const Person& b) {return a.age() > b.age();});   
    std::cout << "vp after first sorting:    ";
    for (std::size_t i = 0; i < vp.size(); ++i)
    {
        std::cout << vp[i];
    }
    std::cout << std::endl << std::endl;
        // 2) По возрастанию возраста с сортировкой по алфавиту при совпадении
    std::sort(vp.begin(), vp.end(), [](const Person& a, const Person& b) {return a.age() != b.age() ? a.age() < b.age() : a.name() < b.name();});
    std::cout << "vp after second sorting:   ";
    for (std::size_t i = 0; i < vp.size(); ++i)
    {
        std::cout << vp[i];
    }
    std::cout << std::endl;
    std::cout << "===========================";
    std::cout << std::endl;

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