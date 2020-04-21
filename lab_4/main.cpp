#include <iostream>
#include "List.h"

using namespace buyer;

template <typename T>
bool equal(T lhs, T rhs)
{
    return lhs == rhs;
}
template <typename T>
bool more(T lhs, T rhs)
{
    return lhs > rhs;
}
template <typename T>
bool under(T lhs, T rhs)
{
    return lhs < rhs;
}
bool equalAccountNumber(Data lhs, Data rhs)
{
    return lhs.getAccountNumber() == rhs.getAccountNumber();
}
bool moreAccountNumber(Data lhs, Data rhs)
{
    return lhs.getAccountNumber() == rhs.getAccountNumber();
}
bool underAccountNumber(Data lhs, Data rhs)
{
    return lhs.getAccountNumber() == rhs.getAccountNumber();
}
bool equalSurname(Data lhs, Data rhs)
{
    return strcmp(lhs.getSurname(), rhs.getSurname()) == 0;
}
bool moreSurname(Data lhs, Data rhs)
{
    return strcmp(lhs.getSurname(), rhs.getSurname()) > 0;
}
bool underSurname(Data lhs, Data rhs)
{
    return strcmp(lhs.getSurname(), rhs.getSurname()) < 0;
}
bool equalTown(Data lhs, Data rhs)
{
    return strcmp(lhs.getTown(), rhs.getTown()) == 0;
}
bool moreTown(Data lhs, Data rhs)
{
    return strcmp(lhs.getTown(), rhs.getTown()) > 0;
}
bool underTown(Data lhs, Data rhs)
{
    return strcmp(lhs.getTown(), rhs.getTown()) < 0;
}

int main()
{
    std::cout << std::endl
              << "Data's Block: " << std::endl;
    List<Data, 10> listD(moreSurname);

    Data andrew("Skvortsov", "Andrew", "Moscow", "Polbina", 46, 42, 849141),
        kirill("Eleseev", "Kirill", "Tula", "Stalevaya", 78, 2, 119431),
        elena("Vyazemskaya", "Elena", "Bryansk", "Pervaya", 31, 10, 673921);

    listD.add(andrew);
    listD.add(kirill);
    listD.add(elena);

    List<Data, 10> filterD = listD.filter(andrew, underTown);
    std::cout << "Filtered list: " << std::endl;
    filterD.print();

    listD.search(kirill, equalAccountNumber);

    std::cout << std::endl
              << "Int's Block: " << std::endl;

    List<int, 10> listI(more);
    listI.add(-1);
    listI.add(32);
    listI.add(0);
    listI.add(63);
    listI.add(144);
    listI.add(4);
    listI.add(17);

    std::cout << "List out: " << std::endl;
    listI.print();

    List<int, 10> filterI = listI.filter(5, under);
    std::cout << "Filtered list: " << std::endl;
    filterI.print();

    return 0;
}
