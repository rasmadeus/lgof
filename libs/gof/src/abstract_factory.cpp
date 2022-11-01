#include "abstract_factory.h"

using namespace lgof;

std::unique_ptr<Button> WinFactory::makeButton() const
{
    return std::unique_ptr<WinButton>();
}

std::unique_ptr<CheckBox> WinFactory::makeCheckBox() const
{
    return std::unique_ptr<WinCheckBox>();
}

std::unique_ptr<Button> LinuxFactory::makeButton() const
{
    return std::unique_ptr<LinuxButton>();
}

std::unique_ptr<CheckBox> LinuxFactory::makeCheckBox() const
{
    return std::unique_ptr<LinuxCheckBox>();
}

AbstractFactoryClient::AbstractFactoryClient(GuiFactory const &guiFactory)
    : m_button{ guiFactory.makeButton() }
    , m_checkBox{ guiFactory.makeCheckBox() }
{
}

void AbstractFactoryClient::paint() const
{
    m_button->paint();
    m_checkBox->paint();
}
