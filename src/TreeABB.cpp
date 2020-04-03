#include <ostream>
#include <fstream>
#include "TreeABB.h"
#include <fstream>
#include "SimplyLinkedListScoreboard.h"
#include "Score.h"
using namespace std;

TreeABB::TreeABB(){
    //this->root = NULL;
    this->size = 0;
    this->mejores = new SimplyLinkedListScoreboard();
}

int TreeABB::getSize(){
    return this->size;
}

void TreeABB::insert(NodeABB *&root, Jugador *data){
    if(root == NULL){
        NodeABB *newNode = new NodeABB(data);
        root = newNode;
        size++;
    }else{
        if(data->getPrimeraLetra() < root->getData()->getPrimeraLetra()){
            insert(root->left, data);
        }else if(data->getPrimeraLetra() > root->getData()->getPrimeraLetra()){
            insert(root->right, data);
        }else{
            cout << "Fallo al ingresar el nodo" <<endl;
            return;
        }
    }
}

NodeABB* TreeABB::searchNode(int id, NodeABB *root, NodeABB* tmp){
    if(root == NULL && tmp == NULL){
        return NULL;
    }
    if(tmp == NULL){
        if(root->getData()->getPrimeraLetra() == id){
            return root;
        }
        tmp = searchNode(id, root->left, tmp);
        tmp = searchNode(id, root->right, tmp);
    }
    return tmp;
}

NodeABB* TreeABB::searchPlayerByID(int id, NodeABB *root, NodeABB* tmp){
    if(root == NULL && tmp == NULL){
        return NULL;
    }
    if(tmp == NULL){
        if(root->getData()->getNoJugador() == id){
            return root;
        }
        tmp = searchPlayerByID(id, root->left, tmp);
        tmp = searchPlayerByID(id, root->right, tmp);
    }
    return tmp;
}

void TreeABB::obtainBest(NodeABB *root){
    if(root == NULL){
        return;
    }
    else{
        if(root->getData()!=nullptr){
                if(root->getData()->getPuntajes()->devolverMejorPuntaje()!=nullptr){
                    mejores->insertar(root->getData()->getPuntajes()->devolverMejorPuntaje());
                }
                mejores->mostrarLista();
        }
        obtainBest(root->left);
        obtainBest(root->right);
    }
}

void TreeABB::ReportPre(NodeABB* root){
    if(root == NULL){
        return;
    }
    if(iteracion!=0){
         contenido += "-> \"  " + root->getData()->getNombreJugador() + " \" ";

    }else{
        contenido += " \"  " + root->getData()->getNombreJugador() + " \" ";

    }
    iteracion++;
    ReportPre(root->getLeft());
    ReportPre(root->getRight());
}

void TreeABB::ReportIn(NodeABB* root){
    if(root == NULL){
        return;
    }
    ReportIn(root->getLeft());
    if(iteracion != 0){
        contenido += "-> \"  " + root->getData()->getNombreJugador() + " \" ";
    }else{
        contenido += " \"  " + root->getData()->getNombreJugador() + " \"";
    }
    iteracion++;
    ReportIn(root->getRight());
}

void TreeABB::ReportPost(NodeABB* root){
    if(root == NULL){
        return;
    }
    ReportPost(root->getLeft());
    ReportPost(root->getRight());
    if(iteracion!=0){
        contenido += " -> \"  " + root->getData()->getNombreJugador() + " \"";
    }else{
        contenido += " \"  " + root->getData()->getNombreJugador() + " \"";
    }
    iteracion++;
}

void TreeABB::GraphABB(NodeABB* root){
    std::string text = "digraph grafica{\n"
            + std::string("rankdir=TB;\n")
            + "node [shape = circle, style=filled, fillcolor=seashell2];\n";
    text = Branch(root, text);
    text = Children(root, text);
    text += "}";
    std::ofstream file;
    file.open("ArbolABB.dot");
    if(file.fail()){
        std::cout << "Error al abrir el txt" << std::endl;
        return;
    }
    file << text << std::endl;
    file.close();
    system("dot ArbolABB.dot -o ArbolABB.png -Tpng");
    system("cmd /c start ArbolABB.png");
}


std::string TreeABB::Branch(NodeABB* root, std::string chain){
    if(root == NULL){
        return chain;
    }
    chain += "nodo" + root->getData()->getNombreJugador() + " [ label = \" " + root->getData()->getNombreJugador() + "\"];\n";
    chain = Branch(root->getLeft(), chain);
    chain = Branch(root->getRight(), chain);
    return chain;
}

std::string TreeABB::Children(NodeABB* root, std::string chain){
    if(root == NULL){
        return chain;
    }
    if(root->getLeft() != NULL){
        chain += "nodo" + root->getData()->getNombreJugador() + ": c0->nodo" + root->getLeft()->getData()->getNombreJugador() + ";\n";
    }
    if(root->getRight() != NULL){
        chain += "nodo" + root->getData()->getNombreJugador() + ": c1->nodo" + root->getRight()->getData()->getNombreJugador() + ";\n";
    }
    chain = Children(root->getLeft(), chain);
    chain = Children(root->getRight(), chain);
    return chain;
}

void TreeABB::createDOT(std::string filename, std::string type, NodeABB *raiz){
    creator = new CreateFile();
    ofstream fs(filename);
    contenido = "";
    contenido += "digraph { \n";
    contenido += " rankdir=LR \n";
    contenido += "node [shape = record] \n";
    if(type=="inorder"){
        ReportIn(raiz);
    }else if(type=="preorder"){
        ReportPre(raiz);
    }else if(type=="postorder"){
        ReportPost(raiz);
    }
    contenido += "}";
    fs << contenido;
    fs.close();
    creator->create(filename, "diccionario.png");
    iteracion =0;
}

SimplyLinkedListScoreboard * TreeABB::getMejores(){
    return this->mejores;
}
