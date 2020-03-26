#ifndef TREEABB_H
#define TREEABB_H
#include "NodeABB.h"
#include "Matrix.h"
#include <vector>
#include <iterator>
#include <iostream>

class TreeABB {
public:
    NodeABB *root;
    TreeABB();
    void insert(NodeABB *&root, Jugador*);
    int preOrden(NodeABB *, int, int, std::vector<Matrix>&);
    int inOrden(NodeABB *, int, int, std::vector<Matrix>&);
    int PostOrden(NodeABB *, int, int, std::vector<Matrix>&);
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
};

#endif /* TREEABB_H */
