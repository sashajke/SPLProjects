//
// Created by az123 on 11/3/2020.
//
#include "Session.h"
#include "Agent.h"


Session::Session(const std::string& path)
{
    std::vector<std::vector<int>> matrix;
    g = Graph(matrix);
}
Session & Session::operator=(const Session &aSession)
{
    // check for "self assignment" and do nothing in that case
    if (this == &aSession)
    {
        return *this;
    }

    setGraph(aSession.g);
    treeType = aSession.treeType;
    agents = aSession.agents;
    infectedQueue = aSession.infectedQueue;
    // return this List
    return *this;
}

void Session::simulate()
{

}
void Session:: addAgent(const Agent& agent)
{

}
void Session::setGraph(const Graph& graph)
{

}

void Session::enqueueInfected(int)
{

}
int Session::dequeueInfected()
{
    return 1;
}
TreeType Session::getTreeType() const
{
    return treeType;
}
void Session::actAsVirus(int nodeind)
{ 
    std::vector<int> virusRow = g.getRow(nodeind);
    // need to check if the virus is in the queue already
    for(int i=0;i<virusRow.size();i++)
    {
        if(i != nodeind && g.isNeighbours(nodeind,i) && !g.isInfected(i))
        {
             Agent* newVirus = new Virus(i,*this);
             agents.push_back(newVirus);
        }
    }
}
