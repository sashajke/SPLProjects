//
// Created by az123 on 11/3/2020.
//

#include "Graph.h"
Graph::Graph() {}

Graph::Graph(std::vector<std::vector<int>> matrix){}

void Graph::infectNode(int nodeInd){}

bool Graph::isInfected(int nodeInd)
{
    return true;
}

std::vector<int> Graph::getRow(int nodeInd)
{
    return edges.at(nodeInd);
}

bool Graph::isNeighbours(int first, int second)
{
    return true;
}
