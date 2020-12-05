#ifndef TREE_H
#define TREE_H

#include  <utility>

struct Tree
{
    Tree();
    std::pair<Node*, Node*> nodes;
    void addNode(Node n);
};

struct Node
{
    Node();
    std::pair<Node*, Node*> nodes;
    void addNode(Node n);
    int getDepth();
};

#endif