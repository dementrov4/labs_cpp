#include "List.h"
#include "predicator.h"
#include <iostream>
using namespace buyer;

int main()
{
    List list;
    predicator pred;

    Data andrew("Skvortsov", "Andrew", "Moscow", "Polbina", 46, 42, 849141),
        kirill("Eleseev", "Kirill", "Tula", "Stalevaya", 78, 2, 119431),
        elena("Vyazemskaya", "Elena", "Bryansk", "Pervaya", 31, 10, 673921),
        urun("Bajangla", "Urun", "Astalap", "Inju", 1454, 41, 684910);

    list.add(andrew);
    list.add(kirill);
    list.add(elena);
    list.add(urun);

    std::cout << "Printed list:" << std::endl;
    list.print();

    std::cout << "Reversed printed list:" << std::endl;
    list.printReversed();

    std::cout << "Sorted list:" << std::endl;
    list.sort(pred.underAccountNumber); 
    list.print();

    std::cout << "Filtered list:" << std::endl;
    list.filter(kirill, pred.underTown).print();
    
    return 0;
}
