#include "NodeHeader.h"

NodeHeader::NodeHeader(int y){
    this->y = y;
    this->next = NULL;
    this->previous = NULL;
}

void NodeHeader::setY(int y){
    this->y = y;
}

void NodeHeader::setPrevious(NodeHeader* previous){
    this->previous = previous;
}

void NodeHeader::setNext(NodeHeader* next){
    this->next = next;
}

int NodeHeader::getY(){
    return this->y;
}

NodeHeader* NodeHeader::getPrevious(){
    return this->previous;
}

NodeHeader* NodeHeader::getNext(){
    return this->next;
}
