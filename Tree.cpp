
// Created by az123 on 11/3/2020.

//#include "Bfs.h"
//#include "Tree.h"
//
//Tree *Tree::createTree(const Session &session, int rootLabel) {
//    TreeType treeType = session.getTreeType();
//    Tree *ToReturn;
//    switch (treeType) {
//        case (Cycle):
//            ToReturn = new CycleTree(rootLabel, session.GetCycle());
//        case (MaxRank):
//            ToReturn = new MaxRankTree(rootLabel);
//        case (Root):
//            ToReturn = new RootTree(rootLabel);
//    }
//    Bfs *BfsScan = new Bfs(session, rootLabel);
//    BfsScan->RunScan(*ToReturn);
//    delete BfsScan;
//    return ToReturn;
//}
//
//MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel) {
//
//}
//
//void Tree::SetRoot(int root) {
//    this->node = root;
//}
//
//Tree::Tree(int
//           rootLabel) {
//    this->node = rootLabel;
//}
//
//CycleTree::CycleTree(int rootLabel, int currCycle) : Tree(rootLabel) {
//    this->currCycle = currCycle;
//}
//
//Tree::~Tree() {
//    for (int i = 0; i < this->children.size(); i++)
//        delete children[i];
//
//}
//
//int Tree::GetRoot() {
//    return this->node;
//}
//
//std::vector<Tree *> Tree::GetChildern() {
//    return this->children;
//}
//
//void Tree::addChild(Tree *child) {
//    this->children.push_back((Tree *const) child);
//}
//
//int Tree::CheckDepth(std::vector<Tree> &array) {
//    int indexToReturn = 0;
//    std::vector<int> ArrayOfDepth;
//    for (int index = 0; index < array.size(); index++)
//        while (true)
//            if (array[index].children.size() == 0)
//                break;
//            else
//                ArrayOfDepth[index] += 1;
//    for (int index = 0; index < array.size(); index++)
//        if (ArrayOfDepth[index] > ArrayOfDepth[indexToReturn])
//            indexToReturn = index;
//
//    return indexToReturn;
//}
//
//
//
//
////the first int it return is the index and the second is te amount of childern
//std::vector<int> Tree::CheckAllVerticesForMax(int CurrentMax, Tree *tree, std::vector<int> &ToReturn) {
//    if (tree->children.size() > CurrentMax) {
//        ToReturn[0] = tree->node;
//        ToReturn[1] = tree->children.size();
//    }
//    for (int index = 0; index < tree->children.size(); index++)
//        CheckAllVerticesForMax(CurrentMax, children[index], ToReturn);
//    return ToReturn;
//}
//
//void Tree::CheckForProblems(std::vector<Tree> &array, int max, Tree *tree, std::vector<int> &ToReturn) {
//    if (tree->children.size() == max)
//        array.push_back(*tree);
//    for (int index = 0; index < tree->children.size(); index++)
//        CheckForProblems(array, max, children[index], ToReturn);
//    if (!array.empty())
//        ToReturn[0] = CheckDepth(array);
//}
//
//
//int MaxRankTree::traceTree() {
//    std::vector<int> ArrayOfThePair;
//    //the first int is the index and the second is te amount of childern
//    ArrayOfThePair = CheckAllVerticesForMax(0, this, ArrayOfThePair);
//    std::vector<Tree> array;
//    CheckForProblems(array, ArrayOfThePair[1], this, ArrayOfThePair);
//    if (!array.empty())
//        return ArrayOfThePair[0];
//}
//
//
//int CycleTree::traceTree() {
//    int Curr = this->getCurrCycle();
//    int NumberOfCycles = 0;
//    CycleTree *t = dynamic_cast<CycleTree *>(this->GetChildern().front());
//    while (Curr > NumberOfCycles && t != nullptr) {
////        t = reinterpret_cast<CycleTree *>(t->GetChildern());
//        Curr++;
//    }
//    return t->GetRoot();
//}
//
//int CycleTree::getCurrCycle() {
//    return this->currCycle;
//}
//
//int RootTree::traceTree() {
//    return this->GetRoot();
//}
