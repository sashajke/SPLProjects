#ifndef TREE_H_
#define TREE_H_
#include <vector>

class Session;

class Tree{
public:
    int traceTreeHelpForMaxTree(int currMaxNode, int currMaxAmount, int currMaxDepth, int currDepth);
    Tree(int rootLabel);
    void addChild(Tree *child);
    static Tree* createTree(const Session& session, int rootLabel);
    virtual int traceTree()=0;
    int GetRoot();
    void SetRoot(int root);
    void runScan(const Session& s,std::vector<int>& scanList);
    ~Tree();
    std::vector<Tree *> GetChildern();


private:
    int node;
    std::vector<Tree*> children;
    int getNode();
};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);

    virtual int traceTree();
     int getCurrCycle ();
private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);
    virtual int traceTree();





};

class RootTree: public Tree{
public:

    RootTree(int rootLabel);

    virtual int traceTree();
};

#endif