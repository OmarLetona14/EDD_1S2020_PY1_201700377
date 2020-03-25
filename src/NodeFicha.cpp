#include "NodeFicha.h"
#include "Ficha.h"

NodeFicha::NodeFicha(Ficha *nueva_ficha)
{
    this->ficha = nueva_ficha;
    this->siguiente = NULL;
}
