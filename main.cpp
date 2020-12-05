#include "tree.h"
#include <iostream>
#include <utility>

int main()
{

    Tree tree;
    Node n;

    std::pair<int, int> depths = tree.getDepth();

    //std::cout << tree.getDepth();
    std::cout << depths.first << " " << depths.second << std::endl;
    std::cout << "aaaaa" << std::endl;
    return 0;
}