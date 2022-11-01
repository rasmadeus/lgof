#pragma once

#include "button.h"
#include <gof_export.h>
#include <memory>

namespace lgof
{
    class GOF_EXPORT Display
    {
    public:
        virtual ~Display() = default;
        void render() const;

    protected:
        virtual std::unique_ptr<Button> makeButton() const = 0;
    };

    class GOF_EXPORT WinDisplay: public Display
    {
    protected:
        std::unique_ptr<Button> makeButton() const override;
    };

    class GOF_EXPORT LinuxDisplay: public Display
    {
    protected:
        std::unique_ptr<Button> makeButton() const override;
    };
}
