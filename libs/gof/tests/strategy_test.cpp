#include "strategy_test.h"
#include "std_cout_redirect.h"
#include <strategy.h>

using namespace lgof;
using namespace lgof::strategy;

TEST_F(StrategyTest, TestContext)
{
    auto context = Context{};
    auto stdCoutRedirect = StdCoutRedirect{};

    context.execute();
    EXPECT_EQ("add", stdCoutRedirect.string());

    context.setStrategy(std::make_unique<Subtract>());
    context.execute();
    EXPECT_EQ("addsubtract", stdCoutRedirect.string());
}
