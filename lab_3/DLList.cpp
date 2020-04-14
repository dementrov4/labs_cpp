#include "DLList.h"

namespace buyer
{
    List::List(const List &list)
    {
        listSize = 0;
        head = tail = NULL;
        for (Node *temp = list.head; temp != NULL; temp = temp->getNext()) {
            addEnd(temp->copyNode());
        }
    }

    List::~List()
    {
        tail = NULL;
        while (head != NULL) {
            Node *temp = head;
            head = head->getNext();
            delete temp;
        }
        listSize = 0;
    }

    void List::addBegin(Node *element)
    {
        if (head) {
            element->setNext(head);
            element->setPrev(NULL);
            head->setPrev(element);
            head = element;
        } else {
            element->setNext(NULL);
            element->setPrev(NULL);
            head = tail = element;
        }

        ++listSize;
    }

    void List::addEnd(Node *element)
    {
        if (tail) {
            element->setNext(NULL);
            element->setPrev(tail);
            tail->setNext(element);
            tail = element;
        } else {
            element->setNext(NULL);
            element->setPrev(NULL);
            head = tail = element;
        }

        ++listSize;
    }

    void List::insert(Node *element, int id)
    {
        if (id == listSize) {
            addEnd(element);
        } else if (id == 0) {
            addBegin(element);
        } else if (id > listSize || id < -listSize) {
            throw ListWrongIndexException(id);
        } else {
            id = (id + this->listSize) % this->listSize;

            Node *temp = head;

            for (int i = 0; i < id; ++i)
            {
                temp = temp->getNext();
            }

            element->setNext(temp);
            element->setPrev(temp->getPrev());
            temp->getPrev()->setNext(element);
            temp->setPrev(element);

            ++listSize;
        }
    }

    void List::remove(Node *element)
    {
        if (listSize == 0) {
            throw ListEmptyException();
        } else if (listSize == 1 && element == head) {
            head = tail = NULL;

            delete element;
            --listSize;
        } else if (element == head) {
            head = element->getNext();
            head->setPrev();

            delete element;
            --listSize;
        } else if (element == tail) {
            tail = element->getPrev();
            tail->setNext();

            delete element;
            --listSize;
        } else if (listSize > 1) {
            Node *temp = head->getNext();

            while (temp != NULL && temp != element) {
                temp = temp->getNext();
            }

            if (temp != NULL) {
                temp->getPrev()->setNext(temp->getNext());
                temp->getNext()->setPrev(temp->getPrev());

                delete temp;
                --listSize;
            }
        }
    }

    void List::save(const char *filename)
    {
        std::ofstream fout(filename);

        if (!fout.good()) {
            throw ListFileReadException();
        }

        for (Node *temp = tail; temp != NULL; temp = temp->getPrev()) {
            temp->showData(fout);
        }

        fout.close();
    }

    void List::print() const
    {
        for (Node* temp = head; temp != NULL; temp = temp->getNext()) {
            temp->showData(std::cout);
        }
    }

    List &List::operator=(const List &list)
    {
        if (this == &list)
            return *this;

        Node *temp = head;
        Node *next;

        while (temp != NULL) {
            next = temp->getNext();
            delete temp;
            temp = next;
        }

        listSize = 0;
        head = tail = NULL;

        for (temp = list.head; temp != NULL; temp->getNext()) {
            addEnd(temp->copyNode());
        }

        return *this;
    }

    Node *List::operator[](int index)
    {
        Node *temp = head;
        if (index >= listSize || index < -listSize) {
            throw ListWrongIndexException(index);
        } else {
            index = (index + listSize) % listSize;
            for (int i = 0; i < index; i++) {
                temp = temp->getNext();
            }
        }
        return temp;
    }
} 
