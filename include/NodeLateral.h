
#ifndef NODELATERAL_H
#define NODELATERAL_H

#include "ListHorizontal.h"

class NodeLateral {
private:
    int x;
    NodeLateral *down;
    NodeLateral *up;
public:
    NodeLateral(int);
    void setDown(NodeLateral*);
    void setUp(NodeLateral*);
    void setX(int);
    int getX();
    NodeLateral* getDown();
    NodeLateral* getUp();
    ListHorizontal row;

};

#endif /* NODELATERAL_H */
