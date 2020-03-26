#include "Ficha.h"

Ficha::Ficha(int noFicha, char letra)
{
    this->noFicha = noFicha;
    this->letra = letra;
    this->puntaje = 0;
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

void Ficha::setNoFicha(int nFicha){
    this->noFicha = nFicha;
}

void Ficha::setLetra(char l){
    this->letra = l;
}

void Ficha::setPuntaje(int p){
    this->puntaje = p;
}
