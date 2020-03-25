#include "HeaderList.h"

HeaderList::HeaderList(){
    this->first = NULL;
    this->last = NULL;
}

void HeaderList::insert(int y){
    NodeHeader *newNode = new NodeHeader(y);
    if(first != NULL){
        if(newNode->getY() < first->getY()){
            insertinFront(newNode);
        }else if(newNode->getY() > last->getY()){
            insertinEnd(newNode);
        }else{
            insertinMedium(newNode);
        }
    }else{
        first = newNode;
        last = first;
    }
}

void HeaderList::insertinFront(NodeHeader* newNode){
    newNode->setNext(first);
    first->setPrevious(newNode);
    first = newNode;
}

void HeaderList::insertinEnd(NodeHeader* newNode){
    newNode->setPrevious(last);
    last->setNext(newNode);
    last = newNode;
}

void HeaderList::insertinMedium(NodeHeader* newNode){
    NodeHeader *tmp = first;
    NodeHeader *tmp2;
    while(tmp->getY() < newNode->getY()){
        tmp = tmp->getNext();
    }
    tmp2 = tmp->getPrevious();
    newNode->setNext(tmp);
    newNode->setPrevious(tmp2);
    tmp2->setNext(newNode);
    tmp->setPrevious(newNode);
}

bool HeaderList::existHeader(int y){
    if(first != NULL){
        NodeHeader *tmp = first;
        while(tmp != NULL){
            if(tmp->getY() == y){
                return true;
            }
            tmp = tmp->getNext();
        }
        return false;
    }else{
        return false;
    }
}

NodeHeader* HeaderList::searchHeader(int y){
    if(existHeader(y)){
        NodeHeader *tmp = first;
        while(tmp->getY() != y){
            tmp = tmp->getNext();
        }
        return tmp;
    }else{
        return new NodeHeader(y);
    }
}
