#include "check_box.h"
#include <iostream>

using namespace lgof;

void WinCheckBox::paint() const
{
    std::cout << "WinCheckBoxPaint";
}

void LinuxCheckBox::paint() const
{
    std::cout << "LinuxCheckBoxPaint";
}
