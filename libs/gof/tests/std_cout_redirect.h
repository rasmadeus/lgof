#pragma once

#include <iostream>
#include <sstream>
#include <streambuf>
#include <string>

namespace lgof
{
    class StdCoutRedirect
    {
    public:
        ~StdCoutRedirect();
        std::string string() const;

    private:
        std::stringstream m_current;
        std::streambuf *m_default{ std::cout.rdbuf(m_current.rdbuf()) };
    };
}
