#pragma once

#include <gof_export.h>
#include <memory>
#include <vector>

namespace lgof
{
    class GOF_EXPORT Stock
    {
    public:
        void buy() const;
        void sell() const;
    };

    class GOF_EXPORT Command
    {
    public:
        virtual ~Command() = default;
        virtual void execute() const = 0;
    };

    class GOF_EXPORT BuyCommand: public Command
    {
    public:
        BuyCommand(Stock const &stock);
        void execute() const override;

    private:
        Stock const &m_stock;
    };

    class GOF_EXPORT SellCommand: public Command
    {
    public:
        SellCommand(Stock const &stock);
        void execute() const override;

    private:
        Stock const &m_stock;
    };

    class Broker
    {
    public:
        void GOF_EXPORT takeOrder(std::unique_ptr<Command> order);
        void GOF_EXPORT placeOrders();

    private:
        std::vector<std::unique_ptr<Command>> m_orders;
    };
}
