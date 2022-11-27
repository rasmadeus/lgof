#pragma once

#include <gof_export.h>
#include <string>
#include <vector>

namespace lgof
{
    class Profile
    {
    public:
        GOF_EXPORT Profile(std::size_t id, std::string email);
        GOF_EXPORT std::size_t id() const;
        GOF_EXPORT std::string const &email() const;

    private:
        std::size_t m_id;
        std::string m_email;
    };

    class GOF_EXPORT Iterator
    {
    public:
        virtual ~Iterator() = default;
        virtual Profile const &next() = 0;
        virtual bool hasNext() const = 0;
    };

    class Facebook
    {
    public:
        GOF_EXPORT void loadProfiles();
        GOF_EXPORT Profile const &profile(std::size_t i) const;
        GOF_EXPORT std::size_t size() const;

    private:
        std::vector<Profile> m_profiles;
    };

    class FacebookIterator: public Iterator
    {
    public:
        GOF_EXPORT FacebookIterator(Facebook const &facebook);
        GOF_EXPORT Profile const &next() override;
        GOF_EXPORT bool hasNext() const override;

    private:
        Facebook const &m_facebook;
        std::size_t m_current{ 0 };
    };

    class Mailer
    {
    public:
        GOF_EXPORT Mailer();
        GOF_EXPORT void send();

    private:
        Facebook m_facebook;
    };
}
