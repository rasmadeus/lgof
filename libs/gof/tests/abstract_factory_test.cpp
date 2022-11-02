#include "abstract_factory_test.h"
#include "std_cout_redirect.h"
#include <abstract_factory.h>

using namespace lgof;

void AbstractFactoryTest::check(AbstractFactoryClient const &client, std::string_view expectedCout) const
{
    auto const stdCoutRedirect = StdCoutRedirect{};
    client.paint();
    EXPECT_EQ(expectedCout, stdCoutRedirect.string());
}

TEST_F(AbstractFactoryTest, TestWinConfig)
{
    auto const factory = WinFactory{};
    auto const client = AbstractFactoryClient{ factory };
    check(client, "WinButtonPaintWinCheckBoxPaint");
}

TEST_F(AbstractFactoryTest, TestLinuxConfig)
{
    auto const factory = LinuxFactory{};
    auto const client = AbstractFactoryClient{ factory };
    check(client, "LinuxButtonPaintLinuxCheckBoxPaint");
}
