#ifndef TREE_H
#define TREE_H

#include  <utility>

std::pair<int, int> getMinMax(std::pair<int, int> aDepths, std::pair<int, int> bDepths);

struct Node
{
    int depth; //Useless
    std::pair<Node*, Node*> nodes {nullptr,nullptr};
    std::pair<int, int> getDepth(int currDepth); //Return min and max depth
    std::pair<int, Node*> findEmptyNode(int currentDepth);
    Node();
};

struct Tree
{
    std::pair<Node*, Node*> nodes;
    void addNode(Node& n);
    std::pair<int, int> getDepth();
};

#endif