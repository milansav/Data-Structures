#include "tree.h"
#include <iostream>
#include <utility>

int main()
{
    std::cout << "Created tree root" << std::endl;
    Tree tree;
    std::cout << "Created empty node" << std::endl;
    Node n;

    tree.addNode(n);
/*
    Node n2;
    n.addNode(n2);

    Node n3;
    n.addNode(n3);

    n2.addNode(n3);

    tree.addNode(n3);
*/
    std::pair<int, int> depths = tree.getDepth();

    //std::cout << tree.getDepth();
    std::cout << "Tree depth: " << "Min:" << depths.first << " Max: " << depths.second << std::endl;
    return 0;
}