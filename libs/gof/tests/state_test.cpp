#include "state_test.h"
#include "std_cout_redirect.h"
#include <state.h>

using namespace lgof;
using namespace lgof::state;

TEST_F(StateTest, TestPlayer)
{
    auto player = Player{};
    auto stdCoutRedirect = StdCoutRedirect{};

    player.clickPlay();
    EXPECT_EQ("play", stdCoutRedirect.string());

    player.clickLock();
    EXPECT_EQ("play", stdCoutRedirect.string());

    player.clickPlay();
    EXPECT_EQ("play", stdCoutRedirect.string());

    player.clickUnlock();
    EXPECT_EQ("play", stdCoutRedirect.string());

    player.clickPlay();
    EXPECT_EQ("playplay", stdCoutRedirect.string());
}
