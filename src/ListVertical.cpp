#include "ListVertical.h"
#include <string>
#include <sstream>

ListVertical::ListVertical(){
    this->first = NULL;
    this->last = NULL;
}

void ListVertical::insert(std::string color, int x, int y){
    NodeMatrix *newNode = new NodeMatrix(color, x, y);
    if(first != NULL){
        if(newNode->x < first->x){
            insertinFront(newNode);
        }else if(newNode->x > last->x){
            insertinEnd(newNode);
        }else{
            insertinMedium(newNode);
        }
    }else{
        first = newNode;
        last = first;
    }
}

void ListVertical::insertinFront(NodeMatrix* newNode){
    first->setUp(newNode);
    newNode->setDown(first);
    first = newNode;
}

void ListVertical::insertinEnd(NodeMatrix* newNode){
    last->setDown(newNode);
    newNode->setUp(last);
    last = newNode;
}

void ListVertical::insertinMedium(NodeMatrix* newNode){
    NodeMatrix *tmp = first;
    NodeMatrix *tmp2;
    while(tmp->x < newNode->x){
        tmp = tmp->getDown();
    }
    tmp2 = tmp->getUp();
    if(tmp2 != NULL){
        tmp2->setDown(newNode);
        tmp->setUp(newNode);
        newNode->setDown(tmp);
        newNode->setUp(tmp2);
    }else{
//       std::cout << "Coordenada " + patch::to_string(tmp->x) + ", " + patch::to_string(tmp->y) + " repetida" << std::endl;
    }
}
