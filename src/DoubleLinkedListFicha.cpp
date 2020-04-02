#include "DoubleLinkedListFicha.h"
#include "NodeFicha.h"
#include "Ficha.h"
#include <iostream>
#include "Jugador.h"
#include <fstream>
using namespace std;
DoubleLinkedListFicha::DoubleLinkedListFicha()
{
    this->size = 0;
    this->primero = NULL;
    this->ultimo = NULL;
}

void DoubleLinkedListFicha::insertar(Ficha* ficha){
    NodeFicha *nuevo = new NodeFicha(ficha);
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

NodeFicha* DoubleLinkedListFicha::buscarNodo(Ficha *ficha, int posicion){
    NodeFicha *aux = primero;
    int contador;
    if(aux!=NULL){
       while(aux!=NULL){
            if(aux->ficha == ficha && contador==posicion){
                return aux;
            }else{
            contador++;
            aux = aux->siguiente;
            }
        }
    }else{
        cout<<"Lista vacia"<<endl;
    }
    return NULL;
}

Ficha* DoubleLinkedListFicha::getFicha(char letra){
    NodeFicha *aux = primero;
    if(aux!=nullptr){
        while(aux!=nullptr){
            if(aux->ficha->getLetra() == letra){
                return aux->ficha;
            }
            aux = aux->siguiente;
        }
    }return nullptr;
}

void DoubleLinkedListFicha::createDOT(std::string filename, std::string nombre_jugador){
    creator = new CreateFile();
    std::string contenido;
    ofstream fs(filename);
    NodeFicha* aux = primero;
    contenido += "digraph Fichas" +  nombre_jugador + "{ \n";
    contenido += "node [ fontsize = 16 shape = record] \n";
    do{
    std::string cont = "";
            std::string letra(1, aux->ficha->getLetra());
            cont += " \" " + letra + std::to_string(aux->ficha->getNoFicha()) + "\" [ label = \" "+ letra + "\" shape = record ]; \n";
            if(aux->siguiente!=nullptr){
                std::string letra_siguiente( 1,aux->siguiente->ficha->getLetra());
                cont +=  " \" " + letra + std::to_string(aux->ficha->getNoFicha()) + "\"" + " -> " +" \" " +
                letra_siguiente + std::to_string(aux->siguiente->ficha->getNoFicha()) + "\"  \n";
            }
            if(aux->anterior!=nullptr){
                std::string letra_anterior(1, aux->anterior->ficha->getLetra());
                cont +=  " \" " + letra + std::to_string(aux->ficha->getNoFicha()) + "\"" + " -> " +" \" " +
                letra_anterior+ std::to_string(aux->anterior->ficha->getNoFicha()) + "\" \n";
            }
            contenido.append(cont);
        aux = aux->siguiente;
    }while(aux!=nullptr);
    contenido += "}";
    fs << contenido;
    fs.close();
    creator->create(filename, "diccionario.png");
}


void DoubleLinkedListFicha::eliminarNodo(Ficha *ficha_eliminar){
    NodeFicha *aux = primero;
    NodeFicha *ant = nullptr;
    if(primero!=nullptr){
        while(aux!=nullptr){
            if(aux->ficha == ficha_eliminar){
                if(aux==primero){
                    primero = primero->siguiente;
                    primero->anterior = nullptr;
                }else if(aux==ultimo){
                    ant->siguiente  = nullptr;
                    ultimo = ant;
                }else{
                    ant->siguiente = aux->siguiente;
                    aux->siguiente->anterior = ant;
                }
                return;
            }
            ant = aux;
            aux = aux->siguiente;
        }
    }else{
        cout<< "La lista se encuentra vacia"<<endl;
    }

}
