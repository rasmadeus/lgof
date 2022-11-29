#include "mediator.h"
#include <iostream>

using namespace lgof;

MediatorButton::MediatorButton(Mediator &mediator)
    : m_mediator{ mediator }
{
}

void MediatorButton::click()
{
    m_mediator.notify("click");
}

MediatorLabel::MediatorLabel(Mediator &mediator)
    : m_mediator{ mediator }
{
}

void MediatorLabel::setText(std::string const &text)
{
    std::cout << text;
}

void MediatorDialog::notify(std::string const &command)
{
    if ("click" == command)
    {
        m_label.setText("click");
    }
}

void MediatorDialog::click()
{
    m_button.click();
}
