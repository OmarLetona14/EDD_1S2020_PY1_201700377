#include "Matrix.h"
#include "Ficha.h"
#include <fstream>
#include <iostream>
using namespace std;

Matrix::Matrix(){
}

void Matrix::insert(int x, int y, Ficha *ficha){
    if(header.existHeader(y) == false){
        header.insert(y);
    }
    if(lateral.existLateral(x) == false){
        lateral.insert(x);
    }
    NodeHeader *tmpH;
    NodeLateral *tmpL;
    tmpH = header.searchHeader(y);
    tmpL = lateral.searchLateral(x);
    tmpH->column.insert(ficha, x, y);
    tmpL->row.insert(ficha, x, y);
}

int Matrix::MaximunHeader(){
    int m = 0;
    NodeHeader *tmp = header.first;
    while(tmp != NULL){
        m = tmp->getY();
        tmp = tmp->getNext();
    }
    return m;
}

int Matrix::MaximunLateral(){
    int l = 0;
    NodeLateral *tmp = lateral.first;
    while(tmp != NULL){
        l = tmp->getX();
        tmp = tmp->getDown();
    }
    return l;
}

Ficha* Matrix::ExistFicha(int x, int y){
    if(lateral.existLateral(x) && header.existHeader(y)){
        NodeLateral *node = lateral.searchLateral(x);
        NodeMatrix *tmp = node->row.first;
        while(tmp != NULL){
            if(tmp->x == x && tmp->y == y){
                return tmp->getFicha();
            }
            tmp = tmp->getNext();
        }
    }
    return nullptr;
}

void Matrix::createImage(Matrix* matrix, std::string filename){
    creator = new CreateFile();
    std::string contenido;
    ofstream fs(filename);
    NodeMatrix *aux = matrix;
    contenido += "digraph Tablero {";
    contenido += "node [ fontsize = 16 shape = record] \n";


    contenido += "}";
    fs << contenido;
    fs.close();
    creator->create(filename, "fichas.png");
}

    std::vector<int> xx;
    std::vector<int> yy;
    std::vector<Matrix>::iterator it;
    for(it = mm.begin(); it < mm.end(); it++){
        yy.push_back( ((*it).MaximunHeader()) + 2);
        xx.push_back( ((*it).MaximunLateral()) + 2);
    }
    std::sort(xx.begin(), xx.end());
    std::sort(yy.begin(), yy.end());
    std::string canvas[xx[xx.size() - 1]+1][yy[yy.size() - 1]+1];
    int f = (sizeof(canvas)/sizeof(canvas[0]));
    int c = (sizeof(canvas[0])/ sizeof(canvas[0][0]));
    for(int j=0; j<c; j++){
        canvas[0][j] = "<TD>" + std::to_string(j) + "</TD>\n";
    }
    for(int i=1; i<f; i++){
        canvas[i][0] = "<TD>" + std::to_string(i) + "</TD>\n";
    }
    for(int i=1; i<f; i++){
        for(int j=1; j<c; j++){
            canvas[i][j] = "<TD></TD>\n";
        }
    }
    std::vector<Matrix>::iterator ti;
    for(ti = mm.begin(); ti < mm.end(); ti++){
        for(int i=0; i<f; i++){
            for(int j=0; j<c; j++){
                std::string col = (*ti).ExistColor(i, j);
                if(col != ""){
                    if(i == 0){
                        canvas[i][j] = "<TD BGCOLOR=\"" + col + "\">" + std::to_string(j) + "</TD>\n";
                    }else if(j == 0){
                        canvas[i][j] = "<TD BGCOLOR=\"" + col + "\">" + std::to_string(i) + "</TD>\n";
                    }else{
                        canvas[i][j] = "<TD BGCOLOR=\"" + col + "\"></TD>\n";
                    }
                }
            }
        }
    }
    std::string body = "";
    for(int i=0; i<f; i++){
        body += "<TR>\n";
        for(int j=0; j<c; j++){
            body += canvas[i][j];
        }
        body += "</TR>\n";
    }
    std::string header = "digraph example {\n"
            + std::string("node [shape=plaintext]\n")
            + "rankdir=TB\n"
            + std::string("A [label=<\n")
            + "<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\" CELLPADDING=\"10\">\n"
            + body
            + "</TABLE>"
            + std::string(">];\n")
            + "}";

