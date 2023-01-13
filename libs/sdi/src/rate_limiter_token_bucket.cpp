#include "rate_limiter_token_bucket.h"

using namespace sdi::rate_limiter_token_bucket;

Bucket::Bucket(int bucketSize)
    : m_bucketSize{ bucketSize }
    , m_availableTokens{ m_bucketSize }
{
}

void Bucket::refill()
{
    m_availableTokens = m_bucketSize;
}

bool Bucket::take()
{
    if (m_availableTokens == 0)
    {
        return false;
    }

    --m_availableTokens;
    return true;
}