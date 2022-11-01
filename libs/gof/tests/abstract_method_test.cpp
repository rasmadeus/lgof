#include "abstract_method_test.h"
#include "std_cout_redirect.h"
#include <abstract_method.h>

using namespace lgof;

void AbstractMethodTest::check(Display const &display, std::string_view expectedCout) const
{
    auto const stdCoutRedirect = StdCoutRedirect{};
    display.render();
    EXPECT_EQ(expectedCout, stdCoutRedirect.string());
}

TEST_F(AbstractMethodTest, TestWinConfig)
{
    auto const display = WinDisplay{};
    check(display, "WinButtonClickWinButtonPaint");
}

TEST_F(AbstractMethodTest, TestLinuxConfig)
{
    auto const display = LinuxDisplay{};
    check(display, "LinuxButtonClickLinuxButtonPaint");
}
