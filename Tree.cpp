
// Created by az123 on 11/3/2020.

#include "Bfs.h"
#include "Tree.h"

Tree *Tree::createTree(const Session &session, int rootLabel) {
    TreeType treeType = session.getTreeType();
    Tree *ToReturn;
    switch (treeType) {
        case (Cycle):
            ToReturn = new CycleTree(rootLabel, session.GetCycle());
            break;
        case (MaxRank):
            ToReturn = new MaxRankTree(rootLabel);
            break;
        case (Root):
            ToReturn = new RootTree( rootLabel);
            break;
    }
//    Bfs *BfsScan = new Bfs(session, rootLabel);
//    BfsScan->RunScan(*ToReturn);
//    delete BfsScan;
    std::vector<int> scanList(session.getNumberOfNodes());
    ToReturn->runScan(session,scanList);
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
    for (int i = 0; i < (int)this->children.size(); i++)
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



//the first int it return is the index and the second is te amount of childern

int MaxRankTree::traceTree() {
    return traceTreeHelpForMaxTree(GetRoot(),0,0,0);
}
int Tree::traceTreeHelpForMaxTree(int currMaxNode, int currMaxAmount, int currMaxDepth, int currDepth)
{
    std::vector<Tree*> children = GetChildern();

    if((int)children.size() > currMaxAmount || ((int)children.size() == currMaxAmount && currMaxDepth > currDepth))
    {
        currMaxNode = this->getNode();
        currMaxAmount = children.size();
        currMaxDepth = currDepth;
    }
    for(int i=0;i<(int)children.size();i++)
    {
        currMaxNode = children[i]->traceTreeHelpForMaxTree(currMaxNode, currMaxAmount,currMaxDepth,currDepth+1);
    }
    return currMaxNode;
}

int Tree::getNode() {
    return  this->node;
}
/////////////////////////////////////////////
///////////////////////////////////////////// need to take care of t , he is not initialized
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
void Tree::runScan(const Session& s,std::vector<int>& scanList) {
    std::vector<int> Colors(s.getNumberOfNodes());
    Graph g = s.GetGraph();
    //0 is white, 1 is grey ,2 is black;
    scanList[node] = 1;
    for (int index = 0; index < (int)g.getRow(node).size(); index++) {
        if (g.isNeighbours(index, node) && scanList[index]==0) {
            scanList[index] = 1;
            switch (s.getTreeType())
            {
                case MaxRank:
                    addChild(new MaxRankTree(index));
                    break;
                case Root:
                    addChild(new RootTree(index));
                    break;
                case Cycle:
                    addChild(new CycleTree(index,s.GetCycle()));
                    break;
            }
        }
    }
    for(size_t i=0;i<children.size();i++)
    {
        children[i]->runScan(s,scanList);
    }

}
