#include "tree.h"

std::pair<int, int> getMinMax(std::pair<int, int> aDepths, std::pair<int, int> bDepths)
{
    
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
    std::pair<int, int> aDepths;
    std::pair<int, int> bDepths;

    if(this->nodes.first == nullptr && this->nodes.second == nullptr) //If there are no other child nodes return currentDepth 
        return std::pair<int, int>{currentDepth, currentDepth};

    if(this->nodes.first != nullptr) aDepths = this->nodes.first->getDepth(currentDepth+1); //Call recursively into the left node, each time increasing the depth
    else aDepths = std::make_pair(currentDepth, currentDepth);
    if(this->nodes.second != nullptr) bDepths = this->nodes.second->getDepth(currentDepth+1); //Call recursively into the right node, each time increasing the depth
    else bDepths = std::make_pair(currentDepth, currentDepth);
    
    return getMinMax(aDepths, bDepths);
}

std::pair<int, int> Tree::getDepth()
{
    std::pair<int, int> aDepths;
    std::pair<int, int> bDepths;

    if(this->nodes.first == nullptr && this->nodes.second == nullptr)
        return std::pair<int, int>{0,0};
    
    if(this->nodes.first == nullptr) aDepths = this->nodes.first->getDepth(1); //Call recursively into the left node
    if(this->nodes.second == nullptr) bDepths = this->nodes.second->getDepth(1); //Call recursively into the right node

    return getMinMax(aDepths, bDepths);
}