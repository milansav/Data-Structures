#include "list.h"

Node::Node()
{

}

void Node::push(Node &node)
{
    if(this->next != nullptr)
    {
        this->push(node);
    } else 
    {
        this->next = &node;
    }
}

void Node::pop()
{
    if(this->next != nullptr)
    {
        this->pop();
    } else 
    {
        delete this;
    }
}

List::List()
{

}

void List::push(Node &node)
{
    head->push(node);
}

void List::pop()
{
    head->pop();
}