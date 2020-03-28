#ifndef LISTHORIZONTAL_H
#define LISTHORIZONTAL_H
#include <iostream>
#include "NodeMatrix.h"
#include "Ficha.h"
class ListHorizontal {
public:
    NodeMatrix *first;
    NodeMatrix *last;
    ListHorizontal();
    void insert(Ficha*, int, int);
    void insertinFront(NodeMatrix*);
    void insertinEnd(NodeMatrix*);
    void insertinMedium(NodeMatrix*);

};

#endif /* LISTHORIZONTAL_H */
