#include "Ficha.h"

Ficha::Ficha(int _noFicha, int _puntaje, char _letra)
{
    this->noFicha = _noFicha;
    this->letra = _letra;
    this->puntaje = _puntaje;
}

int getNoFicha(){
    return this->noFicha;
}
int getPuntaje(){
    return this->puntaje;
}
char getLetra(){
    return this->letra;
}

void setNoFicha(int nFicha){
    this->noFicha = nFicha;
}

void setLetra(char l){
    this->letra = l;
}

void setPuntaje(int p){
    this->puntaje = p;
}
