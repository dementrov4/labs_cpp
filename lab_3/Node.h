#pragma once
#include <iostream>

namespace buyer
{
    class Node
    {
    protected:
        Node *next;
        Node *prev;

    public:
        Node() : next(NULL) {}
        Node(const Node &element) : next(element.getNext()) {}

        virtual ~Node(){};

        virtual Node *getNext() const;
        virtual Node *getPrev() const;

        virtual Node *setNext(Node *element = NULL);
        virtual Node *setPrev(Node *element = NULL);

        virtual Node *copyNode() = 0;
        virtual Node *readData(std::istream &) = 0;
        virtual void showData(std::ostream &) const = 0;
        virtual bool compareSurname(const char*, const char) const = 0;
        virtual bool compareAccountNumber(const int, const char) const = 0;
        virtual bool compareTown(const char*, const char) const = 0;
    };
}
