#pragma once

#include <cstddef>
#include <memory>
#include <stdexcept>
#include <utility>

template<typename T, typename A = std::allocator<T>>
class Vector19
{
public:
    Vector19();                                          // Конструктор по умолчанию
    explicit Vector19(std::size_t capacity);             // Конструктор с емкостью
    Vector19(std::size_t size, const T& value);          // Конструктор с размером и значением

    ~Vector19();                                         // Деструктор

    Vector19(const Vector19& other);                     // Копирующий конструктор
    Vector19(Vector19&& other) noexcept;                 // Перемещающий конструктор
    Vector19& operator=(const Vector19& other);          // Копирующее присваивание
    Vector19& operator=(Vector19&& other) noexcept;      // Перемещающее присваивание

    std::size_t size() const;
    std::size_t capacity() const;

    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;

    T& at(std::size_t index);                            // С проверкой диапазона
    const T& at(std::size_t index) const;

    void reserve(std::size_t newCapacity);
    void resize(std::size_t newSize, const T& value = T());
    void pushBack(const T& value);
    void popBack();

    T* begin();
    T* end();
    const T* begin() const;
    const T* end() const;

private:
    A alloc_;
    std::size_t size_;
    std::size_t capacity_;
    T* data_;
};

template<typename T, typename A>
inline Vector19<T, A>::Vector19()
    : alloc_(), size_(0), capacity_(0), data_(nullptr)
{
}

template<typename T, typename A>
inline Vector19<T, A>::Vector19(std::size_t capacity)
    : alloc_(), size_(0), capacity_(capacity)
{
    data_ = capacity ? alloc_.allocate(capacity) : nullptr;
}

template<typename T, typename A>
inline Vector19<T, A>::Vector19(std::size_t size, const T& value)
    : alloc_(), size_(size), capacity_(size)
{
    data_ = size ? alloc_.allocate(size) : nullptr;
    for (std::size_t i = 0; i < size_; ++i)
    {
        alloc_.construct(&data_[i], value);
    }
}

template<typename T, typename A>
inline Vector19<T, A>::~Vector19()
{
    for (std::size_t i = 0; i < size_; ++i)
    {
        alloc_.destroy(&data_[i]);
    }
    if (data_)
    {
        alloc_.deallocate(data_, capacity_);
    }
}

template<typename T, typename A>
inline Vector19<T, A>::Vector19(const Vector19& other)
    : alloc_(other.alloc_),
      size_(other.size_),
      capacity_(other.size_),
      data_(nullptr)
{
    if (capacity_)
    {
        data_ = alloc_.allocate(capacity_);
    }
    for (std::size_t i = 0; i < size_; ++i)
    {
        alloc_.construct(&data_[i], other.data_[i]);
    }
}

template<typename T, typename A>
inline Vector19<T, A>::Vector19(Vector19&& other) noexcept
    : alloc_(std::move(other.alloc_)),
      size_(other.size_), capacity_(other.capacity_), data_(other.data_)
{
    other.size_ = 0;
    other.capacity_ = 0;
    other.data_ = nullptr;
}

template<typename T, typename A>
inline Vector19<T, A>& Vector19<T, A>::operator=(const Vector19& other)
{
    if (this != &other)
    {
        Vector19 tmp(other);
        std::swap(alloc_, tmp.alloc_);
        std::swap(size_, tmp.size_);
        std::swap(capacity_, tmp.capacity_);
        std::swap(data_, tmp.data_);
    }
    return *this;
}

template<typename T, typename A>
inline Vector19<T, A>& Vector19<T, A>::operator=(Vector19&& other) noexcept
{
    if (this != &other)
    {
        for (std::size_t i = 0; i < size_; ++i)
        {
            alloc_.destroy(&data_[i]);
        }
        if (data_)
        {
            alloc_.deallocate(data_, capacity_);
        }

        alloc_ = std::move(other.alloc_);
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = other.data_;

        other.size_ = 0;
        other.capacity_ = 0;
        other.data_ = nullptr;
    }
    return *this;
}

template <typename T, typename A>
inline std::size_t Vector19<T, A>::size() const
{
    return size_;
}

template <typename T, typename A>
inline std::size_t Vector19<T, A>::capacity() const
{
    return capacity_;
}

template<typename T, typename A>
inline T& Vector19<T, A>::operator[](std::size_t index)
{
    return data_[index];
}

template<typename T, typename A>
inline const T& Vector19<T, A>::operator[](std::size_t index) const
{
    return data_[index];
}

template<typename T, typename A>
inline T& Vector19<T, A>::at(std::size_t index)
{
    if (size_ <= index)
    {
        throw std::out_of_range("index is out of range");
    }
    return data_[index];
}

template<typename T, typename A>
inline const T& Vector19<T, A>::at(std::size_t index) const
{
    if (size_ <= index)
    {
        throw std::out_of_range("index is out of range");
    }
    return data_[index];
}

template<typename T, typename A>
inline void Vector19<T, A>::reserve(std::size_t newCapacity)
{
    if (newCapacity <= capacity_)
    {
        return;
    }

    T* newData = alloc_.allocate(newCapacity);
    for (std::size_t i = 0; i < size_; ++i)
    {
        alloc_.construct(&newData[i], std::move_if_noexcept(data_[i]));
    }
    for (std::size_t i = 0; i < size_; ++i)
    {
        alloc_.destroy(&data_[i]);
    }
    if (data_)
    {
        alloc_.deallocate(data_, capacity_);
    }

    data_ = newData;
    capacity_ = newCapacity;
}

template <typename T, typename A>
inline void Vector19<T, A>::resize(std::size_t newSize, const T& value)
{
    if (newSize > size_)
    {
        reserve(newSize);
        for (std::size_t i = size_; i < newSize; ++i)
        {
            alloc_.construct(&data_[i], value);
        }
    }
    else if (newSize < size_)
    {
        for (std::size_t i = newSize; i < size_; ++i)
        {
            alloc_.destroy(&data_[i]);
        }
    }
    size_ = newSize;
}

template<typename T, typename A>
inline void Vector19<T, A>::pushBack(const T& value)
{
    if (size_ == capacity_)
    {
        std::size_t newCapacity = capacity_ ? capacity_ * 2 : 1;
        reserve(newCapacity);
    }
    alloc_.construct(&data_[size_], value);
    ++size_;
}

template<typename T, typename A>
inline void Vector19<T, A>::popBack()
{
    if (size_ == 0)
    {
        throw std::out_of_range("popBack() called on empty array");
    }
    --size_;
    alloc_.destroy(&data_[size_]);
}

template<typename T, typename A>
inline T* Vector19<T, A>::begin()
{
    return data_;
}

template<typename T, typename A>
inline T* Vector19<T, A>::end()
{
    return data_ + size_;
}

template<typename T, typename A>
inline const T* Vector19<T, A>::begin() const
{
    return data_;
}

template<typename T, typename A>
inline const T* Vector19<T, A>::end() const
{
    return data_ + size_;
}