#pragma once
#include "DLList.h"

namespace buyer
{
    class OrderedList : public List
    {
    private:
        using List::addBegin;
        using List::addEnd;
        using List::insert;
        using List::remove;

    public:
        OrderedList() : List() {}
        OrderedList(const OrderedList &list) : List(list) {}

        void add(const Data&);
        void remove(const char*);

        Node *search(const int);
        OrderedList filter(const char*, const char);
        
        void load(const char *filename);
    };
}