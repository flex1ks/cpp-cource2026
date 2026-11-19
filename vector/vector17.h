#pragma once

#include <cstddef>

class Vector17
{
public:
    explicit Vector17(std::size_t size); // Конструктор с размером

    ~Vector17(); // Деструктор

    std::size_t size() const;

    double get(std::size_t index) const; // Чтение
    void set(std::size_t index, double value); // Запись

    double* begin(); // Указатель на первый элемент
    double* end();   // Указатель на элемент после последнего
    const double* begin() const;
    const double* end() const;

    void popBack(); // Удаление последнего элемента

private:
    std::size_t size_; // Размер
    double* data_;     // Указатель на первый элемент массива
};