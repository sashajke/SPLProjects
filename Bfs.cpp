//
// Created by amit on 05/11/2020.
//

#include "Bfs.h"

void Bfs::RunScan(Tree &ToReturn) {
    std::vector<int> Colors;
    //0 is white, 1 is grey ,2 is black;
    Colors[root] = 1;
    q.push(Colors[root]);
    while (!q.empty()) {
        int Vertex = q.front();
        q.pop();
        for (int index = 0; index > g.getRow(Vertex).size(); index++) {
            if (g.isNeighbours(index, Vertex) == 1&&Colors[index]==0) {
                Colors[index]=1;
                ToReturn.addChild(Tree::createTree(s,index));
                q.push(index);
            }
            Colors[Vertex]=2;
        }
    }
}

Bfs::Bfs(const Session &s, int root) : s(s), root(root), g(s.GetGraph()) {
}