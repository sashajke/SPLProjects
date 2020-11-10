#ifndef TREE_H_
#define TREE_H_
#include <vector>

class Session;

class Tree{
public:
    Tree(int rootLabel);
    void addChild(Tree *child);
    static Tree* createTree(const Session& session, int rootLabel);
    virtual int traceTree()=0;
    int GetRoot();
    void SetRoot(int root);
    ~Tree();
    virtual std::vector<Tree *> GetChildern();
private:
    int node;
    std::vector<Tree*> children;
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
    MaxRankTree(int rootLabel1, int rootLabel);
    MaxRankTree(int rootLabel);
    virtual int traceTree();
    virtual std::vector<Tree*> GetChildern();
};

class RootTree: public Tree{
public:
    RootTree(int rootLabel);
    virtual int traceTree();
};

#endif