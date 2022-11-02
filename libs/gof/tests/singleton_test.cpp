#include "singleton_test.h"
#include <singleton.h>

using namespace lgof;

TEST_F(SingletonTest, TestInstances)
{
    auto &firstInstance = DataBase::instance();
    auto &secondInstance = DataBase::instance();
    EXPECT_EQ(&firstInstance, &secondInstance);
}
