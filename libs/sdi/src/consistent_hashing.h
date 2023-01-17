#pragma once

#include <sdi_export.h>
#include <unordered_map>
#include <vector>

namespace sdi::consistent_hashing
{
    using ServerId = int;
    using Key = int;

    struct SDI_EXPORT Server
    {

        int id{ 0 };
    };

    class SimpleHasher
    {
    public:
        SDI_EXPORT void addServer(ServerId id);
        SDI_EXPORT void removeServer(ServerId id);
        SDI_EXPORT int findServerFor(Key key);
        SDI_EXPORT int assignServerTo(Key key);

    private:
        void rehash();

    private:
        std::vector<Server> m_servers;
        std::unordered_map<Key, ServerId> m_hash;
    };
}
