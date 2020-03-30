#include "NodeJugador.h"

NodeJugador::NodeJugador(Jugador *jugador)
{
    this->jugador = jugador;
    this->siguiente = nullptr;
    this->anterior = nullptr;
}
