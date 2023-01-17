#include "consistent_hashing.h"
#include <algorithm>

using namespace sdi::consistence_hashing;

void SimpleHasher::addServer(int id)
{
    m_servers.emplace_back(id);
    rehash();
}

void SimpleHasher::removeServer(int id)
{
    auto const it = std::ranges::remove_if(m_servers, [id](auto const &server)
        { return id == server.id; });

    m_servers.erase(it, m_servers.end());
    rehash();
}

int SimpleHasher::findSererFor(int id)
{
    const auto it = hash.find(id);
    return it == hash.cend() ? -1 : it->second;
}

void SimpleHasher::assignServerToKey(int key)
{
    const auto hash = std::hash(key);
    const auto serverIndex = hash % m_servers.size();
    const auto serverId = m_servers[serverIndex].id;
    m_hash[key] = serverId;
    return serverId;
}

void SimpleHasher::rehash()
{
    for (auto [key, &serverId] : m_servers)
    {
        serverId = assignServerToKey(key);
    }
}
