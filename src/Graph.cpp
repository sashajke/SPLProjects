//
// Created by az123 on 11/3/2020.
//

#include "Graph.h"
Graph::Graph():edges(),nodesStatus(),infectedQueue() {

}
Graph::Graph(const Graph& graph):edges(graph.edges),nodesStatus(graph.nodesStatus),infectedQueue() {

}
Graph& Graph::operator=(const Graph &graph) {
    edges = graph.edges;
    nodesStatus = graph.nodesStatus;
    infectedQueue = graph.infectedQueue;
    return *this;
}
void Graph::SetGraph(std::vector<std::vector<int>> edges) {
    this->edges=edges;
}

void Graph::infectNode(int nodeInd)
{
    if(!isInfected(nodeInd))
    {
        infectedQueue.push(nodeInd);
        nodesStatus.at(nodeInd) = 2;
    }

}
void Graph::insertVirus(int nodeInd)
{
    if(nodesStatus.at(nodeInd) == 0)
        nodesStatus.at(nodeInd) = 1;
}
bool Graph::isCarrying(int nodeInd) const
{
    int nodeCondition = nodesStatus.at(nodeInd);
    return nodeCondition == 1;
}
bool Graph::isInfected(int nodeInd) const
{
    int nodeCondition = nodesStatus.at(nodeInd);
    return nodeCondition == 2;
}
int Graph::numOfInfected()
{
    return infectedQueue.size();
}
int Graph::GetNumbeOfVertices() const {
    return this->edges.size();
}
std::vector<int> Graph::getRow(int nodeInd) const
{
    std::vector<int> ret;
    for(size_t i=0;i<edges.at(nodeInd).size();i++) // copy the row
    {
        ret.push_back(edges.at(nodeInd).at(i));
    }
    return ret;
}

bool Graph::isNeighbours(int first, int second) const
{
    bool res = edges.at(first).at(second) == 1;
    return  res;
}
int Graph::dequeueInfected()
{
    if(!infectedQueue.empty())
    {
        int node = infectedQueue.front();
        infectedQueue.pop();
        return node;
    }
    return -1;
}

const std::vector<std::vector<int>> Graph::getGraph() const {
    return edges;
}

const std::vector<int> Graph::getNodesStatus() const {
    return nodesStatus;
}


void Graph::disconnectNode(int nodeInt)
{
    if(nodeInt < (int)edges.size())
    {
        for(size_t i=0;i<edges.size();i++)
        {
            std::vector<int> row = edges.at(i);
            for(size_t j=0; j<edges.at(i).size();j++)
            {
                if((int)i == nodeInt ||(int) j == nodeInt)
                {
                    edges.at(i).at(j) = 0;
                }
            }
        }
    }
}
bool Graph::isDisconnected(int nodeInt) const{
    if(nodeInt<(int)edges.size())
    {
        std::vector<int> row1 = edges[nodeInt];
        for(size_t i=0;i<row1.size();i++)
        {
            if(row1[i] == 1 && nodesStatus[i] != 2)
                return false;
        }
        for(size_t i=0;i<edges.size();i++)
        {
            if(edges[i][nodeInt] == 1 && nodesStatus[i] != 2)
                return false;
        }
//        for(size_t i=0;i<edges.size();i++)
//        {
//            std::vector<int> row = edges.at(i);
//            for(size_t j=0; j<row.size();j++)
//            {
//                if(i == nodeInt || j == nodeInt)
//                {
//                    if(row.at(j) == 1 && nodesStatus[j] == 0)
//                        return false;
//                }
//            }
//        }
    }
    return true;
}
bool Graph::checkIfAllSickDisconnected() const{
    for(size_t i=0;i<nodesStatus.size();i++)
    {
        if(nodesStatus[i] != 0 && !isDisconnected(i))
            return false;
    }
    return true;
}
