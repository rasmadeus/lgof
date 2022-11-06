#include "adapter_test.h"
#include <adapter.h>

using namespace lgof;

TEST_F(AdapterTest, TestSqureAdapters)
{
    auto const squarePeg = SquarePeg{ 10.0 };
    auto const squarePegAdapter = SquarePegAdapter{ squarePeg };
    auto const roundHole = RoundHole{ 10.0 };
    EXPECT_TRUE(roundHole.fit(squarePegAdapter));
}
