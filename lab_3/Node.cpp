#include "Node.h"

namespace buyer
{

    Node *Node::getNext() const
    {
        return next;
    }
    Node *Node::getPrev() const
    {
        return prev;
    }

    Node *Node::setNext(Node *element)
    {
        next = element;
        return this;
    }
    Node *Node::setPrev(Node *element)
    {
        prev = element;
        return this;
    }
} 