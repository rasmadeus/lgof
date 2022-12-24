#pragma once

#include <gof_export.h>
#include <memory>

namespace lgof::strategy
{
    class GOF_EXPORT Strategy
    {
    public:
        virtual ~Strategy() = default;
        virtual void execute() = 0;
    };

    class GOF_EXPORT Add: public Strategy
    {
    public:
        void execute() override;
    };

    class GOF_EXPORT Subtract: public Strategy
    {
    public:
        void execute() override;
    };

    class Context
    {
    public:
        void GOF_EXPORT setStrategy(std::unique_ptr<Strategy> strategy);
        void GOF_EXPORT execute();

    private:
        std::unique_ptr<Strategy> m_strategy = std::make_unique<Add>();
    };
}
