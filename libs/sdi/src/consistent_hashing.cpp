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

int SimpleHasher::findServerFor(ServerId id)
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
