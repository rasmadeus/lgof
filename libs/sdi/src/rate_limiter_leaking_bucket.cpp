#include "rate_limiter_leaking_bucket.h"

using namespace sdi::rate_limiter_leaking_bucket;

Bucket::Bucket(int bucketSize)
    : m_bucketSize{ bucketSize }
{
}

void Bucket::refill()
{
    if (m_queueSize > 0)
    {
        --m_queueSize;
    }
}

bool Bucket::take()
{
    if (m_queueSize < m_bucketSize)
    {
        ++m_queueSize;
        return true;
    }

    return false;
}
