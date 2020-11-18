//
// Created by amit on 05/11/2020.
//


#ifndef Bfs_h
#define Bfs_h
#include <vector>
#include "Session.h"
#include "Tree.h"
#include "Graph.h"
using namespace std;

class Bfs {
public:
    Bfs(const Session& s ,int root);
    void RunScan(Tree &);

private:
    queue<int> q;
     Graph g;
    int root;
    Session s;
};


#endif
