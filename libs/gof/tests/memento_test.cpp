#include "memento_test.h"
#include "std_cout_redirect.h"
#include <memento.h>

using namespace lgof;

TEST_F(MementoTest, TestPrinter)
{
    auto printer = Printer{};

    printer.print("1");
    printer.print("2");
    printer.undo();

    auto const stdCoutRedirect = StdCoutRedirect{};
    printer.print();
    EXPECT_EQ("1", stdCoutRedirect.string());
}
