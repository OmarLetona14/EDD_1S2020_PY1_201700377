
#ifndef HEADERLIST_H
#define HEADERLIST_H

#include "NodeHeader.h"

class HeaderList {
public:
    NodeHeader *first;
    NodeHeader *last;
    HeaderList();
    void insert(int);
    void insertinFront(NodeHeader* newNode);
    void insertinEnd(NodeHeader* newNode);
    void insertinMedium(NodeHeader* newNode);
    bool existHeader(int);
    NodeHeader* searchHeader(int);

};

#endif /* HEADERLIST_H */
