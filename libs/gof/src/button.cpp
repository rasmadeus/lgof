#include "button.h"
#include <iostream>

using namespace lgof;

void WinButton::paint() const
{
    std::cout << "WinButtonPaint";
}

void WinButton::click() const
{
    std::cout << "WinButtonClick";
}

void LinuxButton::paint() const
{
    std::cout << "LinuxButtonPaint";
}

void LinuxButton::click() const
{
    std::cout << "LinuxButtonClick";
}
