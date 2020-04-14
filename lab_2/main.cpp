#include <iostream>
#include "Data.h"
#include "List.h"

using namespace buyer;

int main()
{
    Data Nosova("Nosova", "Anastasia", "Khabarovsk", "Lenina", 47, 12, 313524),
        Agapov("Agapov", "Denis", "Tumen", "Oktybarskaya", 9, 212, 164525),
        Levitsky("Levitsky", "Egor", "Krasnodar", "Selikatnaya", 25, 786, 145234),
        Samsonova("Samsonova", "Maria", "Zvezdny", "Roschinskaya", 13, 392, 942561),
        Gurenko;

    Gurenko.setData("Gurenko", "Zakhar", "Zylovsk", "Temnaya", 48, 16, 395293);

    Samsonova = Gurenko;

    Samsonova.setSurname("Samsonova");
    Samsonova.setName("Zoya");

    std::cout << Samsonova;
    List l1;

    l1.add(Samsonova);
    l1.add(Nosova);
    l1.add(Agapov);
    l1.add(Levitsky);

    List l2(l1);

    std::cout << "List that was created by copy constructor: " << std::endl; 
    l2.print();

    List l3 = l1;

    std::cout << "List that was created by assignment operator: " << std::endl;
    l3.print();

    std::cout << "Using of index operator: " << std::endl; 
    std::cout << l3[1] << std::endl;

    std::cout << "Using of adding operator: " << std::endl;
    l3 = l3 + Gurenko;
    l3 = Levitsky + l3;

    l3.print();

    std::cout << "Using of subtract operator: " << std::endl;
    l3 = l3 - 395293;
    l3 = 145234 - l3;

    l3.print();

    std::cout << "Using I/O operators: " << std::endl; 

    std::cout << l1;

    std::ifstream fin("input.txt");

    List l4;
    fin >> l4;

    fin.close();

    std::ofstream fout ("output.txt");

    fout << l4;

    fout.close();

    std::cout << "List filtration with overloaded signs: " << std::endl
              << l1.filterTown("Ternopol", '>');

    std::cout << "Save and load from binary: " << std::endl;
    
    List l5;
    l5.loadBinary();

    std::cout << l5;

    l5.saveBinary();

    
    return 0;
}