#pragma once

#include <gof_export.h>

namespace lgof
{
    class GOF_EXPORT CheckBox
    {
    public:
        virtual ~CheckBox() = default;
        virtual void paint() const = 0;
    };

    class GOF_EXPORT WinCheckBox: public CheckBox
    {
    public:
        void paint() const override;
    };

    class GOF_EXPORT LinuxCheckBox: public CheckBox
    {
    public:
        void paint() const override;
    };
}
