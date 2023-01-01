#pragma once

#include <sdi_export.h>
#include <timer.h>

namespace sdi::rate_limiter_token_bucket
{
    class Bucket
    {
    public:
        SDI_EXPORT Bucket(int bucketSize, std::chrono::milliseconds tikenRefillRate);
        SDI_EXPORT ~Bucket();
        SDI_EXPORT bool take();

    private:
        int const m_bucketSize;
        std::mutex m_availableTokensMutex;
        int m_availableTokens;
        tools::timer::Timer m_timer;
    };
}
