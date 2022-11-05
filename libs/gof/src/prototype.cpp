#include "prototype.h"
#include <numbers>

using namespace lgof;

Circle::Circle(double radius)
    : m_radius{ radius }
    , m_area{ 2 * std::numbers::pi * radius }
{
}

std::unique_ptr<Shape> Circle::clone() const
{
    return std::make_unique<Circle>(m_radius);
}

double Circle::area() const
{
    return m_area;
}

Square::Square(double side)
    : m_side{ side }
    , m_area{ side * side }
{
}

std::unique_ptr<Shape> Square::clone() const
{
    return std::make_unique<Square>(m_side);
}

double Square::area() const
{
    return m_area;
}
