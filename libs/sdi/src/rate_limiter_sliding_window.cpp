#include "rate_limiter_sliding_window.h"

using namespace sdi::rate_limiter_token_bucket;

SlidingWindow::SlidingWindow(int bucketSize, std::chrono::milliseconds interval)
    : m_bucketSize{ bucketSize }
    , m_interval{ interval.count() }
{
}

bool SlidingWindow::take()
{
    const auto now = std::chrono::system_clock::now().time_since_epoch();
    const auto key = std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
    m_timestamps.emplace_back(key);

    const auto keepKey = key - m_interval;
    const auto leftBorder = std::ranges::lower_bound(m_timestamps, keepKey);
    m_timestamps.erase(m_timestamps.cbegin(), leftBorder);

    return m_timestamps.size() <= m_bucketSize;
}
