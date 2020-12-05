#ifndef TREE_H
#define TREE_H

#include  <utility>

struct Node
{
public:
    Node();
    std::pair<Node*, Node*> nodes;
    void addNode(Node n);
    std::pair<int, int> getDepth(int currDepth); //Return min and max depth
};

struct Tree
{
public:
    Tree();
    std::pair<Node*, Node*> nodes;
    void addNode(Node n);
    std::pair<int, int> getDepth();
};

#endif