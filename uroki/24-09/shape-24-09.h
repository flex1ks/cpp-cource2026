#pragma once 

#include <string>

class Shape
{
private:
protected:
    const std::string name_;
public:
    const std::string& getName();
    virtual double calculatePerimeter();
    double calculateSquare();

    Shape() = default;
    Shape(std::string&& name);
    virtual ~Shape() = default;
};

class Rectangular : public Shape
{
private:
    double width_;
    double length_;
public:
    virtual double calculatePerimeter() override;

    Rectangular(double width, double length);
    virtual ~Rectangular() = default;
};  

class Circle : public Shape
{
private:
    double radius_;
public:
    virtual double calculatePerimeter() override;
};