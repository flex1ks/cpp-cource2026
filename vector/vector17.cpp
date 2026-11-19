#include "vector17.h"

Vector17::Vector17(std::size_t size)
    : size_(size), data_(new double[size])
{
    for (std::size_t i = 0; i < size_; ++i)
    {
        data_[i] = 0.0;
    }
}

Vector17::~Vector17()
{
    delete[] data_;
}

std::size_t Vector17::size() const
{
    return size_;
}

double Vector17::get(std::size_t index) const
{
    return data_[index];
}

void Vector17::set(std::size_t index, double value)
{
    data_[index] = value;
}

double* Vector17::begin()
{
    return data_;
}

double* Vector17::end()
{
    return data_ + size_;
}

const double* Vector17::begin() const
{
    return data_;
}

const double* Vector17::end() const
{
    return data_ + size_;
}

void Vector17::popBack()
{
    if (size_ > 0)
    {
        --size_;
    }
}