#include "proxy_test.h"
#include <proxy.h>

using namespace lgof;

TEST_F(ProxyTest, TestVideoCacher)
{
    auto videoDownloader = VideoDownloader{};
    auto videoCacher = VideoCacher{ videoDownloader };

    EXPECT_EQ("1", videoCacher.getVideoName(1));
    EXPECT_EQ("2", videoCacher.getVideoName(2));
}
