#include "iterator.h"
#include <cassert>
#include <iostream>

using namespace lgof;

Profile::Profile(std::size_t id, std::string email)
    : m_id{ id }
    , m_email{ std::move(email) }
{
}

std::size_t Profile::id() const
{
    return m_id;
}

std::string const &Profile::email() const
{
    return m_email;
}

void Facebook::loadProfiles()
{
    m_profiles.clear();

    for (std::size_t i = 0; i < 2; ++i)
    {
        m_profiles.emplace_back(Profile{ i, std::to_string(i) });
    }
}

Profile const &Facebook::profile(std::size_t i) const
{
    return m_profiles[i];
}

std::size_t Facebook::size() const
{
    return m_profiles.size();
}

FacebookIterator::FacebookIterator(Facebook const &facebook)
    : m_facebook{ facebook }
{
}

Profile const &FacebookIterator::next()
{
    assert(hasNext());
    return m_facebook.profile(m_current++);
}

bool FacebookIterator::hasNext() const
{
    return m_current < m_facebook.size();
}

Mailer::Mailer()
{
    m_facebook.loadProfiles();
}

void Mailer::send()
{
    auto it = FacebookIterator{ m_facebook };
    while (it.hasNext())
    {
        auto const &profile = it.next();
        std::cout << profile.id() << profile.email();
    }
}
