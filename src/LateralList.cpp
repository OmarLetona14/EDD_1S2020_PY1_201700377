#include "LateralList.h"

LateralList::LateralList(){
    this->first = NULL;
    this->last = NULL;
}

void LateralList::insert(int x){
    NodeLateral *newNode = new NodeLateral(x);
    if(first != NULL){
        if(newNode->getX() < first->getX()){
            insertinFront(newNode);
        }else if(newNode->getX() > last->getX()){
            insertinEnd(newNode);
        }else{
            insertinMedium(newNode);
        }
    }else{
        first = newNode;
        last = first;
    }
}

void LateralList::insertinFront(NodeLateral* newNode){
    newNode->setDown(first);
    first->setUp(newNode);
    first = newNode;
}

void LateralList::insertinEnd(NodeLateral* newNode){
    newNode->setUp(last);
    last->setDown(newNode);
    last = newNode;
}

void LateralList::insertinMedium(NodeLateral* newNode){
    NodeLateral *tmp = first;
    NodeLateral *tmp2;
    while(tmp->getX() < newNode->getX()){
        tmp = tmp->getDown();
    }
    tmp2 = tmp->getUp();
    newNode->setDown(tmp);
    newNode->setUp(tmp2);
    tmp2->setDown(newNode);
    tmp->setUp(newNode);
}

bool LateralList::existLateral(int x){
    if(first != NULL){
        NodeLateral *tmp = first;
        while(tmp != NULL){
            if(tmp->getX() == x){
                return true;
            }
            tmp = tmp->getDown();
        }
        return false;
    }else{
        return false;
    }
}

NodeLateral* LateralList::searchLateral(int x){
    if(existLateral(x)){
        NodeLateral *tmp = first;
        while(tmp->getX() != x){
            tmp = tmp->getDown();
        }
        return tmp;
    }else{
        return new NodeLateral(x);
    }
}
