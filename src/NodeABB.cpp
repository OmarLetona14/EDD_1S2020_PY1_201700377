#include "NodeABB.h"
#include "Jugador.h"

NodeABB::NodeABB(Jugador *data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

void NodeABB::setData(Jugador *data){
    this->data = data;
}

void NodeABB::setRight(NodeABB* right){
    this->right = right;
}

void NodeABB::setLeft(NodeABB* left){
    this->left = left;
}

Jugador* NodeABB::getData(){
    return this->data;
}

NodeABB* NodeABB::getRight(){
    return this->right;
}

NodeABB* NodeABB::getLeft(){
    return this->left;
}
