#ifndef LIST_H
#define LIST_H

struct Node
{
    Node *next {nullptr};
    Node();
    void push(Node &node);
    void pop();
};

struct List
{
    Node *head;
    List();
    void push(Node &node);
    void pop();
};

#endif