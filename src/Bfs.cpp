//
// Created by amit on 05/11/2020.
//

#include "Bfs.h"

void Bfs::RunScan(Tree &ToReturn) {
    std::vector<int> Colors(s.getNumberOfNodes());
    //0 is white, 1 is grey ,2 is black;
    Colors[root] = 1;
    q.push(root);
    while (!q.empty()) {
        int Vertex = q.front();
        q.pop();
        for (int index = 0; index < (int)g.getRow(Vertex).size(); index++) {
            if (g.isNeighbours(index, Vertex) && Colors[index]==0) {
                Colors[index]=1;
                switch (s.getTreeType())
                {
                    case MaxRank:
                        ToReturn.addChild(new MaxRankTree(index));
                        break;
                    case Root:
                        ToReturn.addChild(new RootTree(index));
                        break;
                    case Cycle:
                        ToReturn.addChild(new CycleTree(index,s.GetCycle()));
                        break;
                }

                q.push(index);
            }
        }
        Colors[Vertex]=2;
    }
}

Bfs::Bfs(const Session &s, int root) : s(s), root(root), g(s.GetGraph()) {
}