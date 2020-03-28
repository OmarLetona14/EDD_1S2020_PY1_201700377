#ifndef NODEMATRIX_H
#define NODEMATRIX_H

#include <string>
#include <cstddef>
#include "Ficha.h"
class NodeMatrix {
private:
    Ficha *ficha;
    NodeMatrix *up;
    NodeMatrix *down;
    NodeMatrix *next;
    NodeMatrix *previous;
public:
    int x;
    int y;
    NodeMatrix(Ficha*, int , int);
    void setFicha(Ficha*);
    void setUp(NodeMatrix*);
    void setDown(NodeMatrix*);
    void setNext(NodeMatrix*);
    void setPrevious(NodeMatrix*);
    Ficha* getFicha();
    NodeMatrix* getUp();
    NodeMatrix* getDown();
    NodeMatrix* getNext();
    NodeMatrix* getPrevious();

};

#endif /* NODEMATRIX_H */
