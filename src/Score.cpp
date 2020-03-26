#include "Score.h"
#include <iostream>
using namespace std;
Score::Score(std::string nombre_jugador, int puntaje)
{
    this->nombre_jugador = nombre_jugador;
    this->puntaje = puntaje;
}

std::string Score::getNombreJugador(){
    return this->nombre_jugador;
}

int Score::getPuntaje(){
    return this->puntaje;
}

void Score::setNombreJugador(std::string nombre){
    this->nombre_jugador = nombre;
}

void Score::setPuntaje(int p){
    this->puntaje = p;
}
