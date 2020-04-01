#include "NodeCoordenada.h"
#include "Coordenada.h"
NodeCoordenada::NodeCoordenada(Coordenada *_coordenada)
{
    this->coordenada = _coordenada;
    this->siguiente = NULL;
    this->anterior = NULL;
}
