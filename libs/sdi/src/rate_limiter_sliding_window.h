#pragma once

#include <chrono>
#include <sdi_export.h>
#include <timer.h>
#include <vector>

namespace sdi::rate_limiter_token_bucket
{
    class SlidingWindow
    {
    public:
        SDI_EXPORT SlidingWindow(int bucketSize, std::chrono::milliseconds interval);
        SDI_EXPORT bool take();

    private:
        int const m_bucketSize;
        long long const m_interval;
        std::vector<long long> m_timestamps;
    };
}
