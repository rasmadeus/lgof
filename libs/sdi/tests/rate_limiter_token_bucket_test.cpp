#include "rate_limiter_token_bucket_test.h"
#include <chrono>
#include <rate_limiter_token_bucket.h>

using namespace sdi::rate_limiter_token_bucket;

TEST_F(TokenBucketTest, TestBucket)
{
    auto bucket = Bucket{
        2,
        std::chrono::milliseconds{ 100 }
    };

    EXPECT_TRUE(bucket.take());
    EXPECT_TRUE(bucket.take());
    EXPECT_FALSE(bucket.take());

    std::this_thread::sleep_for(std::chrono::milliseconds{ 110 });
    EXPECT_TRUE(bucket.take());
}
