#include "rate_limiter_leaking_bucket_test.h"
#include <rate_limiter_leaking_bucket.h>

using namespace sdi::rate_limiter_leaking_bucket;

TEST_F(LeakingBucketTest, TestBucket)
{
    auto bucket = Bucket{ 2 };

    EXPECT_TRUE(bucket.take());
    EXPECT_TRUE(bucket.take());
    EXPECT_FALSE(bucket.take());

    bucket.refill();
    EXPECT_TRUE(bucket.take());
}
