#include "NodeMatrix.h"

NodeMatrix::NodeMatrix(std::string color, int x, int y){
    this->color = color;
    this->x = x;
    this->y = y;
    this->up = NULL;
    this->down = NULL;
    this->next = NULL;
    this->previous = NULL;
}

void NodeMatrix::setColor(std::string color){
    this->color = color;
}

void NodeMatrix::setDown(NodeMatrix* down){
    this->down = down;
}

void NodeMatrix::setNext(NodeMatrix* next){
    this->next = next;
}

void NodeMatrix::setUp(NodeMatrix* up){
    this->up = up;
}

void NodeMatrix::setPrevious(NodeMatrix* previous){
    this->previous = previous;
}

std::string NodeMatrix::getColor(){
    return this->color;
}

NodeMatrix* NodeMatrix::getDown(){
    return this->down;
}

NodeMatrix* NodeMatrix::getUp(){
    return this->up;
}

NodeMatrix* NodeMatrix::getNext(){
    return this->next;
}

NodeMatrix* NodeMatrix::getPrevious(){
    return this->previous;
}
