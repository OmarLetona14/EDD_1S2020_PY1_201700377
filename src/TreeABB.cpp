#include <ostream>

#include "TreeABB.h"
TreeABB::TreeABB(){
    this->root = NULL;
}

void TreeABB::insert(NodeABB *&root, Jugador *data){
    if(root == NULL){
        NodeABB *newNode = new NodeABB(data);
        root = newNode;
    }else{
        if(data->getNoJugador() < root->getData()->getNoJugador()){
            insert(root->left, data);
        }else if(data->getNoJugador() > root->getData()->getNoJugador()){
            insert(root->right, data);
        }else{

        }
    }
}

NodeABB* TreeABB::searchNode(int id, NodeABB *root, NodeABB* tmp){
    if(root == NULL && tmp == NULL){
        return NULL;
    }
    if(tmp == NULL){
        if(root->getData()->getNoJugador() == id){
            return root;
        }
        tmp = searchNode(id, root->left, tmp);
        tmp = searchNode(id, root->right, tmp);
    }
    return tmp;
}

std::vector<Matrix> TreeABB::GenerateImgPre(int node){
    std::cout << "\nCapas a usar:" << std::endl;
    std::vector<Matrix> vec;
    preOrden(root, 0, node, vec);
    return vec;
}

std::vector<Matrix> TreeABB::GenerateImgIn(int node){
    std::cout << "\nCapas a usar:" << std::endl;
    std::vector<Matrix> vec;
    inOrden(root, 0, node, vec);
    return vec;
}

std::vector<Matrix> TreeABB::GenerateImgPost(int node){
    std::cout << "\nCapas a usar:" << std::endl;
    std::vector<Matrix> vec;
    PostOrden(root, 0, node, vec);
    return vec;
}

int TreeABB::preOrden(NodeABB *root, int iteratorr, int limit, std::vector<Matrix> &listMatrix){
    if(iteratorr < limit){
        if(root == NULL){
            return iteratorr;
        }
        std::cout << root->getData()->getNoJugador();
//        listMatrix.push_back(GenerateMatrix(root));
        iteratorr++;
        if(iteratorr < limit){
          iteratorr =  preOrden(root->left, iteratorr, limit, listMatrix);
        }
        if(iteratorr < limit){
           iteratorr = preOrden(root->right, iteratorr, limit, listMatrix);
        }
    }
    return iteratorr;
}

int TreeABB::inOrden(NodeABB* root, int iteratorr, int limit, std::vector<Matrix> &listMatrix){
    if(iteratorr < limit){
        if(root == NULL){
            return iteratorr;
        }
        iteratorr =  inOrden(root->left, iteratorr, limit, listMatrix);
        if(iteratorr < limit){
            std::cout << root->getData()->getNoJugador();
//            listMatrix.push_back(GenerateMatrix(root));
            iteratorr++;
        }
        if(iteratorr < limit){
           iteratorr = inOrden(root->right, iteratorr, limit, listMatrix);
        }
    }
    return iteratorr;
}

int TreeABB::PostOrden(NodeABB* root, int iteratorr, int limit, std::vector<Matrix> &listMatrix){
    if(iteratorr < limit){
        if(root == NULL){
            return iteratorr;
        }
        iteratorr =  PostOrden(root->left, iteratorr, limit, listMatrix);
        if(iteratorr < limit){
           iteratorr = PostOrden(root->right, iteratorr, limit, listMatrix);
        }
        if(iteratorr < limit){
            std::cout << root->getData()->getNoJugador();
//            listMatrix.push_back(GenerateMatrix(root));
            iteratorr++;
        }
    }
    return iteratorr;
}
void TreeABB::LeafNodes(NodeABB* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        std::cout << std::to_string(root->getData()->getNoJugador()) + " ";
    }
    LeafNodes(root->getLeft());
    LeafNodes(root->getRight());
}

int TreeABB::TreeDepth(NodeABB* root){
    if(root == NULL){
        return 0;
    }
    int left = TreeDepth(root->getLeft());
    int right = TreeDepth(root->getRight());
    if(left <= right){
        return right + 1;
    }else{
        return left + 1;
    }
}

void TreeABB::ReportPre(NodeABB* root){
    if(root == NULL){
        return;
    }
    std::cout << std::to_string(root->getData()->getNoJugador()) + " ";
    ReportPre(root->getLeft());
    ReportPre(root->getRight());
}

void TreeABB::ReportIn(NodeABB* root){
    if(root == NULL){
        return;
    }
    ReportIn(root->getLeft());
    std::cout << std::to_string(root->getData()->getNoJugador()) + " ";
    ReportIn(root->getRight());
}

void TreeABB::ReportPost(NodeABB* root){
    if(root == NULL){
        return;
    }
    ReportPost(root->getLeft());
    ReportPost(root->getRight());
    std::cout << std::to_string(root->getData()->getNoJugador()) + " ";
}
