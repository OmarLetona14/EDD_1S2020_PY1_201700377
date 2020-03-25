#include "ColaFicha.h"
#include "Ficha.h"
ColaFicha::ColaFicha()
{
    this->primero =NULL;
    this->ultimo = NULL;
}

void ColaFicha::push(Ficha *ficha){
    NodeFicha nuevo = new NodeFicha(ficha);

}
