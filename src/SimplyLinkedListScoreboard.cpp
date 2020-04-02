#include "SimplyLinkedListScoreboard.h"
#include "NodeScore.h"
#include <fstream>
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

Score* SimplyLinkedListScoreboard::devolverMejorPuntaje(){
    if(primero!=NULL && ultimo!=NULL){
        return ultimo->score;
    }else{
        return NULL;
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
    if(scoreboard->getSize()==0){
        return NULL;
    }else{
        return scoreboard;
    }
}

int SimplyLinkedListScoreboard::getSize(){
    return this->size;
}


void SimplyLinkedListScoreboard::createDOT(std::string nombre_jugador){
    std::string filename = "Puntajes" + nombre_jugador;
    creator = new CreateFile();
    std::string contenido;
    ofstream fs(filename + ".dot");
    NodeScore* aux = primero;
    contenido += "digraph " + filename + "{ \n";
    contenido += "node [ fontsize = 16 shape = record] \n";
    do{
    std::string cont = "";
            cont += " \" " + aux->score->getNombreJugador() + std::to_string(aux->score->getPuntaje()) +
             "\" [ label = \" "+ std::to_string(aux->score->getPuntaje()) + "\" shape = record ]; \n";
            if(aux->siguiente!=nullptr){
                cont +=  " \" " + aux->score->getNombreJugador() + std::to_string(aux->score->getPuntaje()) + "\"" + " -> " +" \" " +
                aux->siguiente->score->getNombreJugador() +
                std::to_string(aux->siguiente->score->getPuntaje()) + "\"  \n";
            }
        contenido.append(cont);
        aux = aux->siguiente;
    }while(aux!=nullptr);
    contenido += "}";
    fs << contenido;
    fs.close();
    creator->create(filename + ".dot", filename + ".png");

}
