#include "template_method_test.h"
#include "std_cout_redirect.h"
#include <template_method.h>

using namespace lgof;
using namespace lgof::template_method;

TEST_F(TemplateMethodTest, TestBookPrinter)
{
    auto bookPrinter = BookPrinter{};
    auto stdCoutRedirect = StdCoutRedirect{};

    bookPrinter.print();
    EXPECT_EQ("book_printer", stdCoutRedirect.string());
}
