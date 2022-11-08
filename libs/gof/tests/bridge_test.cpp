#include "bridge_test.h"
#include <bridge.h>

using namespace lgof;

TEST_F(BridgeTest, TestTv)
{
    auto tv = Tv{};
    EXPECT_FALSE(tv.isEnabled());

    tv.enable();
    EXPECT_TRUE(tv.isEnabled());

    tv.disable();
    EXPECT_FALSE(tv.isEnabled());
}

TEST_F(BridgeTest, TestRemoteControl)
{
    auto tv = Tv{};
    auto remoteControl = RemoteControl{ tv };

    remoteControl.toggle();
    EXPECT_TRUE(tv.isEnabled());

    remoteControl.toggle();
    EXPECT_FALSE(tv.isEnabled());
}
