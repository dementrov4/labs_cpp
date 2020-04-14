#include "OrderedList.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace buyer;

int main()
{
    // Все исключения отлавливаются внутри механизмов обработки списка

    OrderedList list;

    std::cout << "Loading list from file: " << std::endl;
    list.load("input.txt");

    std::cout << "Printing list: " << std::endl;
    list.print();

    std::cout << "Filtered list: " << std::endl;
    OrderedList filteredList = list.filter("Tomsk", '<');
    filteredList.print();

    std::cout << "List indexes: " << std::endl;
    list[-1]->showData(std::cout);
    list[0]->showData(std::cout);
    list[-3]->showData(std::cout);

    std::cout << "Adding element: " << std::endl;
    Data data("Nosova", "Anastasia", "Khabarovsk", "Lenina", 47, 12, 313524);
    list.add(data);
    list.print();

    std::cout << "Saving list to file: " << std::endl;
    list.save("output.txt");

    return 0;
}
