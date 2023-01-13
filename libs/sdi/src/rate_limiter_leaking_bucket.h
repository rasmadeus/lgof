#pragma once

#include <sdi_export.h>

namespace sdi::rate_limiter_leaking_bucket
{
    class Bucket
    {
    public:
        SDI_EXPORT Bucket(int bucketSize);
        SDI_EXPORT bool take();
        SDI_EXPORT void refill();

    private:
        int const m_bucketSize;
        int m_queueSize = 0;
    };
}
