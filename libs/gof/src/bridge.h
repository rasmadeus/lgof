#pragma once

#include <gof_export.h>

namespace lgof
{
    class GOF_EXPORT Device
    {
    public:
        virtual ~Device() = default;
        virtual bool isEnabled() const = 0;
        virtual void enable() = 0;
        virtual void disable() = 0;
    };

    class GOF_EXPORT Tv: public Device
    {
    public:
        bool isEnabled() const override;
        void enable() override;
        void disable() override;

    private:
        bool m_isEnabled{ false };
    };

    class GOF_EXPORT RemoteControl
    {
    public:
        RemoteControl(Device &device);
        void toggle();

    private:
        Device &m_device;
    };
}
