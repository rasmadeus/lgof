#include "decorator_test.h"
#include "std_cout_redirect.h"
#include <decorator.h>

using namespace lgof;

TEST_F(DecoratorTest, TestDecorator)
{
    auto simpleText = std::make_unique<SimpleText>("simple text");
    auto headerDecorator = HeaderDecorator{ std::move(simpleText) };
    auto const stdCoutRedirect = StdCoutRedirect{};
    headerDecorator.draw();
    EXPECT_EQ("<h1>simple text</h1>", stdCoutRedirect.string());
}
