#include "SimplyLinkedListCoordenada.h"
#include "Coordenada.h"
#include "NodeCoordenada.h"
SimplyLinkedListCoordenada::SimplyLinkedListCoordenada()
{
    this->size = 0;
    this->primero = NULL;
    this->ultimo = NULL;
}

void SimplyLinkedListCoordenada::insertar(Coordenada *coordenada){
    NodeCoordenada *nuevo = new NodeCoordenada(coordenada);
    if(primero == NULL){
        primero = nuevo;
        nuevo->siguiente = NULL;
        ultimo = nuevo;
    }else {
        ultimo->siguiente = nuevo;
        nuevo->siguiente = nullptr;
        ultimo = nuevo;
    }
}

int SimplyLinkedListCoordenada::getSize(){
    return this->size;
}

bool SimplyLinkedListCoordenada::isDouble(int _x, int _y){
    NodeCoordenada *aux = primero;
    if(primero!=nullptr){
        while(aux!=nullptr){
            if(aux->coordenada->getX() == _x){
                if(aux->coordenada->getY() == _y){
                    if(aux->coordenada->getValor() == "doble"){
                        return true;
                    }
                }
            }
            aux = aux->siguiente;
        }
    }return false;
}

bool SimplyLinkedListCoordenada::isTriple(int _x, int _y){
    NodeCoordenada *aux = primero;
    if(primero!=nullptr){
        while(aux!=nullptr){
            if(aux->coordenada->getX() == _x){
                if(aux->coordenada->getY() == _y){
                    if(aux->coordenada->getValor() == "triple"){
                        return true;
                    }
                }
            }
            aux = aux->siguiente;
        }
    }return false;
}
