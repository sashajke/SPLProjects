
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
    std::vector<int> scanList(session.getNumberOfNodes());
    ToReturn->runScan(session,scanList);
    return ToReturn;
}

MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel) {

}

void Tree::SetRoot(int root) {
    this->node = root;
}

Tree::Tree(int rootLabel):node(rootLabel),children() {

}

CycleTree::CycleTree(int rootLabel, int currCycle) : Tree(rootLabel) ,currCycle(currCycle) {

}

 Tree::~Tree() {
    for (int i = 0; i < (int)this->children.size(); i++)
        delete children[i];
    children.clear();
}

int Tree::GetRoot() const {
    return this->node;
}

const std::vector<Tree *> Tree::GetChildren() const {
    return this->children;
}

void Tree::addChild(Tree *child) {
    this->children.push_back((Tree *const) child);
}



//the first int it return is the index and the second is te amount of childern




int MaxRankTree::traceTree() {
    return traceTreeHelpForMaxTree(GetRoot(),0,0,0);
}
int Tree::traceTreeHelpForMaxTree(int currMaxNode, int currMaxAmount, int currMaxDepth, int currDepth) const
{
    std::vector<Tree*> children = GetChildren();

    if((int)children.size() > currMaxAmount || ((int)children.size() == currMaxAmount && currMaxDepth > currDepth))
    {
        currMaxNode = this->GetRoot();
        currMaxAmount = children.size();
        currMaxDepth = currDepth;
    }
    for(int i=0;i<(int)children.size();i++)
    {
        currMaxNode = children[i]->traceTreeHelpForMaxTree(currMaxNode, currMaxAmount,currMaxDepth,currDepth+1);
    }
    return currMaxNode;
}

int CycleTree::traceTree() {
    int Curr = this->getCurrCycle();
    return traceTreeHelpForCycleTree(Curr);
}

int Tree::traceTreeHelpForCycleTree(int currCycle) const {
    if(currCycle == 0 || children.size() == 0)
        return node;
    return children[0]->traceTreeHelpForCycleTree(currCycle-1);

}

int CycleTree::getCurrCycle() {
    return this->currCycle;
}

int RootTree::traceTree() {
    return this->GetRoot();
}

RootTree::RootTree(int rootLabel) : Tree(rootLabel) {

}
void Tree::runScan(const Session& s,std::vector<int>& scanList)
{
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
//copy consto
Tree::Tree(Tree&& t):node(t.node),children(std::move(t.children)){
}
//rule of 5;

Tree & Tree::operator=(const Tree &&t) {
    if(this==&t)
        return *this;
    for(size_t index=0;index<t.children.size();index++)
       delete children[(int)index];
    children.clear();
    this->children=std::move(children);
    this->node=t.node;
    return *this;
}

void Tree::SetChildern(std::vector<Tree *> childern) {
    this->children=childern;
}
//=oprtaor rule of three
Tree & Tree::operator=(const Tree &t){
    if(this==&t)
        return *this;
    SetChildern(t.GetChildren());
    this->node=t.GetRoot();
    return *this;
}
//=opratoar rule of three
CycleTree& CycleTree::operator=(const CycleTree &Ct) {
    SetChildern(Ct.GetChildren());
    this->SetRoot(Ct.GetRoot());
    this->currCycle = Ct.currCycle;
    return *this;
}
//copt constructor
CycleTree::CycleTree(int rootLabel, const CycleTree &Ct) : Tree(rootLabel),currCycle(Ct.currCycle) {
}

