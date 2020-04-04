#include "Ficha.h"

Ficha::Ficha(int noFicha, char letra)
{
    this->noFicha = noFicha;
    this->letra = letra;
    this->puntaje = 0;
    this->doble = false;
    this->triple = false;
}

int Ficha::getPosicionX(){
    return this->posicion_x;
}

int Ficha::getPosicionY(){
    return this->posicion_y;
}

int Ficha::getNoFicha(){
    return this->noFicha;
}
int Ficha::getPuntaje(){
    return this->puntaje;
}
char Ficha::getLetra(){
    return this->letra;
}

bool Ficha::getDoble(){
    return this->doble;
}

bool Ficha::getTriple(){
    return this->triple;
}

void Ficha::setNoFicha(int nFicha){
    this->noFicha = nFicha;
}

void Ficha::setLetra(char l){
    this->letra = l;
}

void Ficha::setPuntaje(int p){
    this->puntaje = p;
}

void Ficha::setDoble(bool v){
    this->doble =v;
}

void Ficha::setTriple(bool t){
    this->triple = t;
}

void Ficha::setPosicionX(int _x){
    this->posicion_x = _x;
}
void Ficha::setPosicionY(int _y){
    this->posicion_y = _y;
}
