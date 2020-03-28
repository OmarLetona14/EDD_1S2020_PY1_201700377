#ifndef TREEABB_H
#define TREEABB_H
#include "NodeABB.h"
#include "Matrix.h"
#include <vector>
#include <iterator>
#include <iostream>
#include "CreateFile.h"
class TreeABB {
public:
    int iteracion=0, size;
    CreateFile *creator;
    TreeABB();
    void insert(NodeABB *&root, Jugador*);
    int preOrden(NodeABB *, int, int, std::vector<Matrix>&);
    int inOrden(NodeABB *, int, int, std::vector<Matrix>&);
    int PostOrden(NodeABB *, int, int, std::vector<Matrix>&);
    int getSize();
    NodeABB* searchNode(int, NodeABB*, NodeABB*);
    std::vector<Matrix> GenerateImgPre(int);
    std::vector<Matrix> GenerateImgIn(int);
    std::vector<Matrix> GenerateImgPost(int);
    Matrix GenerateMatrix(NodeABB*);
    void LeafNodes(NodeABB*);
    int TreeDepth(NodeABB*);
    void ReportPre(NodeABB*);
    void ReportIn(NodeABB*);
    void ReportPost(NodeABB*);
    void GraphABB(NodeABB*);
    void createDOT(std::string, std::string, NodeABB*);
    std::string Branch(NodeABB*,std::string);
    std::string Children(NodeABB*,std::string);
    std::string contenido;
};

#endif /* TREEABB_H */
