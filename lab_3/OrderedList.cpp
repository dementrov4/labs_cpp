#include "OrderedList.h"

namespace buyer
{
    void OrderedList::add(const Data& data) 
    {
        if (head == NULL || head->compareSurname(data.getSurname(), '<')) {
            addBegin(new NodeData(data));
        }
        else if (tail->compareSurname(data.getSurname(), '>')) {
            addEnd(new NodeData(data));
        } else {
            NodeData* operating = new NodeData(data);
            for (Node* temp = tail; temp != NULL; temp = temp->getPrev()) {
                if (temp->compareSurname(data.getSurname(), '>')) {
                    temp->getNext()->setPrev(temp);
                    operating->setNext(temp->getNext());
                    temp->setNext(operating);
                    operating->setPrev(temp);
                    break;
                }
            }
            incSize();
        }
    }
    void OrderedList::remove(const char* key) 
    {
        try {
            bool flag;
            for (Node *temp = tail; temp != NULL; temp = temp->getPrev()) {
                if (temp->compareSurname(key, '=')) {
                    flag = false;
                    if (temp->getNext() == NULL) {
                        remove(tail);
                    } else if (temp->getPrev() == NULL) {
                        remove(head);
                    } else {
                        temp->getNext()->setPrev(temp->getPrev());
                        temp->getPrev()->setNext(temp->getNext());
                        delete temp;
                    }
                    break;
                }
            }
            if (flag)
            {
                throw std::invalid_argument("removing error: bad key");
            }
            subSize();
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    Node *OrderedList::search(const int key)
    {
        Node *temp = head;

        if (listSize != 0)
        {
            while (temp != NULL && temp->compareAccountNumber(key, '='))
            {
                temp = temp->getNext();
            }
            return temp;
        }
    }
    OrderedList OrderedList::filter(const char* key, const char sign)
    {
        OrderedList list;

        for (Node *temp = tail; temp != NULL; temp = temp->getPrev())
        {
            if (temp->compareTown(key, sign)) {
                list.addEnd(temp->copyNode());
            }
        }

        return list;
    }

    void OrderedList::load(const char *filename)
    {
        std::ifstream fin(filename);

        if (!fin)
        {
            throw ListFileReadException();
        }

        Node *temp = head;
        Node *next;

        while (temp != nullptr)
        {
            next = temp->getNext();
            delete temp;
            temp = next;
        }

        listSize = 0;
        head = tail = NULL;

        while (fin.good()) {
            add(((new NodeData())->readData(fin))->getData());
        }
        fin.close();
    }
}