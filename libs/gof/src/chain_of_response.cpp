#include "chain_of_response.h"

using namespace lgof;

void BaseHintWidget::setHint(std::string hint)
{
    m_hint = std::move(hint);
}

void BaseHintWidget::setNext(std::shared_ptr<HintWidget> const &next)
{
    m_next = next;
}

std::string const &BaseHintWidget::hint() const
{
    if (m_hint.empty() && m_next)
    {
        return m_next->hint();
    }
    else
    {
        return m_hint;
    }
}
