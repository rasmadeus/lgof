#pragma once

#include <gof_export.h>
#include <memory>
#include <string>

namespace lgof
{
    class GOF_EXPORT WebTag
    {
    public:
        virtual ~WebTag() = default;
        virtual void draw() const = 0;
    };

    class SimpleText: public WebTag
    {
    public:
        GOF_EXPORT SimpleText(std::string text);
        GOF_EXPORT void draw() const override;

    private:
        std::string m_text;
    };

    class HeaderDecorator: public WebTag
    {
    public:
        GOF_EXPORT HeaderDecorator(std::unique_ptr<WebTag> webTag);
        GOF_EXPORT void draw() const override;

    private:
        std::unique_ptr<WebTag> m_webTag;
    };

}
