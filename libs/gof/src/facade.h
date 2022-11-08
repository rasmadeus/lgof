#pragma once

#include <gof_export.h>

namespace lgof
{
    class GOF_EXPORT VideoFileReader
    {
    public:
        void read() const;
    };

    class GOF_EXPORT VideoFileConverter
    {
    public:
        void convert() const;
    };

    class GOF_EXPORT VideoFileRender
    {
    public:
        void render() const;
    };

    class GOF_EXPORT VideoFacade
    {
    public:
        void show() const;

    private:
        VideoFileReader m_reader;
        VideoFileConverter m_converter;
        VideoFileRender m_render;
    };
}
