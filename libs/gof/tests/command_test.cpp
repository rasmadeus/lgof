#include "command_test.h"
#include "std_cout_redirect.h"
#include <command.h>

using namespace lgof;

TEST_F(CommandTest, TestBroker)
{
    auto const stock = Stock{};
    auto broker = Broker{};
    broker.takeOrder(std::make_unique<BuyCommand>(stock));
    broker.takeOrder(std::make_unique<SellCommand>(stock));

    auto const stdCoutRedirect = StdCoutRedirect{};
    broker.placeOrders();
    EXPECT_EQ("buysell", stdCoutRedirect.string());
}
