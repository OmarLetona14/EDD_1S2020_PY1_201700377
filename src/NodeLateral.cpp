#include "NodeLateral.h"

NodeLateral::NodeLateral(int x){
    this->x = x;
    this->down = NULL;
    this->up = NULL;
}

void NodeLateral::setDown(NodeLateral* down){
    this->down = down;
}

void NodeLateral::setUp(NodeLateral* up){
    this->up = up;
}

void NodeLateral::setX(int x){
    this->x = x;
}

int NodeLateral::getX(){
    return this->x;
}

NodeLateral* NodeLateral::getDown(){
    return this->down;
}

NodeLateral* NodeLateral::getUp(){
    return this->up;
}
