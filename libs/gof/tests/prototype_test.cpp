#include "prototype_test.h"
#include <prototype.h>

using namespace lgof;

TEST_F(PrototypeTest, TestPrototype)
{
    auto const circle = Circle{ 2.0 };
    auto const circleClone = circle.clone();
    EXPECT_EQ(circle.area(), circleClone->area());

    auto const square = Square{ 2.0 };
    auto const squareClone = square.clone();
    EXPECT_EQ(square.area(), squareClone->area());
}
