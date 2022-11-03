#include "builder.h"
#include <cassert>
#include <format>
#include <unordered_map>

using namespace lgof;

void Coffee::addSugar()
{
    m_sugar += 1;
}

void Coffee::setCupSize(CupSize cupSize)
{
    m_cupSize = cupSize;
}

int Coffee::sugar() const
{
    return m_sugar;
}

CupSize Coffee::cupSize() const
{
    return m_cupSize;
}

void CupOfCoffeeBuilder::addSugar()
{
    m_coffee.addSugar();
}

void CupOfCoffeeBuilder::setCupSize(CupSize cupSize)
{
    m_coffee.setCupSize(cupSize);
}

Coffee const &CupOfCoffeeBuilder::get() const
{
    return m_coffee;
}

void CoffeeAdvertisementBuilder::addSugar()
{
    m_coffee.addSugar();
}

void CoffeeAdvertisementBuilder::setCupSize(CupSize cupSize)
{
    m_coffee.setCupSize(cupSize);
}

std::string CoffeeAdvertisementBuilder::get() const
{
    static auto const sizeDescriptions = std::unordered_map<CupSize, std::string>{
        { CupSize::Big, "big" },
        { CupSize::Small, "small" },
    };

    auto const sizeDescription = sizeDescriptions.find(m_coffee.cupSize());
    assert(sizeDescription != sizeDescriptions.cend());

    return std::format("Size: {}; Sugar: {}", sizeDescription->second, m_coffee.sugar());
}

Coffee Barista::makeAmericano() const
{
    auto builder = CupOfCoffeeBuilder{};
    builder.setCupSize(CupSize::Big);
    builder.addSugar();
    builder.addSugar();
    builder.addSugar();
    return builder.get();
}

std::string Barista::makeAmericanoAdvertisement() const
{
    auto builder = CoffeeAdvertisementBuilder{};
    builder.setCupSize(CupSize::Big);
    builder.addSugar();
    builder.addSugar();
    builder.addSugar();
    return builder.get();
}

Coffee Barista::makeCapuchino() const
{
    auto builder = CupOfCoffeeBuilder{};
    builder.setCupSize(CupSize::Small);
    builder.addSugar();
    return builder.get();
}

std::string Barista::makeCapuchinoAdvertisement() const
{
    auto builder = CoffeeAdvertisementBuilder{};
    builder.setCupSize(CupSize::Small);
    builder.addSugar();
    return builder.get();
}
