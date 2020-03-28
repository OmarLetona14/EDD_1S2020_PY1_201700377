#include "Matrix.h"
#include "Ficha.h"

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

Ficha* Matrix::ExistFicha(int x, int y){
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
