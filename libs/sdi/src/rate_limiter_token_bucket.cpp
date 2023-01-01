#include "rate_limiter_token_bucket.h"

using namespace sdi::rate_limiter_token_bucket;

Bucket::Bucket(int bucketSize, std::chrono::milliseconds tokenRefillRate)
    : m_bucketSize{ bucketSize }
    , m_availableTokens{ m_bucketSize }
{
    m_timer.setInterval(tokenRefillRate, [this]()
        {
            std::lock_guard const lock{ m_availableTokensMutex };
            m_availableTokens = m_bucketSize;
        });
}

Bucket::~Bucket()
{
    m_timer.stop();
}

bool Bucket::take()
{
    std::lock_guard const lock{ m_availableTokensMutex };
    if (m_availableTokens == 0)
    {
        return false;
    }

    --m_availableTokens;
    return true;
}