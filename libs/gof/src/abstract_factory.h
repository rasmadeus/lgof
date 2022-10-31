#pragma once

#include <memory>
#include <string>

namespace lgof
{
    class Button
    {
    public:
        virtual ~Button() = default;
        virtual std::string paint() const = 0;
    };

    class WinButton: public Button
    {
    public:
        std::string paint() const override
        {
            return "WinButton";
        }
    };

    class LinuxButton: public Button
    {
    public:
        std::string paint() const override
        {
            return "LinuxButton";
        }
    };

    class CheckBox
    {
    public:
        virtual ~CheckBox() = default;
        virtual std::string paint() const = 0;
    };

    class WinCheckBox: public CheckBox
    {
    public:
        std::string paint() const override
        {
            return "WinCheckBox";
        }
    };

    class LinuxCheckBox: public CheckBox
    {
    public:
        std::string paint() const override
        {
            return "LinuxCheckBox";
        }
    };

    class GuiFactory
    {
    public:
        virtual ~GuiFactory() = default;
        virtual std::unique_ptr<Button> makeButton() const = 0;
        virtual std::unique_ptr<CheckBox> makeCheckBox() const = 0;
    };

    class WinFactory: public GuiFactory
    {
    public:
        std::unique_ptr<Button> makeButton() const override
        {
            return std::make_unique<WinButton>();
        }

        virtual std::unique_ptr<CheckBox> makeCheckBox() const override
        {
            return std::make_unique<WinCheckBox>();
        }
    };

    class LinuxFactory: public GuiFactory
    {
    public:
        std::unique_ptr<Button> makeButton() const override
        {
            return std::make_unique<LinuxButton>();
        }

        std::unique_ptr<CheckBox> makeCheckBox() const override
        {
            return std::make_unique<LinuxCheckBox>();
        }
    };

    class Application
    {
    public:
        Application(GuiFactory const &guiFactory)
            : m_button{ guiFactory.makeButton() }
            , m_checkBox{ guiFactory.makeCheckBox() }
        {
        }

        std::string paint() const
        {
            return m_button->paint() + m_checkBox->paint();
        }

    private:
        std::unique_ptr<Button> m_button;
        std::unique_ptr<CheckBox> m_checkBox;
    };
}
