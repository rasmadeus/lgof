#include "strategy.h"
#include <iostream>

using namespace lgof::strategy;

void Add::execute()
{
    std::cout << "add";
}

void Subtract::execute()
{
    std::cout << "subtract";
}

void Context::setStrategy(std::unique_ptr<Strategy> strategy)
{
    m_strategy = std::move(strategy);
}

void Context::execute()
{
    m_strategy->execute();
}
