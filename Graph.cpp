//
// Created by az123 on 11/3/2020.
//

#include "Graph.h"
Graph::Graph(const Graph& graph) {
    edges = graph.edges;
    nodesStatus = graph.nodesStatus;
}

Graph::Graph(std::vector<std::vector<int>> matrix)
{
    edges = matrix;
    nodesStatus = std::vector<int>(matrix.size());

}
Graph& Graph::operator=(const Graph &graph) {
    edges = graph.edges;
    nodesStatus = graph.nodesStatus;
    infectedQueue = graph.infectedQueue;
    return *this;
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
bool Graph::isCarrying(int nodeInd)
{
    int nodeCondition = nodesStatus.at(nodeInd);
    return nodeCondition == 1;
}
bool Graph::isInfected(int nodeInd)
{
    int nodeCondition = nodesStatus.at(nodeInd);
    return nodeCondition == 2;
}
int Graph::numOfInfected()
{
    return infectedQueue.size();
}

std::vector<int> Graph::getRow(int nodeInd)
{
    std::vector<int> ret;
    for(int i=0;i<edges.at(nodeInd).size();i++) // copy the row
    {
        ret.push_back(edges.at(nodeInd).at(i));
    }
    return ret;
}

bool Graph::isNeighbours(int first, int second)
{
    bool res = edges.at(first).at(second) == 1;
    return  res;
}
int Graph::dequeueInfected()
{
    int node = infectedQueue.front();
    infectedQueue.pop();
    return node;
}

void Graph::disconnectNode(int nodeInt)
{
    if(nodeInt < edges.size())
    {
        for(int i=0;i<edges.size();i++)
        {
            std::vector<int> row = edges.at(i);
            for(int j=0; j<row.size();j++)
            {
                if(i == nodeInt || j == nodeInt)
                {
                    row.at(j) = 0;
                }
            }
        }
    }
}
