#ifndef NODEABB_H
#define NODEABB_H
#include "Jugador.h"
#include <cstddef>

class NodeABB {
private:
    Jugador *data;

public:
    NodeABB *right;
    NodeABB *left;
    NodeABB(Jugador*);
    void setData(Jugador*);
    void setRight(NodeABB*);
    void setLeft(NodeABB*);
    Jugador* getData();
    NodeABB* getLeft();
    NodeABB* getRight();
};

#endif /* NODEABB_H */

