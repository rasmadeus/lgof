#include "iterator_test.h"
#include "std_cout_redirect.h"
#include <iterator.h>

using namespace lgof;

TEST_F(IteratorTest, TestMailer)
{
    auto mailer = Mailer{};
    auto const stdCoutRedirect = StdCoutRedirect{};
    mailer.send();
    EXPECT_EQ("0011", stdCoutRedirect.string());
}
