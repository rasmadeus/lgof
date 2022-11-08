#include "decorator.h"
#include <iostream>

using namespace lgof;

SimpleText::SimpleText(std::string text)
    : m_text{ std::move(text) }
{
}

void SimpleText::draw() const
{
    std::cout << m_text;
}

HeaderDecorator::HeaderDecorator(std::unique_ptr<WebTag> webTag)
    : m_webTag{ std::move(webTag) }
{
}

void HeaderDecorator::draw() const
{
    std::cout << "<h1>";
    m_webTag->draw();
    std::cout << "</h1>";
}
