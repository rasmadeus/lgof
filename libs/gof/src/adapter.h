#pragma once

#include <gof_export.h>

namespace lgof
{
    class GOF_EXPORT RoundPeg
    {
    public:
        virtual ~RoundPeg() = default;
        virtual double getRadius() const = 0;
    };

    class GOF_EXPORT RoundHole
    {
    public:
        RoundHole(double radius);
        bool fit(RoundPeg const &roundPeg) const;

    private:
        double const m_radius;
    };

    class GOF_EXPORT SquarePeg
    {
    public:
        SquarePeg(double side);
        double getSide() const;

    private:
        double const m_side;
    };

    class GOF_EXPORT SquarePegAdapter: public RoundPeg
    {
    public:
        SquarePegAdapter(SquarePeg const &squarePeg);
        double getRadius() const override;

    private:
        double const m_radius;
    };
}
