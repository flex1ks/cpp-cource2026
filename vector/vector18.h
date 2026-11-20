#pragma once

#include <cstddef>
#include <initializer_list>

class Vector18
{
public:
    Vector18(); // Конструктор по умолчанию
    explicit Vector18(std::size_t size); // Конструктор с размером
    Vector18(std::size_t size, double value); // Конструктор с размером и значением
    Vector18(std::initializer_list<double> values);

    ~Vector18(); // Деструктор

    Vector18(const Vector18& other); // Копирующий конструктор
    Vector18(Vector18&& other) noexcept; // Перемещающий конструктор
    Vector18& operator=(const Vector18& other); // Копирующее присваивание
    Vector18& operator=(Vector18&& other) noexcept; // Перемещающее присваивание

    std::size_t size() const;

    double& operator[](std::size_t index); // Доступ с записью
    const double& operator[](std::size_t index) const; // Доступ только на чтение

    double* begin();
    double* end();
    const double* begin() const;
    const double* end() const;

    void popBack();

private:
    std::size_t size_;
    double* data_;
};