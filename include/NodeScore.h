#ifndef NODESCORE_H
#define NODESCORE_H
#include "Score.h"

class NodeScore
{
    public:
        Score *score;
        NodeScore(Score*);
        NodeScore *siguiente;
        NodeScore *anterior;
    protected:

    private:
};

#endif // NODESCORE_H
