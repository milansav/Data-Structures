#include "tree.h"


void Tree::addNode(Node n)
{
    if(this->nodes.first == nullptr) this->nodes.first = &n;
    else if(this->nodes.second == nullptr) this->nodes.second = &n;
}

int Node::getDepth()
{
    int a = 0;
    int b = 0;
    if(this->nodes.first != nullptr) a = this->nodes.first->getDepth();
    if(this->nodes.second != nullptr) b = this->nodes.second->getDepth();

    if(a>b) return a;
    else return b;
}