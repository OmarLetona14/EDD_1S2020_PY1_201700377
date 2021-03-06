#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>
#include "ColaFicha.h"
#include "SimplyLinkedListScoreboard.h"
#include "DoubleLinkedListFicha.h"

using namespace std;
class Jugador
{
    public:
        DoubleLinkedListFicha *fichas;
        Jugador(int, std::string, int);
        std::string nombre_jugador;
        Jugador();
        int puntaje, noJugador, primera_letra;
        SimplyLinkedListScoreboard *puntajes;

        int getNoJugador();
        int getPuntaje();
        std::string getNombreJugador();
        int getPrimeraLetra();
        SimplyLinkedListScoreboard* getPuntajes();
        DoubleLinkedListFicha* getFichas();
        void setNoJugador(int);
        void setNombreJugador(std::string);
        void setPuntaje(int);
        void setPrimeraLetra(int);
        void setFichas(DoubleLinkedListFicha*);
        void setPuntajes(SimplyLinkedListScoreboard*);
    protected:

    private:
};

#endif // JUGADOR_H
