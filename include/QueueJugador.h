#ifndef QUEUEJUGADOR_H
#define QUEUEJUGADOR_H
#include "Jugador.h"
#include "NodeJugador.h"
class QueueJugador
{
    public:
        int size;
        void push(Jugador*);
        void pop();
        void desplegarCola();
        NodeJugador *primero;
        NodeJugador *ultimo;
        bool exists(Jugador*);
        int getSize();
        QueueJugador();

    protected:

    private:
};

#endif // QUEUEJUGADOR_H
