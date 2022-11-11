#include "flyweight_test.h"
#include "std_cout_redirect.h"
#include <flyweight.h>

using namespace lgof;

TEST_F(FlyweightTest, TestForest)
{
    auto forest = Forest{};

    forest.addTree(0, 0, TreeType::Oak, 1);
    EXPECT_EQ(1, forest.treeDataSize());

    forest.addTree(0, 1, TreeType::Oak, 2);
    EXPECT_EQ(2, forest.treeDataSize());

    forest.addTree(1, 0, TreeType::Oak, 1);
    EXPECT_EQ(2, forest.treeDataSize());

    forest.addTree(1, 1, TreeType::Birch, 1);
    EXPECT_EQ(3, forest.treeDataSize());

    forest.addTree(2, 0, TreeType::Birch, 1);
    EXPECT_EQ(3, forest.treeDataSize());

    auto const stdCoutRedirect = StdCoutRedirect{};
    forest.draw();
    EXPECT_EQ("00110112101111012001", stdCoutRedirect.string());
}
