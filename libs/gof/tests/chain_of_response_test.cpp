#include "chain_of_response_test.h"
#include <chain_of_response.h>

using namespace lgof;

TEST_F(ChainOfResponseTest, TestHint)
{
    auto button = std::make_shared<BaseHintWidget>();
    button->setHint("button");

    auto panel = std::make_shared<BaseHintWidget>();
    panel->setNext(button);

    EXPECT_EQ("button", panel->hint());
    EXPECT_EQ("button", button->hint());
}
