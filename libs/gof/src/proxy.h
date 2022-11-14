#pragma once

#include <gof_export.h>
#include <string>
#include <unordered_map>

namespace lgof
{
    class GOF_EXPORT VideoHost
    {
    public:
        virtual ~VideoHost() = default;
        virtual std::string getVideoName(int id) = 0;
    };

    class GOF_EXPORT VideoDownloader: public VideoHost
    {
    public:
        std::string getVideoName(int id) override;
    };

    class VideoCacher: public VideoHost
    {
    public:
        GOF_EXPORT VideoCacher(VideoHost &videoHost);
        GOF_EXPORT std::string getVideoName(int id) override;

    private:
        VideoHost &m_videoHost;
        std::unordered_map<int, std::string> m_cach;
    };
}
