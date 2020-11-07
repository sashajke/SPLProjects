//
// Created by az123 on 11/3/2020.
//
#include "Bfs.h"
#include "Tree.h"

Tree *Tree::createTree(const Session &session, int rootLabel) {
    Bfs BfsScan = new Bfs(Session session, rootLabel);
    Tree ToReturn = BfsScan.RunScan(TreeType);
    return ToReturn;
}

Tree::~Tree() {
    delete this;
}

int Tree::GetRoot() {
    return this->node;
}

void Tree::addChild(const Tree &child) {
    this->addChild(child);
}
std::vector<Tree*>*  Tree::GetChildern() {
    return &this->children ;
}

int MaxRankTree::traceTree() {
    int Index=0;
     MaxRankTree ChildernList= (MaxRankTree &&) GetChildern();
    for(MaxRankTree t : ChildernList)
        if(t)

}

int CycleTree::traceTree() {

}

int RootTree::traceTree() {

return this->GetRoot()

}
