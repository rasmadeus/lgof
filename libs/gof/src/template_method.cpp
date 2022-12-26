#include "template_method.h"
#include <iostream>

using namespace lgof::template_method;

void Printer::print()
{
    if (hasHeader())
    {
        printHeader();
    }
}

void BookPrinter::printHeader()
{
    std::cout << "book_printer";
}

bool BookPrinter::hasHeader()
{
    return true;
}
