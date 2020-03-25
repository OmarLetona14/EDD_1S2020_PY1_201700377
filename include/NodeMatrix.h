#ifndef NODEMATRIX_H
#define NODEMATRIX_H

#include <string>
#include <cstddef>

class NodeMatrix {
private:
    std::string color;
    NodeMatrix *up;
    NodeMatrix *down;
    NodeMatrix *next;
    NodeMatrix *previous;
public:
    int x;
    int y;
    NodeMatrix(std::string, int , int);
    void setColor(std::string);
    void setUp(NodeMatrix*);
    void setDown(NodeMatrix*);
    void setNext(NodeMatrix*);
    void setPrevious(NodeMatrix*);
    std::string getColor();
    NodeMatrix* getUp();
    NodeMatrix* getDown();
    NodeMatrix* getNext();
    NodeMatrix* getPrevious();

};

#endif /* NODEMATRIX_H */
