#ifndef LIST_H
#define LIST_H

struct List
{
    List::List *head;
    List::List *next;
    List();
    void push(List &list);
    void pop();
};

#endif