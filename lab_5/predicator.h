#pragma once
#include "Data.h"

namespace buyer{

    class predicator {
    public:
    static bool equalAccountNumber(Data lhs, Data rhs)
    {
        return lhs.getAccountNumber() == rhs.getAccountNumber();
    }

    static bool moreAccountNumber(Data lhs, Data rhs)
    {
        return lhs.getAccountNumber() > rhs.getAccountNumber();
    }

    static bool underAccountNumber(Data lhs, Data rhs)
    {
        return lhs.getAccountNumber() < rhs.getAccountNumber();
    }

    static bool equalTown(Data lhs, Data rhs)
    {
        return lhs.getAccountNumber() == rhs.getAccountNumber();
    }

    static bool moreTown(Data lhs, Data rhs)
    {
        return lhs.getAccountNumber() > rhs.getAccountNumber();
    }

    static bool underTown(Data lhs, Data rhs)
    {
        return lhs.getAccountNumber() < rhs.getAccountNumber();
    }
    };
}