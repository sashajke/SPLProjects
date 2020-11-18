#ifndef TREE_H_
#define TREE_H_
#include <vector>

class Session;

class Tree{
public:
    Tree(Tree&& t);
    Tree & operator=(const Tree & t);
    Tree & operator=(const Tree && t);
    int traceTreeHelpForMaxTree(int currMaxNode, int currMaxAmount, int currMaxDepth, int currDepth) const;
    int traceTreeHelpForCycleTree(int currCycle) const;
    Tree(int rootLabel);
    void addChild(Tree *child);
    static Tree* createTree(const Session& session, int rootLabel);
    virtual int traceTree()=0;
    int GetRoot() const;
    void SetRoot(int root);
    void runScan(const Session& s,std::vector<int>& scanList);
    void SetChildern(std::vector<Tree *>  childern);
    ~Tree();
    const std::vector<Tree *> GetChildren() const;

private:
    int node;
    std::vector<Tree*> children;
};

class CycleTree: public Tree{
public:
    CycleTree & operator=(const CycleTree & Ct);
    CycleTree(int rootLabel, int currCycle);
    virtual int traceTree();
    CycleTree(int rootLabel, const CycleTree &Ct);
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