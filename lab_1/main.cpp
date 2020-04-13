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
	
	List l1;

	l1.add(Samsonova);
	l1.add(Nosova);
	l1.add(Agapov);
	l1.add(Levitsky);
	
	l1.update(5, Gurenko);
	l1.update(1, Gurenko);
	
	l1.print();

	std::cout << l1.searchAccountNumber(164525) << std::endl;
	l1.save();

	List l2 = l1.filterTown("Khabarovsk", '<');

	std::cout << "Filtered list: " << std::endl;
	l2.print();

	List l3;
	l3.load();

	std::cout << "Loaded list: " << std::endl;
 	l3.print();
}

