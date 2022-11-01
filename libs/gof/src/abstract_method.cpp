#include "abstract_method.h"

using namespace lgof;

void Display::render() const
{
    auto const button = makeButton();
    button->click();
    button->paint();
}

std::unique_ptr<Button> WinDisplay::makeButton() const
{
    return std::make_unique<WinButton>();
}

std::unique_ptr<Button> LinuxDisplay::makeButton() const
{
    return std::make_unique<LinuxButton>();
}
