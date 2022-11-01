#pragma once

#include <gtest/gtest.h>
#include <string_view>

namespace lgof
{
    class AbstractFactoryClient;

    class AbstractFactoryTest: public testing::Test
    {
    protected:
        void check(AbstractFactoryClient const &client, std::string_view expectedCout) const;
    };
}
