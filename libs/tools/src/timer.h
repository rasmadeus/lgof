#pragma once

#include <chrono>
#include <functional>
#include <tools_export.h>

namespace tools::timer
{
    class Timer
    {
    public:
        void TOOLS_EXPORT setInterval(std::chrono::milliseconds timeouot, std::function<void()> f);
        void TOOLS_EXPORT stop();

    private:
        bool m_isActive{ false };
    };
}
