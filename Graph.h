#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>

class Graph{
public:
    Graph(){}
    Graph(const Graph& graph);
    Graph(std::vector<std::vector<int>> matrix);
    Graph& operator=(const Graph& graph);
    ~Graph(){}

    int numOfInfected();
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd) const;
    void insertVirus(int nodeInd);
    bool isCarrying(int nodeInd) const;
    int dequeueInfected();
    std::vector<int> getRow(int nodeInd) const;
    bool isNeighbours(int first,int second) const;
    void disconnectNode(int nodeInt);
    bool isDisconnected(int nodeInt) const;
    bool checkIfAllSickDisconnected() const;
    int GetNumbeOfVertices() const;
    const std::vector<std::vector<int>> getGraph() const;
    const std::vector<int> getNodesStatus() const;

private:
    std::vector<std::vector<int>> edges;
    std::vector<int> nodesStatus; // 0 for healthy,1 for carrying virus,2 for sick
    std::queue<int> infectedQueue;

};

#endif
