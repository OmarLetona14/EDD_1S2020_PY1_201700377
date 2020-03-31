#ifndef NODEHEADER_H
#define NODEHEADER_H

#include "ListVertical.h"
#include <cstddef>

class NodeHeader {
private:

    NodeHeader *next;
    NodeHeader *previous;
public:
    int y;
    NodeHeader(int);
    void setY(int);
    void setNext(NodeHeader*);
    void setPrevious(NodeHeader*);
    int getY();
    NodeHeader* getNext();
    NodeHeader* getPrevious();
    ListVertical column;

};

#endif /* NODEHEADER_H */
