#include "proxy.h"

using namespace lgof;

std::string VideoDownloader::getVideoName(int id)
{
    return std::to_string(id);
}

VideoCacher::VideoCacher(VideoHost &videoHost)
    : m_videoHost{ videoHost }
{
}

std::string VideoCacher::getVideoName(int id)
{
    if (!m_cach.contains(id))
    {
        m_cach[id] = m_videoHost.getVideoName(id);
    }

    return m_cach[id];
}
