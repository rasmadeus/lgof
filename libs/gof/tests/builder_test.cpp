#include "builder_test.h"
#include <builder.h>

using namespace lgof;

void BuilderTest::checkCoffee(CupSize expectedCupSize, int expectedSugar, Coffee const &coffee) const
{
    EXPECT_EQ(expectedCupSize, coffee.cupSize());
    EXPECT_EQ(expectedSugar, coffee.sugar());
}

TEST_F(BuilderTest, TestCoffeeBuilder)
{
    auto const barista = Barista{};
    checkCoffee(CupSize::Big, 3, barista.makeAmericano());
    checkCoffee(CupSize::Small, 1, barista.makeCapuchino());
}

TEST_F(BuilderTest, TestAdvertismentBuilder)
{
    auto const barista = Barista{};
    EXPECT_EQ("Size: big; Sugar: 3", barista.makeAmericanoAdvertisement());
    EXPECT_EQ("Size: small; Sugar: 1", barista.makeCapuchinoAdvertisement());
}
