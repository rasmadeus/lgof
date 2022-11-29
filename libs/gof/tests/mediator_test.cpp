#include "mediator_test.h"
#include "std_cout_redirect.h"
#include <mediator.h>

using namespace lgof;

TEST_F(MediatorTest, TestClick)
{
    auto mediator = MediatorDialog{};
    auto const stdCoutRedirect = StdCoutRedirect{};
    mediator.click();
    EXPECT_EQ("click", stdCoutRedirect.string());
}
