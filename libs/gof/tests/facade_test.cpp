#include "facade_test.h"
#include "std_cout_redirect.h"
#include <facade.h>

using namespace lgof;

TEST_F(FacadeTest, TestFacade)
{
    auto const facade = VideoFacade{};
    auto const stdCoutRedirect = StdCoutRedirect{};
    facade.show();
    EXPECT_EQ("readconvertrender", stdCoutRedirect.string());
}
