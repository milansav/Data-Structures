#include "tree.h"
#include <iostream>
#include <vector>

Node::Node()
{
    this->nodes.first = this->nodes.second = nullptr;
}

std::pair<int, int> getMinMax(std::pair<int, int> aDepths, std::pair<int, int> bDepths)
{
    //Find min and max depths
    int minA = 0, minB = 0, maxA = 0, maxB = 0;

    if(aDepths.first > aDepths.second)
    {
        minA = aDepths.second;
        maxA = aDepths.first;
    } else
    {
        minA = aDepths.first;
        maxA = aDepths.second;
    }

    if(bDepths.first > bDepths.second)
    {
        minB = bDepths.second;
        maxB = bDepths.first;
    } else
    {
        minB = bDepths.first;
        maxB = bDepths.second;
    }

    std::pair<int, int> depths;
    if(minA > minB) depths.first = minB;
    else depths.first = minA;
    if(maxA > maxB) depths.second = maxA;
    else depths.second = maxB;

    return depths;
}

std::pair<int, int> Node::getDepth(int currentDepth)
{

    bool firstNull = this->nodes.first == nullptr;
    bool secondNull = this->nodes.second == nullptr;

    std::cout << currentDepth << std::endl;

    std::pair<int, int> aDepths;
    std::pair<int, int> bDepths;

    if( firstNull && secondNull ) //If there are no other child nodes return currentDepth 
        return std::pair<int, int>{currentDepth, currentDepth};

    if(!firstNull) aDepths = this->nodes.first->getDepth(currentDepth+1); //Call recursively into the left node, each time increasing the depth
    else aDepths = std::make_pair(currentDepth, currentDepth);
    if(!secondNull) bDepths = this->nodes.second->getDepth(currentDepth+1); //Call recursively into the right node, each time increasing the depth
    else bDepths = std::make_pair(currentDepth, currentDepth);
    
    return getMinMax(aDepths, bDepths);
}

std::pair<int, int> Tree::getDepth()
{

    bool firstNull = this->nodes.first == nullptr;
    bool secondNull = this->nodes.second == nullptr;

    std::pair<int, int> aDepths;
    std::pair<int, int> bDepths;

    if(firstNull && secondNull) //If root has no child nodes return 0 0
        return std::pair<int, int>{0,0};
    
    if(!firstNull) aDepths = this->nodes.first->getDepth(1); //Call recursively into the left node
    if(!secondNull) bDepths = this->nodes.second->getDepth(1); //Call recursively into the right node

    return getMinMax(aDepths, bDepths);
}

void Tree::addNode(Node& n)
{


    bool firstNull = this->nodes.first == nullptr;
    bool secondNull = this->nodes.second == nullptr;

    std::pair<std::pair<int, Node*>, std::pair<int, Node*>> emptyNodes;

    if(this->nodes.first == nullptr) this->nodes.first = &n;
    else emptyNodes.first = this->nodes.first->findEmptyNode(0);

    if(this->nodes.second == nullptr) this->nodes.second = &n;
    else emptyNodes.second = this->nodes.second->findEmptyNode(0);

    //Because we know neither of them can't be not nullptr choose the closest one
    if(emptyNodes.first.first > emptyNodes.second.first)
        emptyNodes.first.second = &n;
    else emptyNodes.second.second = &n;
}

std::pair<int, Node*> Node::findEmptyNode(int currentDepth)
{
    bool firstNull = this->nodes.first == nullptr;
    bool secondNull = this->nodes.second == nullptr;

    std::cout << "Finding null node" << std::endl;

    std::pair<std::pair<int, Node*>, std::pair<int, Node*>> emptyNodes;

    if(firstNull)
    {
        return std::pair<int, Node*>{currentDepth, this->nodes.first};
    } else emptyNodes.first = this->nodes.first->findEmptyNode(currentDepth+1);

    if(secondNull)
    {
        return std::pair<int, Node*>{currentDepth, this->nodes.second};
    } else emptyNodes.second = this->nodes.second->findEmptyNode(currentDepth+1);

    if(emptyNodes.first.first < emptyNodes.second.first)
    {
        return std::pair<int, Node*>{emptyNodes.second.first, emptyNodes.second.second};
    
    } else
    {
        return std::pair<int, Node*>{emptyNodes.first.first, emptyNodes.first.second};
    }       
}