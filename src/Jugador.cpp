#include "Jugador.h"
#include "SimplyLinkedListScoreboard.h"
#include "DoubleLinkedListFicha.h"
#include <iostream>
using namespace std;

Jugador::Jugador(int noJugador, std::string nombre_jugador)
{
    this->noJugador = noJugador;
    this->nombre_jugador = nombre_jugador;
    this->puntaje =0;
    this->puntajes = new SimplyLinkedListScoreboard();
    this->fichas = new DoubleLinkedListFicha();
}

int Jugador::getNoJugador(){
    return this->noJugador;
}

std::string Jugador::getNombreJugador(){
    return this->nombre_jugador;
}

int Jugador::getPuntaje(){
    return this->puntaje;
}

SimplyLinkedListScoreboard* Jugador::getPuntajes(){
    return this->puntajes;
}

DoubleLinkedListFicha* Jugador::getFichas(){
    return this->fichas;
}

void Jugador::setNoJugador(int nJ){
    this->noJugador = nJ;
}

void Jugador::setNombreJugador(std::string n){
    this->nombre_jugador = n;
}
void Jugador::setPuntaje(int p){
    this->puntaje =  p;
}
void Jugador::setPuntajes(SimplyLinkedListScoreboard *pt){
    this->puntajes = pt;
}
void Jugador::setFichas(DoubleLinkedListFicha *f){
    this->fichas = f;
}

