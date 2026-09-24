#include "18-09.h"
#include <iostream>

my_class::my_class()
{
    field = 0;
    my_string = "hello";
}

my_class::~my_class() = default;
// my_class::~my_class() = delete;


my_class::my_class(const my_class &other)
{
    field = other.field;
    my_string = other.my_string;
}

my_class::my_class(my_class &&other)
{
    field = std::move(other.field);
    my_string = std::move(other.my_string);
}   

my_class& my_class::operator=(const my_class& other)
{
    field = other.field;
    my_string = other.my_string;
    return *this;
}

 my_class& my_class::operator=(const my_class&& other)
 {
    field = std::move(other.field);
    my_string = std::move(other.my_string);
    return *this;
 }
