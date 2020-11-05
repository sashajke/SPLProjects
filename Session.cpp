//
// Created by az123 on 11/3/2020.
//
#include "Session.h"
#include "Agent.h"
#include "Tree.h"


Session::Session(const std::string& path)
{
    std::vector<std::vector<int>> vect
            {
                    {1, 1},
                    {1, 1}
            };
    g = Graph(vect);
    vect.at(0).at(0) = 0;

    Agent* v = new Virus(0,*this);
    agents.push_back(v);

}
Session::~Session() {
    for(int i=0;i<agents.size();i++)
    {
        delete agents.at(i);
    }
    agents.clear();
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
    for(int i=0;i<agents.size();i++)
    {
        delete agents.at(i);
    }
    agents.clear();
    for(int i=0;i<aSession.agents.size();i++)
    {
        agents.push_back(aSession.agents.at(i));
    }
    return *this;
}

void Session::simulate()
{

    while(g.numOfInfected() != 2)
    {
        int numOfCurrentAgents = agents.size();
        for(int i=0;i<numOfCurrentAgents;i++)
        {
           agents.at(i)->act();
        }
    }
}
void Session:: addAgent(const Agent& agent)
{

}
void Session::setGraph(const Graph& graph)
{
    g = graph;
}

void Session::enqueueInfected(int nodeInd)
{
    g.infectNode(nodeInd);
}
int Session::dequeueInfected()
{
    int node = g.dequeueInfected();
    return node;
}
TreeType Session::getTreeType() const
{
    return treeType;
}
void Session::actAsVirus(int nodeind)
{
    std::vector<int> virusRow = g.getRow(nodeind);
    // need to check if the virus is in the queue already
    if(!g.isInfected(nodeind))
        g.infectNode(nodeind);
    for(int i=0;i<virusRow.size();i++)
    {
        if(i != nodeind)
        {
            if(g.isNeighbours(nodeind,i))
            {
                if(!g.isCarrying(i) && !g.isInfected(i))
                {
                    Agent* newVirus = new Virus(i,*this);
                    agents.push_back(newVirus);
                    g.insertVirus(i);
                    break;
                }
            }

        }
    }
}

void Session::actAsContactTracer()
{
//    int sickNode = g.dequeueInfected();
//    Tree* tree = Tree::createTree(*this,sickNode);
//    int nodeToDisconnect = tree->traceTree();
//    g.disconnectNode(nodeToDisconnect);
//    delete tree;
}


