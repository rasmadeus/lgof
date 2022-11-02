#include "singleton.h"

using namespace lgof;

DataBase &DataBase::instance()
{
    static DataBase instance{};
    return instance;
}
