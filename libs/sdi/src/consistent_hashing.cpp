#include "consistent_hashing.h"
#include <algorithm>

using namespace sdi::consistent_hashing;

void SimpleHasher::addServer(ServerId id)
{
    m_servers.emplace_back(id);
    rehash();
}

void SimpleHasher::removeServer(ServerId id)
{
    auto [begin, end] = std::ranges::remove_if(m_servers, [id](auto const &server)
        { return id == server.id; });

    m_servers.erase(begin, end);
    rehash();
}

ServerId SimpleHasher::findServerFor(Key id)
{
    const auto it = m_hash.find(id);
    return it == m_hash.cend() ? -1 : it->second;
}

int SimpleHasher::assignServerTo(Key key)
{
    const auto serverIndex = key % m_servers.size();
    const auto serverId = m_servers[serverIndex].id;
    m_hash[key] = serverId;
    return serverId;
}

void SimpleHasher::rehash()
{
    for (auto &[key, serverId] : m_hash)
    {
        if (m_servers.empty())
        {
            serverId = -1;
        }
        else
        {
            const auto serverIndex = key % m_servers.size();
            serverId = m_servers[serverIndex].id;
        }
    }
}

bool RingHasher::addServer(ServerId id)
{
    auto const res = m_servers.emplace(id, Server{ id });
    return res.second;
}

void RingHasher::removeServer(ServerId id)
{
    m_servers.erase(id);
}

ServerId RingHasher::findServerFor(Key key)
{
    if (m_servers.empty())
    {
        return -1;
    }

    auto const it = m_servers.lower_bound(key);
    return it == m_servers.cend() ? m_servers.cbegin()->second.id : it->second.id;
}
