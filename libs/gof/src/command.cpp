#include "command.h"
#include <iostream>

using namespace lgof;

void Stock::buy() const
{
    std::cout << "buy";
}

void Stock::sell() const
{
    std::cout << "sell";
}

BuyCommand::BuyCommand(Stock const &stock)
    : m_stock{ stock }
{
}

void BuyCommand::execute() const
{
    m_stock.buy();
}

SellCommand::SellCommand(Stock const &stock)
    : m_stock{ stock }
{
}

void SellCommand::execute() const
{
    m_stock.sell();
}

void GOF_EXPORT Broker::takeOrder(std::unique_ptr<Command> order)
{
    m_orders.emplace_back(std::move(order));
}

void GOF_EXPORT Broker::placeOrders()
{
    for (auto const &order : m_orders)
    {
        order->execute();
    }

    m_orders.clear();
}
