#pragma once

#include <gof_export.h>

namespace lgof
{
    class DataBase
    {
    public:
        static DataBase &instance();

    private:
        DataBase() = default;
        DataBase(DataBase const &other) = delete;
        DataBase &operator=(DataBase const &other) = delete;
        DataBase(DataBase &&other) = delete;
        DataBase &operator=(DataBase &&other) = delete;
    };
}
