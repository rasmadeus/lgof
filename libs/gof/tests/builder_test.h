#pragma once

#include <builder.h>
#include <gtest/gtest.h>
#include <string_view>

namespace lgof
{
    class BuilderTest: public testing::Test
    {
    protected:
        void checkCoffee(CupSize expectedCupSize, int expectedSugar, Coffee const &coffee) const;
    };
}
