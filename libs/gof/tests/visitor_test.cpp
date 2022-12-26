#include "visitor_test.h"
#include "std_cout_redirect.h"
#include <visitor.h>

using namespace lgof;
using namespace lgof::visitor;

TEST_F(VisitorTest, TestLogger)
{
    auto logger = Logger{};
    auto circle = Circle{};
    auto rect = Rect{};

    auto stdCoutRedirect = StdCoutRedirect{};
    circle.accept(logger);
    rect.accept(logger);
    EXPECT_EQ("211", stdCoutRedirect.string());
}
