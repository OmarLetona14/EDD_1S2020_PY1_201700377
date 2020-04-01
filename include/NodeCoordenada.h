#ifndef NODECOORDENADA_H
#define NODECOORDENADA_H
#include "Coordenada.h"
class NodeCoordenada
{
    public:
        NodeCoordenada(Coordenada*);
        Coordenada *coordenada;
        NodeCoordenada *siguiente;
        NodeCoordenada *anterior;

    protected:

    private:
};

#endif // NODECOORDENADA_H
