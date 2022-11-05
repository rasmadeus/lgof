#pragma once

#include <gof_export.h>
#include <memory>

namespace lgof
{
    class GOF_EXPORT Shape
    {
    public:
        virtual ~Shape() = default;
        virtual std::unique_ptr<Shape> clone() const = 0;
        virtual double area() const = 0;
    };

    class GOF_EXPORT Circle: public Shape
    {
    public:
        Circle(double radius);
        std::unique_ptr<Shape> clone() const override;
        double area() const override;

    private:
        double m_radius;
        double m_area;
    };

    class GOF_EXPORT Square: public Shape
    {
    public:
        Square(double side);
        std::unique_ptr<Shape> clone() const override;
        double area() const override;

    private:
        double m_side;
        double m_area;
    };
}
