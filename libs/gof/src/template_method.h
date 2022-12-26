#pragma once

#include <gof_export.h>

namespace lgof::template_method
{
    class GOF_EXPORT Printer
    {
    public:
        virtual ~Printer() = default;
        void print();

    protected:
        virtual void printHeader() = 0;
        virtual bool hasHeader() = 0;
    };

    class GOF_EXPORT BookPrinter: public Printer
    {
    protected:
        void printHeader() override;
        bool hasHeader() override;
    };
}
