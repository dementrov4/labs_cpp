#pragma once
#include "NodeData.h"
#include "MyException.h"
#include <fstream>

namespace buyer
{
class List
{
protected:
    int listSize;
    Node *head;
    Node *tail;

public:
    List() : listSize(0), head(NULL), tail(NULL) {}
    List(Node *const element) : listSize(1), head(element), tail(head) {}
    List(const List &list);
    ~List();

    int size() const { return listSize; };

    void incSize() { ++listSize; }
    void subSize() { --listSize; }

    void addBegin(Node *);
    void addEnd(Node *);
    void insert(Node *, int);
    void remove(Node *);
    void save(const char *filename);
    void print() const;

    List &operator=(const List&);
    Node *operator[](int);
};
} 
