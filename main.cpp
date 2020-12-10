#include "tree.h"
#include <iostream>
#include <utility>

int main()
{
    std::cout << "Created tree root" << std::endl;
    Tree tree;


    Node n = Node();
    Node n2 = Node();
    Node n3 = Node();
    Node n4 = Node();

    tree.addNode(n); 
    tree.addNode(n2);
    tree.addNode(n3);
    tree.addNode(n4);

    std::pair<int, int> depths = tree.getDepth();

    //std::cout << tree.getDepth();
    std::cout << "Tree depth: " << "Min:" << depths.first << " Max: " << depths.second << std::endl;
    return 0;
}