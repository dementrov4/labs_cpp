#pragma once
#include <list>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "Data.h"

namespace buyer
{
class List : public std::list<Data>
{
public:
    List() : list<Data>() {}
    List(const Data &data) : list<Data>(1, data) {}
    ~List() { erase(begin(), end()); }

    void add(const Data&);
    void remove(const std::string);
    void update(int, Data);

    void print();
    void printReversed();

    Data search(Data, bool (*compareFunction)(Data, Data));
    List filter(Data, bool (*compareFunction)(Data, Data));

    void load(const char *filename = "input.txt");
    void save(const char *filename = "output.txt");
};
} 
