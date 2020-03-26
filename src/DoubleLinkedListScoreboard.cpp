#include "DoubleLinkedListScoreboard.h"
#include "Score.h"
#include "NodeScore.h"

DoubleLinkedListScoreboard::DoubleLinkedListScoreboard()
{
    this->size = 0;
    this->primero = NULL;
    this->ultimo = NULL;
}

void DoubleLinkedListScoreboard::insertar(Score *score){
    NodeScore *nuevo = new NodeScore(score);
    if(primero==NULL){
        primero = nuevo;
        primero->siguiente = NULL;
        primero->anterior = NULL;
        ultimo = primero;
    }else{
        ultimo->siguiente =  nuevo;
        nuevo->siguiente = NULL;
        nuevo->anterior = ultimo;
        ultimo =nuevo;
    }
}
