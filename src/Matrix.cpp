#include "Matrix.h"
#include "Ficha.h"
#include <fstream>
#include <iostream>
#include "NodeHeader.h"
#include "Matrix.h"
#include "HeaderList.h"
#include "NodeLateral.h"
#include "CreateFile.h"
using namespace std;

Matrix::Matrix(){
}

void Matrix::insert(int x, int y, Ficha *ficha){
    if(header.existHeader(y) == false){
        header.insert(y);
    }
    if(lateral.existLateral(x) == false){
        lateral.insert(x);
    }
    NodeHeader *tmpH;
    NodeLateral *tmpL;
    tmpH = header.searchHeader(y);
    tmpL = lateral.searchLateral(x);
    tmpH->column.insert(ficha, x, y);
    tmpL->row.insert(ficha, x, y);
}

std::string Matrix::ExistsFicha(int x, int y){
    if(lateral.existLateral(x) && header.existHeader(y)){
        NodeLateral *node = lateral.searchLateral(x);
        NodeMatrix *tmp = node->row.first;
        while(tmp != NULL){
            if(tmp->x == x && tmp->y == y){
                std::string letra(1, tmp->getFicha()->getLetra());
                return letra;
            }
            tmp = tmp->getNext();
        }
    }
    return "";
}

int Matrix::MaximunHeader(){
    int m = 0;
    NodeHeader *tmp = header.first;
    while(tmp != NULL){
        m = tmp->getY();
        tmp = tmp->getNext();
    }
    return m;
}

int Matrix::MaximunLateral(){
    int l = 0;
    NodeLateral *tmp = lateral.first;
    while(tmp != NULL){
        l = tmp->getX();
        tmp = tmp->getDown();
    }
    return l;
}

Ficha* Matrix::getFicha(int x, int y){
    if(lateral.existLateral(x) && header.existHeader(y)){
        NodeLateral *node = lateral.searchLateral(x);
        NodeMatrix *tmp = node->row.first;
        while(tmp != NULL){
            if(tmp->x == x && tmp->y == y){
                return tmp->getFicha();
            }
            tmp = tmp->getNext();
        }
    }
    return nullptr;
}

