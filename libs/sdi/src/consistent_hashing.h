#pragma once

#include <functional>
#include <map>
#include <sdi_export.h>
#include <unordered_map>
#include <vector>

namespace sdi::consistent_hashing
{
    using ServerId = int;
    using Key = int;
    using Hash = int;

    struct SDI_EXPORT Server
    {

        ServerId id{ 0 };
    };

    class SimpleHasher
    {
    public:
        SDI_EXPORT void addServer(ServerId id);
        SDI_EXPORT void removeServer(ServerId id);
        SDI_EXPORT ServerId findServerFor(Key key);
        SDI_EXPORT ServerId assignServerTo(Key key);

    private:
        void rehash();

    private:
        std::vector<Server> m_servers;
        std::unordered_map<Key, ServerId> m_hash;
    };

    class RingHasher
    {
    public:
        SDI_EXPORT bool addServer(ServerId id);
        SDI_EXPORT void removeServer(ServerId id);
        SDI_EXPORT ServerId findServerFor(Key key);

    private:
        std::hash<Key> m_hasher;
        std::map<ServerId, Server> m_servers;
    };
}
