#pragma once 
#include "Data.h"
#include <exception>

namespace buyer
{
	class List
	{
	private:
		struct Node
		{
			Node* next;
			Node* prev;
			Data data;
		};
		Node* head;
		Node* tail;
		int length;

	public:
		List();
		~List();
		void add(Data);
		void remove(const char*);
		void print();
		void update(int, const Data&);
		void load(const char* filename = "input.txt");
		void save(const char* filename = "output.txt");
		Data searchAccountNumber(int);
		List filterTown(const char*, const char);
	};
}