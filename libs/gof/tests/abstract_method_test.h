#pragma once

#include <gtest/gtest.h>
#include <string_view>

namespace lgof
{
    class Display;

    class AbstractMethodTest: public testing::Test
    {
    protected:
        void check(Display const &display, std::string_view expectedCout) const;
    };
}
