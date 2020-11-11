
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
            ToReturn = new RootTree( rootLabel);
    }
    Bfs *BfsScan = new Bfs(session, rootLabel);
    BfsScan->RunScan(*ToReturn);
    delete BfsScan;
    return ToReturn;
}

MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel) {

}

void Tree::SetRoot(int root) {
    this->node = root;
}

Tree::Tree(int rootLabel):node(rootLabel) {

}

CycleTree::CycleTree(int rootLabel, int currCycle) : Tree(rootLabel) {
    this->currCycle = currCycle;
}

Tree::~Tree() {
    for (int i = 0; i < this->children.size(); i++)
        delete children[i];
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

int Tree::CheckDepth(std::vector<Tree> &array) {
    int indexToReturn = 0;
    std::vector<int> ArrayOfDepth;
    for (int index = 0; index < array.size(); index++)
        while (true)
            if (array[index].children.size() == 0)
                break;
            else
                ArrayOfDepth[index] += 1;
    for (int index = 0; index < array.size(); index++)
        if (ArrayOfDepth[index] > ArrayOfDepth[indexToReturn])
            indexToReturn = index;

    return indexToReturn;
}

//the first int it return is the index and the second is te amount of childern
std::vector<int> Tree::CheckAllVerticesForMax(int CurrentMax, Tree *tree, std::vector<int> &ToReturn) {
    if (tree->children.size() > CurrentMax) {
        ToReturn[0] = tree->node;
        ToReturn[1] = tree->children.size();
    }
    for (int index = 0; index < tree->children.size(); index++)
        CheckAllVerticesForMax(CurrentMax, children[index], ToReturn);
    return ToReturn;
}




int MaxRankTree::traceTree() {
    return traceTreeHelpForMaxTree(0,0,0,0);
}
int Tree::traceTreeHelpForMaxTree(int currMaxNode, int currMaxAmount, int currMaxDepth, int currDepth)
{
    std::vector<Tree*> children = GetChildern();

    if(children.size() > currMaxAmount || (children.size() == currMaxAmount && currMaxDepth > currDepth))
    {
        currMaxNode = this->getNode();
        currMaxAmount = children.size();
        currMaxDepth = currDepth;
    }
    for(int i=0;i<children.size();i++)
    {
        currMaxNode = children[i]->traceTreeHelpForMaxTree(currMaxNode, currMaxAmount,currMaxDepth,currDepth+1);
    }
    return currMaxNode;
}

int Tree::getNode() {
    return  this->node;
}

int CycleTree::traceTree() {
    int Curr = this->getCurrCycle();
    int NumberOfCycles = 0;
    Tree *t;
    while (Curr > NumberOfCycles && t ->GetChildern().size()>0) {
      t = t->GetChildern()[0];
        NumberOfCycles++;
    }
    return t->GetRoot();
}

int CycleTree::getCurrCycle() {
    return this->currCycle;
}

int RootTree::traceTree() {
    return this->GetRoot();
}

RootTree::RootTree(int rootLabel) : Tree(rootLabel) {

}
