#include "composite_test.h"
#include "std_cout_redirect.h"
#include <composite.h>

using namespace lgof;

TEST_F(CompositeTest, TestCompoundGraphic)
{
    auto rectangles = std::make_unique<CompoundGraphic>();
    rectangles->add(std::make_unique<Rectangle>());
    rectangles->add(std::make_unique<Rectangle>());

    auto root = CompoundGraphic{};
    root.add(std::make_unique<Rectangle>());
    root.add(std::move(rectangles));

    auto const stdCoutRedirect = StdCoutRedirect{};
    root.draw();
    EXPECT_EQ("DrawRectangleDrawRectangleDrawRectangle", stdCoutRedirect.string());
}