void Matrix::createImage(Matrix *matrix){
    creator = new CreateFile();
    std::string contenido;
    ofstream fs("tablero.dot");
    contenido += "digraph tablero{ \n";
    contenido += "node [shape= record] \n";
    contenido += "mt [label= \" matriz\" group = 0 ];\n ";
    NodeLateral *auxLateral = matrix->lateral.first;
    while(auxLateral!=nullptr){
        contenido += "x" + std::to_string(auxLateral->getX()) + "[label = \" " + std::to_string(auxLateral->getX()) + "\" group = 0 ];\n";
        auxLateral = auxLateral->getDown();
    }
    auxLateral = matrix->lateral.first;
    contenido+= "mt -> x0 \n";
    while(auxLateral!=nullptr){
        if(auxLateral->getDown()!=nullptr){
            contenido += "x" + std::to_string(auxLateral->getX()) + " -> x" + std::to_string(auxLateral->getDown()->getX()) + "\n";
        }
        auxLateral = auxLateral->getDown();
    }
    int contador= 1;
    NodeHeader *auxHeader = matrix->header.first;
    while(auxHeader!=nullptr){
        contenido += "y"+std::to_string(auxHeader->getY()) + "[label = \" " + std::to_string(auxHeader->getY()) +
         "\" group = "+ std::to_string(contador) +" ]; \n";
         contador++;
        auxHeader = auxHeader->getNext();
    }
    auxHeader = matrix->header.first;
    contenido += "mt -> y0 \n";
    while(auxHeader!=nullptr){
        if(auxHeader->getNext()!=nullptr){
            contenido += "y"+ std::to_string(auxHeader->getY())+ " -> y" + std::to_string(auxHeader->getNext()->getY()) + " \n";
        }
        auxHeader = auxHeader->getNext();
    }
    contenido += "{rank = same; mt; ";
    auxHeader = matrix->header.first;
    while(auxHeader!=nullptr){
        contenido += "y"+std::to_string(auxHeader->getY())+ ";";
        auxHeader = auxHeader->getNext();
    }
    contenido += "}; \n";
    auxLateral = matrix->lateral.first;
    while(auxLateral!=nullptr){
        NodeMatrix *auxMatrix = auxLateral->row.first;
        while(auxMatrix!=nullptr){
            if(auxMatrix->getFicha()!=nullptr){
                std::string letra(1, auxMatrix->getFicha()->getLetra());
                int grupo = auxMatrix->y+1;
                contenido += "x"+ std::to_string(auxMatrix->x) + "y" + std::to_string(auxMatrix->y) + " [label = \" " + letra +
                 "\" group = " + std::to_string(grupo) + " ]; \n";
            }else{
                int grupo = auxMatrix->y+1;
                contenido += "x"+ std::to_string(auxMatrix->x) + "y" + std::to_string(auxMatrix->y) +
                 " [label = \" null \" group = " + std::to_string(grupo) + " ]; \n";
            }
            auxMatrix = auxMatrix->getNext();
        }
        auxLateral =auxLateral->getDown();
    }
    auxLateral = matrix->lateral.first;
    while(auxLateral!=nullptr){
        NodeMatrix *auxMatrix = auxLateral->row.first;
        while(auxMatrix!=nullptr){
            if(auxMatrix->getNext()!=nullptr){
                contenido += "x" + std::to_string(auxMatrix->x) + "y" + std::to_string(auxMatrix->y) +
                " -> x"+ std::to_string(auxMatrix->getNext()->x) + "y" + std::to_string(auxMatrix->getNext()->y) + " \n";
            }
            if(auxMatrix->getPrevious()!=nullptr){
                contenido += "x" + std::to_string(auxMatrix->x) + "y" + std::to_string(auxMatrix->y) +
                " -> x"+ std::to_string(auxMatrix->getPrevious()->x) + "y" + std::to_string(auxMatrix->getPrevious()->y) + " \n";
            }
            auxMatrix = auxMatrix->getNext();
        }
        auxLateral = auxLateral->getDown();
    }
    auxHeader = matrix->header.first;
    while(auxHeader!=nullptr){
        NodeMatrix *auxMatrix = auxHeader->column.first;
        while(auxMatrix!=nullptr){
            if(auxMatrix->getDown()!=nullptr){
                contenido += "x" + std::to_string(auxMatrix->x) + "y" + std::to_string(auxMatrix->y) + "-> x"+
                std::to_string(auxMatrix->getDown()->x) + "y" + std::to_string(auxMatrix->getDown()->y) + " \n ";
            }
            if(auxMatrix->getUp()!=nullptr){
                contenido += "x" + std::to_string(auxMatrix->x) + "y" + std::to_string(auxMatrix->y) + "-> x"+
                std::to_string(auxMatrix->getUp()->x) + "y" + std::to_string(auxMatrix->getUp()->y) + " \n ";
            }
            auxMatrix = auxMatrix->getDown();
        }
        auxHeader = auxHeader->getNext();
    }
    auxLateral = matrix->lateral.first;
    while(auxLateral!=nullptr){
        contenido += "x" + std::to_string(auxLateral->x) + " -> x" + std::to_string(auxLateral->row.first->x) +
        "y" +  std::to_string(auxLateral->row.first->y) + "\n";
        auxLateral = auxLateral->getDown();
    }
    auxHeader = matrix->header.first;
    while(auxHeader!=nullptr){
        contenido += "y" + std::to_string(auxHeader->y) + " -> x" + std::to_string(auxHeader->column.first->x) +  "y"+
        std::to_string(auxHeader->column.first->y) + " \n ";
        auxHeader = auxHeader->getNext();
    }
    auxLateral = matrix->lateral.first;
    while(auxLateral!=nullptr){
        contenido += "{ rank = same; x" + std::to_string(auxLateral->getX()) + "; ";
        NodeMatrix *auxMatrix =  auxLateral->row.first;
        while(auxMatrix!=nullptr){
            contenido += "x" + std::to_string(auxMatrix->x) + "y" + std::to_string(auxMatrix->y) + "; \n";
            auxMatrix = auxMatrix->getNext();
        }
        contenido += "}\n";
        auxLateral = auxLateral->getDown();
    }

    contenido += "}";
    fs << contenido;
    fs.close();
    creator->create("tablero.dot", "tablero.png");
}



