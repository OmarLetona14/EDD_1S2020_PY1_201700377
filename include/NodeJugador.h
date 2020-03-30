#ifndef NODEJUGADOR_H
#define NODEJUGADOR_H
#include "Jugador.h"

class NodeJugador
{
    public:
        Jugador *jugador;
        NodeJugador(Jugador*);
        NodeJugador *siguiente;
        NodeJugador *anterior;

    protected:

    private:
};

#endif // NODEJUGADOR_H
