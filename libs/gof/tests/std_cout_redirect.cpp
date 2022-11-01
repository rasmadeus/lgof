#include "std_cout_redirect.h"

using namespace lgof;

StdCoutRedirect::~StdCoutRedirect()
{
    std::cout.rdbuf(m_default);
}

std::string StdCoutRedirect::string() const
{
    return m_current.str();
}
