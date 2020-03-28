#include "NodeMatrix.h"
#include "Ficha.h"
NodeMatrix::NodeMatrix(Ficha* ficha, int x, int y){
    this->ficha = ficha;
    this->x = x;
    this->y = y;
    this->up = NULL;
    this->down = NULL;
    this->next = NULL;
    this->previous = NULL;
}

void NodeMatrix::setFicha(Ficha * ficha){
    this->ficha = ficha;
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

Ficha* NodeMatrix::getFicha(){
    return this->ficha;
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
