#include "check_box.h"
#include <iostream>

using namespace lgof;

void WinCheckBox::paint() const
{
    std::cout << "WinCheckBox";
}

void LinuxCheckBox::paint() const
{
    std::cout << "LinuxCheckBox";
}
