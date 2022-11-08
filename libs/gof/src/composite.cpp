#include "composite.h"
#include <iostream>

using namespace lgof;

void CompoundGraphic::add(std::unique_ptr<Graphic> graphic)
{
    m_compoundGraphic.emplace_back(std::move(graphic));
}

void CompoundGraphic::draw() const
{
    for (auto &graphic : m_compoundGraphic)
    {
        graphic->draw();
    }
}

void Rectangle::draw() const
{
    std::cout << "DrawRectangle";
}
