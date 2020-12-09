#include "tree.h"
#include <iostream>


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

    std::pair<std::pair<int, Node*>, std::pair<int, Node*>> emptyNodes {{0, nullptr}, {0, nullptr}};

    if(this->nodes.first == nullptr) this->nodes.first = &n;
    else emptyNodes.first = this->nodes.first->findEmptyNode(0);

    if(this->nodes.second == nullptr) this->nodes.second = &n;
    else emptyNodes.second = this->nodes.second->findEmptyNode(0);

    //Because we know neither of them can't be not nullptr choose the closest one
    if(emptyNodes.first.first > emptyNodes.second.first)
        emptyNodes.first.second = &n;
    else emptyNodes.second.second = &n;
}

std::pair<int, Node*> Node::findEmptyNode(int currentDepth) //std::pair<depth, NodePointer>
{
    bool firstNull = this->nodes.first == nullptr;
    bool secondNull = this->nodes.second == nullptr;

    std::pair<std::pair<int, Node*>, std::pair<int, Node*>> emptyNodes {{currentDepth, nullptr}, {currentDepth, nullptr}};

    if(firstNull)
    { 
        emptyNodes.first.first = currentDepth;
        *emptyNodes.first.second = *this->nodes.first;
    } //If its not empty, look into child
    else emptyNodes.first = this->nodes.first->findEmptyNode(currentDepth+1);


    if(secondNull)
    {
        emptyNodes.second.first = currentDepth;
        *emptyNodes.second.second = *this->nodes.second;
    } //If its not empty, look into child
    else emptyNodes.second = this->nodes.second->findEmptyNode(currentDepth+1);

    //Return the closest one
    if(emptyNodes.first.first > emptyNodes.second.first) //Right is closer than left
    {
        if(emptyNodes.second.second == nullptr) return emptyNodes.second; //If second is nullptr return it
        return emptyNodes.first; //If no return first
    } else //Left is closer or the same distance from root, either way return left
    {
        if(emptyNodes.first.second == nullptr) return emptyNodes.first; //Same
        return emptyNodes.second;
    }

}