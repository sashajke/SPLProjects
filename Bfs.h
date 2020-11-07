//
// Created by amit on 05/11/2020.
//

#ifndef ASSIGNMENT1_BFS_H
#define ASSIGNMENT1_BFS_H
#include "Session.h"
#include "Tree.h"
class Bfs {
public:
    Bfs(Session &seesion,int rootlabel);
    Tree RunScan();
};


#endif //ASSIGNMENT1_BFS_H
