#pragma once

#include <gof_export.h>
#include <memory>

namespace lgof::visitor
{
    class GOF_EXPORT Rect;
    class GOF_EXPORT Circle;

    class GOF_EXPORT Visitor
    {
    public:
        virtual ~Visitor() = default;
        virtual void visit(Rect &rect) = 0;
        virtual void visit(Circle &circle) = 0;
    };

    class GOF_EXPORT Logger: public Visitor
    {
    public:
        void visit(Rect &rect) override;
        void visit(Circle &circle) override;
    };

    class GOF_EXPORT Visitable
    {
    public:
        virtual ~Visitable() = default;
        virtual void accept(Visitor &visitor) = 0;
    };

    class GOF_EXPORT Rect: public Visitable
    {
    public:
        void accept(Visitor &visitor) override;
        int width() const;
        int height() const;
    };

    class GOF_EXPORT Circle: public Visitable
    {
    public:
        void accept(Visitor &visitor) override;
        int radius() const;
    };
}
