#ifndef DOUBLELINKEDLISTSCOREBOARD_H
#define DOUBLELINKEDLISTSCOREBOARD_H
#include "Score.h"
#include "NodeScore.h"

class DoubleLinkedListScoreboard
{
    public:
        DoubleLinkedListScoreboard();
        void insertar(Score*);
        int getSize();
        NodeScore *primero;
        NodeScore *ultimo;
        int size;
    protected:

    private:
};

#endif // DOUBLELINKEDLISTSCOREBOARD_H
