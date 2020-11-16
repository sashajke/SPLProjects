#ifndef TREE_H_
#define TREE_H_
#include <vector>

class Session;

class Tree{
public:
    Tree & operator=(const Tree &t);
    Tree(Tree const &t);
    int traceTreeHelpForMaxTree(int currMaxNode, int currMaxAmount, int currMaxDepth, int currDepth) const;
    int traceTreeHelpForCycleTree(int currCycle) const;
    Tree(int rootLabel);
    void addChild(Tree *child);
    static Tree* createTree(const Session& session, int rootLabel);
    virtual int traceTree()=0;
    int GetRoot() const;
    void SetRoot(int root);
    void runScan(const Session& s,std::vector<int>& scanList);
    ~Tree();
    const std::vector<Tree *> GetChildren() const;
    void SetChildern(std::vector<Tree *> childern);

private:
    int node;
    std::vector<Tree*> children;
};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
    CycleTree & operator=(const CycleTree &Ct);
    virtual int traceTree();
     int getCurrCycle ();
    CycleTree(const Tree &t, CycleTree const &Ct);
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