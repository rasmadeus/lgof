#include "adapter.h"

using namespace lgof;

RoundHole::RoundHole(double radius)
    : m_radius{ radius }
{
}

bool RoundHole::fit(RoundPeg const &roundPeg) const
{
    return m_radius >= roundPeg.getRadius();
}

SquarePeg::SquarePeg(double side)
    : m_side{ side }
{
}

double SquarePeg::getSide() const
{
    return m_side;
}

SquarePegAdapter::SquarePegAdapter(SquarePeg const &squarePeg)
    : m_radius{ squarePeg.getSide() / 2.0 }
{
}

double SquarePegAdapter::getRadius() const
{
    return m_radius;
}
