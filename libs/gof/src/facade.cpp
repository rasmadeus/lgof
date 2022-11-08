#include "facade.h"
#include <iostream>

using namespace lgof;

void VideoFileReader::read() const
{
    std::cout << "read";
}

void VideoFileConverter::convert() const
{
    std::cout << "convert";
}

void VideoFileRender::render() const
{
    std::cout << "render";
}

void VideoFacade::show() const
{
    m_reader.read();
    m_converter.convert();
    m_render.render();
}
