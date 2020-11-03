#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

class Graph{
public:
    Graph();
    Graph(std::vector<std::vector<int>> matrix);

    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    std::vector<int> getRow(int nodeInd);
    bool isNeighbours(int first,int second);
private:
    std::vector<std::vector<int>> edges;
};

#endif
