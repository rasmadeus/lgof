#pragma once

#include <gof_export.h>

namespace lgof
{
    class GOF_EXPORT Button
    {
    public:
        virtual ~Button() = default;
        virtual void paint() const = 0;
        virtual void click() const = 0;
    };

    class GOF_EXPORT WinButton: public Button
    {
    public:
        void paint() const override;
        void click() const override;
    };

    class GOF_EXPORT LinuxButton: public Button
    {
    public:
        void paint() const override;
        void click() const override;
    };
}
