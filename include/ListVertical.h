#ifndef LISTVERTICAL_H
#define LISTVERTICAL_H

#include "NodeMatrix.h"
#include <iostream>
#include <string>

class ListVertical {
public:
    NodeMatrix *first;
    NodeMatrix *last;
    ListVertical();
    void insert(std::string, int, int);
    void insertinFront(NodeMatrix*);
    void insertinEnd(NodeMatrix*);
    void insertinMedium(NodeMatrix*);

};

#endif /* LISTVERTICAL_H */
