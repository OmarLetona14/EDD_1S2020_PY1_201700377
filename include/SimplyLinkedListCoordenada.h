#ifndef SIMPLYLINKEDLISTCOORDENADA_H
#define SIMPLYLINKEDLISTCOORDENADA_H
#include "Coordenada.h"
#include "NodeCoordenada.h"
class SimplyLinkedListCoordenada
{
    public:
        SimplyLinkedListCoordenada();
        void insertar(Coordenada*);
        NodeCoordenada *primero;
        NodeCoordenada *ultimo;
        int size;
        int getSize();
        bool isDouble(int, int);
        bool isTriple(int, int);
    protected:

    private:
};

#endif // SIMPLYLINKEDLISTCOORDENADA_H
