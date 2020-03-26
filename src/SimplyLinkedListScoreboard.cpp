#include "SimplyLinkedListScoreboard.h"
#include "NodeScore.h"

SimplyLinkedListScoreboard::SimplyLinkedListScoreboard()
{
    this->size = 0;
    this->primero = NULL;
    this->ultimo = NULL;
}

void SimplyLinkedListScoreboard::insertar(Score *score){
    NodeScore *nuevo = new NodeScore(score);
    if(primero == NULL){
        primero = nuevo;
        nuevo->siguiente = NULL;
        ultimo = nuevo;
    }else {
        NodeScore *aux = primero;
        NodeScore *aux1;

        while((aux!=NULL) && (aux->score->getPuntaje() < nuevo->score->getPuntaje())){
            aux1 = aux;
            aux = aux->siguiente;
        }
        if(primero==aux1){
            primero = nuevo;

        }else{
            aux1->siguiente = nuevo;
        }
        nuevo->siguiente = aux;
    }
}

void SimplyLinkedListScoreboard::mostrarLista(){
    NodeScore *aux = primero;
    if(aux!=NULL){
        while(aux!=NULL){
        cout << "Jugador: " +aux->score->getNombreJugador() + " Puntuacion: " +
        std::to_string(aux->score->getPuntaje());
        aux = aux->siguiente;
        }
    }else{
        cout<<"Lista vacia" <<endl;
    }
}

SimplyLinkedListScoreboard* SimplyLinkedListScoreboard::devolverPrimerosCinco(){
    SimplyLinkedListScoreboard *scoreboard = new SimplyLinkedListScoreboard();
    NodeScore *aux = primero;
    int contador = 0;
    if(aux!=NULL){
        while(aux!=NULL || contador <=5){
        scoreboard->insertar(aux->score);
        contador++;
        aux = aux->siguiente;
        }
    }else{
        cout<<"Lista vacia" <<endl;
    }
    return scoreboard;
}
