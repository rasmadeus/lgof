#include "timer_test.h"
#include <timer.h>

using namespace tools::timer;

TEST_F(TimerTest, TestTimer)
{
    auto timer = Timer{};
    bool flag = false;

    timer.setInterval(std::chrono::milliseconds{ 200 }, [&flag]()
        { flag = true; });

    std::this_thread::sleep_for(std::chrono::milliseconds{ 100 });
    EXPECT_FALSE(flag);

    std::this_thread::sleep_for(std::chrono::milliseconds{ 200 });
    EXPECT_TRUE(flag);
}
