#include "bridge.h"

using namespace lgof;

bool Tv::isEnabled() const
{
    return m_isEnabled;
}

void Tv::enable()
{
    m_isEnabled = true;
}

void Tv::disable()
{
    m_isEnabled = false;
}

RemoteControl::RemoteControl(Device &device)
    : m_device{ device }
{
}

void RemoteControl::toggle()
{
    if (m_device.isEnabled())
    {
        m_device.disable();
    }
    else
    {
        m_device.enable();
    }
}
