#pragma once
#include <fstream>
#include <string>
#include "Data.h"

namespace buyer
{
template <typename T, std::size_t capacity>
class List
{
private:
    struct Node
    {
        Node *next;
        Node *prev;
        T data;
    };
    Node *head;
    Node *tail;
    int length;
    bool (*compFunc)(T, T);

public:
    List(bool (*compareFunction)(T, T));
    List(const List &);
    ~List();
    void add(T);
    void remove(int key = 0);
    void print();
    void update(int, T);
    void load(const char *filename = "input.txt");
    void save(const char *filename = "output.txt");
    T search(T, bool (*compareFunction)(T, T));
    List<T, capacity> filter(T, bool (*compareFunction)(T, T));
};
} // namespace buyer
