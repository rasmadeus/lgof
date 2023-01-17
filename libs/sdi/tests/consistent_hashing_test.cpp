#include "consistent_hashing_test.h"
#include <consistent_hashing.h>

using namespace sdi::consistent_hashing;

TEST_F(ConsistentHasherTest, TestSimpleHasher)
{
    auto hasher = SimpleHasher{};
    hasher.addServer(0);

    hasher.assignServerTo(0);
    EXPECT_EQ(0, hasher.findServerFor(0));

    hasher.assignServerTo(1);
    EXPECT_EQ(0, hasher.findServerFor(1));

    hasher.removeServer(0);
    EXPECT_EQ(-1, hasher.findServerFor(1));

    hasher.addServer(0);
    EXPECT_EQ(0, hasher.findServerFor(1));

    hasher.addServer(1);
    EXPECT_EQ(1, hasher.findServerFor(1));
}
