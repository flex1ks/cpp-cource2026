#include "shape-24-09.h"

double Rectangular::calculatePerimeter()
{
    return (length_ + width_) * 2.0;
}

double Rectangular::calculatePerimeter()
{
    return(length_ * width_)
}
Rectangular::Rectangular(double width, double length)
    : Shape("rectangular"), width_(width), length_(length) {} //список инициализаций

const std::string &Shape::getName()
{
    return name_;
}

Shape::Shape(std::string &&name) : name_(std::move(name)) {}

double Circle::calculatePerimeter()
{
    return radius_ * 2.0 * 3.1415926535;
}

double Circle::calculatePerimeter()
{
    return 3.1415926535 * radius_ * radius_;
}

Circle::Circle(double radius) : Shape("circle"), radius_(radius) {}