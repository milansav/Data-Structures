#include "tree.h"
#include <iostream>
#include <utility>

int main()
{
    std::cout << "Created tree root" << std::endl;
    Tree tree;
    std::cout << "Created empty node" << std::endl;
    Node n;

    tree.addNode(n); //RN throws seg fault

    Node n2;
    Node n3;
    Node n4;

    tree.addNode(n2); //These tree also throw seg fault rn
    tree.addNode(n3);
    tree.addNode(n4);

    std::pair<int, int> depths = tree.getDepth();

    //std::cout << tree.getDepth();
    std::cout << "Tree depth: " << "Min:" << depths.first << " Max: " << depths.second << std::endl;
    return 0;
}