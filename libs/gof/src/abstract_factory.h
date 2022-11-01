#pragma once

#include "button.h"
#include "check_box.h"
#include <gof_export.h>
#include <memory>

namespace lgof
{
    class GOF_EXPORT GuiFactory
    {
    public:
        virtual ~GuiFactory() = default;
        virtual std::unique_ptr<Button> makeButton() const = 0;
        virtual std::unique_ptr<CheckBox> makeCheckBox() const = 0;
    };

    class GOF_EXPORT WinFactory: public GuiFactory
    {
    public:
        std::unique_ptr<Button> makeButton() const override;
        std::unique_ptr<CheckBox> makeCheckBox() const override;
    };

    class GOF_EXPORT LinuxFactory: public GuiFactory
    {
    public:
        std::unique_ptr<Button> makeButton() const override;
        std::unique_ptr<CheckBox> makeCheckBox() const override;
    };

    class AbstractFactoryClient
    {
    public:
        GOF_EXPORT AbstractFactoryClient(GuiFactory const &guiFactory);
        GOF_EXPORT void paint() const;

    private:
        std::unique_ptr<Button> m_button;
        std::unique_ptr<CheckBox> m_checkBox;
    };
}
