#pragma once
#include <string>

struct my_struct
{
    int field; // <-- public
    int add(int x, int y);
public:
    // Доступно снаружи структуры/класса при обращении к объекту
protected:
    // Доступно внутри структуры/класса и внутри наследников
private:
    // Доступно только внутри структуры/класса
};

class my_class
{
    int field; // <-- private


public:
    my_class() : field(0), my_string("great") {}; // <-- конструктор || вызывается при создании экземпляра
    ~my_class(); // <-- деструктор || вызывается при уничтожении экземпляра
    my_class(const my_class& other); // <-- конструктор копирования || вызывается при создании экземпляра
    my_class(my_class&& other); // <-- конструктор перемещения || вызывается при создании экземпляра
    my_class& operator=(const my_class& other); // <--- копирующий оператор присваиния
    my_class& operator=(const my_class&& other); // <--- перемещающий оператор присваивания

protected:
private:
    std::string my_string;
};