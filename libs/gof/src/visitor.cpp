#include "visitor.h"
#include <iostream>

using namespace lgof::visitor;

void Logger::visit(Rect &rect)
{
    std::cout << rect.width() << rect.height();
}

void Logger::visit(Circle &circle)
{
    std::cout << circle.radius();
}

void Rect::accept(Visitor &visitor)
{
    visitor.visit(*this);
}

int Rect::width() const
{
    return 1;
}

int Rect::height() const
{
    return 1;
}
void Circle::accept(Visitor &visitor)
{
    visitor.visit(*this);
}

int Circle::radius() const
{
    return 2;
}
