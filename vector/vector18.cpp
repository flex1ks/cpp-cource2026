#include "vector18.h"

#include <stdexcept>
#include <utility>

Vector18::Vector18()
    : size_(0), data_(nullptr) {}

Vector18::Vector18(std::size_t size)
    : size_(size), data_(new double[size])
{
    for (std::size_t i = 0; i < size_; ++i)
    {
        data_[i] = 0.0;
    }
}

Vector18::Vector18(std::size_t size, double value)
    : size_(size), data_(new double[size])
{
    for (std::size_t i = 0; i < size_; ++i)
    {
        data_[i] = value;
    }
}

Vector18::Vector18(std::initializer_list<double> values)
    : size_(values.size()), data_(new double[values.size()])
{
    for (std::size_t i = 0; i < size_; ++i)
    {
        data_[i] = *(values.begin() + i);
    }
}

Vector18::~Vector18()
{
    delete[] data_;
}

Vector18::Vector18(const Vector18& other)
    : size_(other.size_), data_(new double[other.size_])
{
    for (std::size_t i = 0; i < size_; ++i)
    {
        data_[i] = other.data_[i];
    }
}

Vector18::Vector18(Vector18&& other) noexcept
    : size_(other.size_), data_(other.data_)
{
    other.size_ = 0;
    other.data_ = nullptr;
}

Vector18& Vector18::operator=(const Vector18& other)
{
    if (this != &other) // Надо проверить на присвоение x=x
    {
        Vector18 tmp(other); // Временный объект
        std::swap(size_, tmp.size_);
        std::swap(data_, tmp.data_);
    }
    return *this;
}

Vector18& Vector18::operator=(Vector18&& other) noexcept
{
    if (this != &other) // Надо проверить на присвоение x=x
    {
        delete[] data_; // Очищаем текущие данные
        size_ = other.size_;
        data_ = other.data_; // Забираем данные other
        other.size_ = 0;
        other.data_ = nullptr;
    }
    return *this;
}

std::size_t Vector18::size() const
{
    return size_;
}

double& Vector18::operator[](std::size_t index)
{
    return data_[index];
}

const double& Vector18::operator[](std::size_t index) const
{
    return data_[index];
}

double* Vector18::begin()
{
    return data_;
}

double* Vector18::end()
{
    return data_ + size_;
}

const double* Vector18::begin() const
{
    return data_;
}

const double* Vector18::end() const
{
    return data_ + size_;
}

void Vector18::popBack()
{
    if (size_ == 0)
    {
        throw std::out_of_range("popBack() called on empty array");
    }
    --size_;
}