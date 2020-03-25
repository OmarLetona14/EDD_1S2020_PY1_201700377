#ifndef LATERALLIST_H
#define LATERALLIST_H

#include "NodeLateral.h"

class LateralList {
public:
    NodeLateral *first;
    NodeLateral *last;
    LateralList();
    void insert(int);
    void insertinFront(NodeLateral* newNode);
    void insertinEnd(NodeLateral* newNode);
    void insertinMedium(NodeLateral* newNode);
    bool existLateral(int);
    NodeLateral* searchLateral(int);

};

#endif /* LATERALLIST_H */
