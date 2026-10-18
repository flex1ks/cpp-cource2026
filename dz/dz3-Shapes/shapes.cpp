#include "shapes.h"
#include <cmath>





Shape::Shape(const std::string& name) : name(name) {}

Shape::~Shape() = default;
Shape::Shape(const Shape& other) = default;
Shape::Shape(Shape&& other) noexcept = default;
Shape& Shape::operator=(const Shape& other) = default;
Shape& Shape::operator=(Shape&& other) noexcept = default;

const std::string& Shape::getName() const
{
    return name;
}





Triangle::Triangle(double a, double b, double c) : Shape("Triangle"), a(a), b(b), c(c)
{
    if (a <= 0.0 or b <= 0.0 or c <= 0.0)
        throw ShapeException("Triangle sides must be positive");
    if (a + b <= c or a + c <= b or b + c <= a)
        throw ShapeException("A triangle with the given sides doesn't exist");
}

Triangle::~Triangle() = default;
Triangle::Triangle(const Triangle& other) = default;
Triangle::Triangle(Triangle&& other) noexcept = default;
Triangle& Triangle::operator=(const Triangle& other) = default;
Triangle& Triangle::operator=(Triangle&& other) noexcept = default;

double Triangle::Area() const
{
    double p = Perimeter() / 2.0;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::Perimeter() const
{
    return a + b + c;
}





Circle::Circle(double radius) : Shape("Circle"), radius(radius)
{
    if (radius <= 0.0)
        throw ShapeException("Circle radius must be positive");
}

Circle::~Circle() = default;
Circle::Circle(const Circle& other) = default;
Circle::Circle(Circle&& other) noexcept = default;
Circle& Circle::operator=(const Circle& other) = default;
Circle& Circle::operator=(Circle&& other) noexcept = default;

double Circle::Area() const
{
    return M_PI * radius * radius;
}

double Circle::Perimeter() const
{
    return 2.0 * M_PI * radius;
}





Rectangular::Rectangular(double length, double width)
    : Shape("Rectangular"), length(length), width(width)
{
    if (length <= 0.0 || width <= 0.0)
        throw ShapeException("Rectangular sides must be positive");
}

Rectangular::~Rectangular() = default;
Rectangular::Rectangular(const Rectangular& other) = default;
Rectangular::Rectangular(Rectangular&& other) noexcept = default;
Rectangular& Rectangular::operator=(const Rectangular& other) = default;
Rectangular& Rectangular::operator=(Rectangular&& other) noexcept = default;

double Rectangular::Area() const
{
    return length * width;
}

double Rectangular::Perimeter() const
{
    return 2.0 * (length + width);
}





Square::Square(double side) : Rectangular(side, side) {}

Square::~Square() = default;
Square::Square(const Square& other) = default;
Square::Square(Square&& other) noexcept = default;
Square& Square::operator=(const Square& other) = default;
Square& Square::operator=(Square&& other) noexcept = default;





namespace {
    bool almostEqual(double x, double y) { return std::abs(x - y) < 1e-6; }
}

bool operator==(const Shape& lhs, const Shape& rhs)
{
    return almostEqual(lhs.Area(), rhs.Area());
}

bool operator^(const Shape& lhs, const Shape& rhs)
{
    return almostEqual(lhs.Perimeter(), rhs.Perimeter());
}

std::ostream& operator<<(std::ostream& os, const Shape& shape)
{
    os << "Shape: " << shape.getName()
       << ", area=" << shape.Area()
       << ", perimeter=" << shape.Perimeter();
    return os;
}