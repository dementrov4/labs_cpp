#include "List.h"
#include <exception>

namespace buyer
{
template List<int, 10>;
template List<char, 10>;
template List<double, 10>;
template List<Data, 10>;

template <typename T, std::size_t capacity>
List<T, capacity>::List(bool (*compareFunction)(T, T))
{
    head = tail = NULL;
    length = 0;
    compFunc = compareFunction;
}

template <typename T, std::size_t capacity>
List<T, capacity>::List(const List &list)
{
    head = tail = NULL;
    length = 0;
    for (Node *temp = list.tail; temp != NULL; temp = temp->prev)
    {
        add(temp->data);
    }
}

template <typename T, std::size_t capacity>
void List<T, capacity>::add(T data)
{
    Node *temp = new Node;
    temp->next = NULL;
    temp->prev = NULL;
    temp->data = data;

    if (length == capacity)
    {
        std::cout << "Size of list is max - adding is impossible" << std::endl;
    }
    else
    {
        if (head == NULL)
        {
            head = tail = temp;
        }
        else if (compFunc(tail->data, data))
        {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        else if (!compFunc(head->data, data))
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        else
        {
            for (Node *operating = tail; operating != NULL; operating = operating->prev)
            {
                if (compFunc(temp->data, data))
                {
                    operating->next->prev = temp;
                    temp->next = operating->next;
                    operating->next = temp;
                    temp->prev = operating;
                    break;
                }
            }
        }
        ++length;
    }
}

template <typename T, std::size_t capacity>
void List<T, capacity>::remove(int key)
{
    if (length == 1)
    {
        delete head;
    }
    else if (key == 0)
    {
        head = head->next;
        delete head->prev;
    }
    else if (key = length - 1)
    {
        tail = tail->prev;
        delete tail->next;
    }
    else
    {
        Node *temp = head;
        for (int i = 0; i != key; ++i)
        {
            temp = temp->next;
        }
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
    }
    --length;
}
template <typename T, std::size_t capacity>
void List<T, capacity>::print()
{
    for (Node *temp = tail; temp != NULL; temp = temp->prev)
    {
        std::cout << temp->data << std::endl;
    }
}
template <typename T, std::size_t capacity>
void List<T, capacity>::update(int id, T element)
{
    if (id > length)
    {
        std::cout << "This position doesn't exist" << std::endl;
    }
    else
    {
        remove(id);
        add(element);
    }
}

template <typename T, std::size_t capacity>
void List<T, capacity>::load(const char *filename)
{
    std::ifstream file(filename);
    T temp;
    while (file.good())
    {
        file >> temp;
        add(temp);
    }
    file.close();
}

template <typename T, std::size_t capacity>
void List<T, capacity>::save(const char *filename)
{
    std::ofstream file(filename);

    for (Node *temp = tail; temp != NULL; temp = temp->prev)
    {
        file << temp->data << std::endl;
    }
    file.close();
}

template <typename T, std::size_t capacity>
T List<T, capacity>::search(T element, bool (*compareFunction)(T, T))
{
    T data;
    for (Node *temp = tail; temp != NULL; temp = temp->prev)
    {
        if (compareFunction(element, temp->data))
        {
            data = element;
            std::cout << "Element: " << element
                      << "is founded." << std::endl;
        }
    }
    return data;
}

template <typename T, std::size_t capacity>
List<T, capacity> List<T, capacity>::filter(T element, bool (*compareFunction)(T, T))
{
    List<T, capacity> list(compFunc);

    for (Node *temp = tail; temp != NULL; temp = temp->prev)
    {
        if (compareFunction(temp->data, element))
        {
            list.add(temp->data);
        }
    }
    return list;
}

template <typename T, std::size_t capacity>
List<T, capacity>::~List()
{
    Node *temp = head;
    Node *next;

    while (temp)
    {
        next = temp->next;
        delete temp;
        temp = next;
    }

    length = 0;
}
} // namespace buyer
