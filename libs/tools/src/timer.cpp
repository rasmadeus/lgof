#include "timer.h"
#include <thread>

using namespace tools::timer;

void Timer::setInterval(std::chrono::milliseconds interval, std::function<void()> f)
{
    if (m_isActive)
        return;

    m_isActive = true;

    auto thread = std::thread{
        [interval, f, this]()
        {
            while (true)
            {
                if (!m_isActive)
                    break;

                std::this_thread::sleep_for(interval);

                if (m_isActive)
                    f();
                else
                    break;
            }
        }
    };

    thread.detach();
}

void Timer::stop()
{
    m_isActive = false;
}
