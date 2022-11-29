#pragma once

#include <gof_export.h>
#include <string>

namespace lgof
{
    class GOF_EXPORT Mediator
    {
    public:
        virtual ~Mediator() = default;
        virtual void notify(std::string const &command) = 0;
    };

    class GOF_EXPORT MediatorButton
    {
    public:
        MediatorButton(Mediator &mediator);
        void click();

    private:
        Mediator &m_mediator;
    };

    class GOF_EXPORT MediatorLabel
    {
    public:
        MediatorLabel(Mediator &mediator);
        void setText(std::string const &text);

    private:
        Mediator &m_mediator;
    };

    class GOF_EXPORT MediatorDialog: public Mediator
    {
    public:
        void notify(std::string const &command) override;
        void click();

    private:
        MediatorButton m_button{ *this };
        MediatorLabel m_label{ *this };
    };
}
