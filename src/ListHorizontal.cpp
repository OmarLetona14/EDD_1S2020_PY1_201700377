#include "ListHorizontal.h"
#include <sstream>
#include <string>
#include <iostream>

ListHorizontal::ListHorizontal(){
    this->first = NULL;
    this->last = NULL;
}

void ListHorizontal::insert(std::string color, int x, int y){
    NodeMatrix *newNode = new NodeMatrix(color, x, y);
    if(first != NULL){
        if(newNode->y < first->y){
            insertinFront(newNode);
        }else if(newNode->y > last->y){
            insertinEnd(newNode);
        }else{
            insertinMedium(newNode);
        }
    }else{
        first = newNode;
        last = first;
    }
}

void ListHorizontal::insertinFront(NodeMatrix* newNode){
    first->setPrevious(newNode);
    newNode->setNext(first);
    first = newNode;
}

void ListHorizontal::insertinEnd(NodeMatrix* newNode){
    last->setNext(newNode);
    newNode->setPrevious(last);
    last = newNode;
}

void ListHorizontal::insertinMedium(NodeMatrix* newNode){
    NodeMatrix *tmp = first;
    NodeMatrix *tmp2;
    while(tmp->y < newNode->y){
        tmp = tmp->getNext();
    }
    tmp2 = tmp->getPrevious();
    if(tmp2 != NULL){
        tmp2->setNext(newNode);
        tmp->setPrevious(newNode);
        newNode->setNext(tmp);
        newNode->setPrevious(tmp2);
    }else{
     //  std::cout << "Coordenada " + std::to_string(tmp->x) + ", " + std::to_string(tmp->y) + " repetida" << std::endl;
    }
}
