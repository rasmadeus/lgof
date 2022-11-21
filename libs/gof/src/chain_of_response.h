#pragma once

#include <gof_export.h>
#include <memory>
#include <string>

namespace lgof
{
    class GOF_EXPORT HintWidget
    {
    public:
        virtual ~HintWidget() = default;
        virtual std::string const &hint() const = 0;
    };

    class BaseHintWidget: public HintWidget
    {
    public:
        GOF_EXPORT void setHint(std::string hint);
        GOF_EXPORT void setNext(std::shared_ptr<HintWidget> const &next);
        GOF_EXPORT std::string const &hint() const override;

    private:
        std::string m_hint;
        std::shared_ptr<HintWidget> m_next;
    };
}
