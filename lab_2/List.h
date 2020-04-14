#pragma once
#include "Data.h"
#include <exception>
#include <cstdlib>

namespace buyer
{
class List
{
private:
    struct Node
    {
        Node *next;
        Node *prev;
        Data data;
    };
    Node *head;
    Node *tail;
    int length;

public:
    List();
    List(const List &);
    ~List();

    void add(Data);
    void remove(const char *);
    void print();
    void update(int, const Data &);
    void load(const char *filename = "input.txt");
    void save(const char *filename = "output.txt");
    Data searchAccountNumber(int);
    List filterTown(const char *, const char);

    List &operator=(const List &);
    Data &operator[](const int);

    List &operator+(const Data &);
    friend List &operator+(const Data &, List &);

    List &operator-(const int);
    friend List &operator-(const int, List &);

    friend std::ostream &operator<<(std::ostream &, const List &);
    friend std::ifstream &operator>>(std::ifstream &, List &);

    void loadBinary(const char *filename = "binary.dat");
    void saveBinary(const char *filename = "binary.dat");    
};
} // namespace buyer