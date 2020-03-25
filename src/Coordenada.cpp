#include "Coordenada.h"
#include <iostream>

using namespace std;
Coordenada::Coordenada(int _x, int _y, std::string _valor)
{
    this->x =_x;
    this->y = _y;
    this->valor = _valor;
}

int Coordenada::getX(){
    return this->x;
}
int Coordenada::getY(){
    return this->y;
}
std::string Coordenada::getValor(){
    return this->valor;
}

void Coordenada::setX(int nuevo_x){
    this->x = nuevo_x;
}
void Coordenada::setY(int nuevo_y){
    this->y = nuevo_y;
}
void Coordenada::setValor(std::string nuevo_valor){
    this->valor = nuevo_valor;
}

