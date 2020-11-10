
// Created by az123 on 11/3/2020.

#include "Bfs.h"
#include "Tree.h"

Tree *Tree::createTree(const Session &session, int rootLabel) {
    TreeType treeType = session.getTreeType();
    Tree *ToReturn;
    switch (treeType) {
        case (Cycle):
            ToReturn = new CycleTree(rootLabel, session.GetCycle());
        case (MaxRank):
            ToReturn = new MaxRankTree(rootLabel);
        case (Root):
            ToReturn = new RootTree(rootLabel);
    }
    Bfs *BfsScan = new Bfs(session, rootLabel);
    ToReturn = BfsScan->RunScan(ToReturn);
    return ToReturn;
}

MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel) {

}

void Tree::SetRoot(int root) {
    this->node = root;
}

Tree::Tree(int
           rootLabel) {
    this->node = rootLabel;
}

CycleTree::CycleTree(int rootLabel, int currCycle) : Tree(rootLabel) {
    this->currCycle = currCycle;
}

Tree::~Tree() {
    for (int i = 0; i < this->children.size(); i++)
        delete children[i];
    delete this;
}

int Tree::GetRoot() {
    return this->node;
}

std::vector<Tree *> Tree::GetChildern() {
    return this->children;
}

void Tree::addChild(Tree *child) {
    this->children.push_back((Tree *const) child);
}

int MaxRankTree::traceTree() {
    int indexToReturn = 0;
    std::vector<Tree *> ChildernPointer = this->GetChildern();
    for (int index = 0; index < ChildernPointer->size(); index++)
        if (ChildernPointer[indexToReturn].size() < ChildernPointer[index].size())
            indexToReturn = index;
    return indexToReturn;
}

//
int CycleTree::traceTree() {
    int Curr = this->getCurrCycle();
    int NumberOfCycles = 0;
    CycleTree *t = dynamic_cast<CycleTree *>(this->GetChildern()->front());
    while (Curr > NumberOfCycles && t != nullptr) {
        t = reinterpret_cast<CycleTree *>(t->GetChildern());
        Curr++;
    }
    return t->GetRoot();
}

int CycleTree::getCurrCycle() {
    return this->currCycle;
}

int RootTree::traceTree() {
    return this->GetRoot();
}
