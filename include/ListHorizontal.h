#ifndef LISTHORIZONTAL_H
#define LISTHORIZONTAL_H
#include <iostream>
#include "NodeMatrix.h"

class ListHorizontal {
public:
    NodeMatrix *first;
    NodeMatrix *last;
    ListHorizontal();
    void insert(std::string, int, int);
    void insertinFront(NodeMatrix*);
    void insertinEnd(NodeMatrix*);
    void insertinMedium(NodeMatrix*);

};

#endif /* LISTHORIZONTAL_H */
