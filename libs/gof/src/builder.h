#pragma once

#include <gof_export.h>
#include <string>

namespace lgof
{
    enum class GOF_EXPORT CupSize
    {
        Small,
        Big,
    };

    class GOF_EXPORT Coffee
    {
    public:
        void addSugar();
        void setCupSize(CupSize cupSize);

        int sugar() const;
        CupSize cupSize() const;

    private:
        int m_sugar{ 0 };
        CupSize m_cupSize{ CupSize::Small };
    };

    class GOF_EXPORT CoffeeBuilder
    {
    public:
        virtual ~CoffeeBuilder() = default;
        virtual void addSugar() = 0;
        virtual void setCupSize(CupSize cupSize) = 0;
    };

    class GOF_EXPORT CupOfCoffeeBuilder: public CoffeeBuilder
    {
    public:
        void addSugar() override;
        void setCupSize(CupSize cupSize) override;
        Coffee const &get() const;

    private:
        Coffee m_coffee;
    };

    class GOF_EXPORT CoffeeAdvertisementBuilder: public CoffeeBuilder
    {
    public:
        void addSugar() override;
        void setCupSize(CupSize cupSize) override;
        std::string get() const;

    private:
        Coffee m_coffee;
    };

    class GOF_EXPORT Barista
    {
    public:
        Coffee makeAmericano() const;
        std::string makeAmericanoAdvertisement() const;
        Coffee makeCapuchino() const;
        std::string makeCapuchinoAdvertisement() const;
    };
}
