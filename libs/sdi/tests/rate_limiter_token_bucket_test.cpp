#include "rate_limiter_token_bucket_test.h"
#include <rate_limiter_token_bucket.h>

using namespace sdi::rate_limiter_token_bucket;

TEST_F(TokenBucketTest, TestBucket)
{
    auto bucket = Bucket{ 2 };

    EXPECT_TRUE(bucket.take());
    EXPECT_TRUE(bucket.take());
    EXPECT_FALSE(bucket.take());

    bucket.refill();
    EXPECT_TRUE(bucket.take());
}
