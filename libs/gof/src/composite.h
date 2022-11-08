#pragma once

#include <gof_export.h>
#include <memory>
#include <vector>

namespace lgof
{
    class GOF_EXPORT Graphic
    {
    public:
        virtual ~Graphic() = default;
        virtual void draw() const = 0;
    };

    class CompoundGraphic: public Graphic
    {
    public:
        void GOF_EXPORT add(std::unique_ptr<Graphic> graphic);
        void GOF_EXPORT draw() const override;

    private:
        std::vector<std::unique_ptr<Graphic>> m_compoundGraphic;
    };

    class GOF_EXPORT Rectangle: public Graphic
    {
    public:
        void draw() const override;
    };
}
