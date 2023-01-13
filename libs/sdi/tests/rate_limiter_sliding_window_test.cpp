#include "rate_limiter_sliding_window_test.h"
#include <rate_limiter_sliding_window.h>

using namespace sdi::rate_limiter_token_bucket;

TEST_F(SlidingWindowTest, TestSlidingWindow)
{
    auto limiter = SlidingWindow{ 2, std::chrono::milliseconds{ 100 } };

    EXPECT_TRUE(limiter.take());
    EXPECT_TRUE(limiter.take());
    EXPECT_FALSE(limiter.take());

    std::this_thread::sleep_for(std::chrono::milliseconds{ 200 });
    EXPECT_TRUE(limiter.take());
    EXPECT_TRUE(limiter.take());
}
