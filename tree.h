#ifndef TREE_H
#define TREE_H

#include  <utility>

std::pair<int, int> getMinMax(std::pair<int, int> aDepths, std::pair<int, int> bDepths);

struct Node
{
    bool firstNull;
    bool secondNull;
    std::pair<Node*, Node*> nodes;
    void addNode(Node& n);
    std::pair<int, int> getDepth(int currDepth); //Return min and max depth
};

struct Tree
{
    bool firstNull;
    bool secondNull;
    std::pair<Node*, Node*> nodes;
    void addNode(Node& n);
    std::pair<int, int> getDepth();
};

#endif