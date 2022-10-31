#include "abstract_factory_test.h"
#include "abstract_factory.h"

using namespace lgof;

TEST_F(AbstractFactoryTest, TestWinFactory)
{
    const auto winFactory = WinFactory{};
    const auto app = Application{ winFactory };
    static const auto expectedPaint = std::string{ "WinButtonWinCheckBox" };
    EXPECT_EQ(expectedPaint, app.paint());
}

TEST_F(AbstractFactoryTest, TestLinuxFactory)
{
    const auto linuxFactory = LinuxFactory{};
    const auto app = Application{ linuxFactory };
    static const auto expectedPaint = std::string{ "LinuxButtonLinuxCheckBox" };
    EXPECT_EQ(expectedPaint, app.paint());
}
