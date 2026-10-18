#pragma once

#include <string>

#include <iostream>

#include <exception>


class ShapeException : public std::exception
{
    std::string message;
public:
    ShapeException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};



class Shape
{
public:
    Shape(const std::string& name);
    virtual ~Shape();
    Shape(const Shape& other);
    Shape(Shape&& other) noexcept;
    Shape& operator=(const Shape& other);
    Shape& operator=(Shape&& other) noexcept;

    const std::string& getName() const;

    virtual double Area() const = 0;
    virtual double Perimeter() const = 0;

private:
    std::string name;
};



class Triangle : public Shape
{
public:
    Triangle(double a, double b, double c);
    ~Triangle() override;
    Triangle(const Triangle& triangle);
    Triangle(Triangle&& triangle) noexcept;
    Triangle& operator=(const Triangle& triangle);
    Triangle& operator=(Triangle&& triangle) noexcept;

    double Area() const override;
    double Perimeter() const override;

private:
    double a, b, c;
};



class Circle : public Shape
{
public:
    Circle(double radius);
    ~Circle() override;
    Circle(const Circle& circle);
    Circle(Circle&& circle) noexcept;
    Circle& operator=(const Circle& circle);
    Circle& operator=(Circle&& circle) noexcept;

    double Area() const override;
    double Perimeter() const override;

private:
    double radius;
};



class Rectangular : public Shape
{
public:
    Rectangular(double length, double width);
    ~Rectangular() override;
    Rectangular(const Rectangular& rectangular);
    Rectangular(Rectangular&& rectangular) noexcept;
    Rectangular& operator=(const Rectangular& rectangular);
    Rectangular& operator=(Rectangular&& rectangular) noexcept;

    double Area() const override;
    double Perimeter() const override;

protected:
    double length, width;
};



class Square : public Rectangular
{
public:
    Square(double side);
    ~Square() override;
    Square(const Square& square);
    Square(Square&& square) noexcept;
    Square& operator=(const Square& square);
    Square& operator=(Square&& square) noexcept;
};



bool operator==(const Shape& lhs, const Shape& rhs);

bool operator^(const Shape& lhs, const Shape& rhs);

std::ostream& operator<<(std::ostream& os, const Shape& shape);