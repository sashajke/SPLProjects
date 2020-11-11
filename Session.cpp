//
// Created by az123 on 11/3/2020.
//
#include "Session.h"
#include "Agent.h"
#include "Tree.h"
#include "json.hpp"
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

// for convenience
using json = nlohmann::json;


Session::Session(const std::string& path)
{

    std::ifstream stream(path);
    json j;
    stream >> j;
    for(int i=0;i<j["agents"].size();i++) // agents addition
    {
            Agent* v;
            if(j["agents"][i][0] == "V")
            {
                 v = new Virus(j["agents"][i][1],*this);
            }
            else
                v = new ContactTracer(*this);
            addAgent(*v);
    }

    std::vector<std::vector<int>> edges = j["graph"]; // initialize the graph
    setGraph(edges);

    std::string tree = j["tree"];
    switch(tree[0]) // initialize the treeType of the tree
    {
        case 'M':
            treeType = MaxRank;
            break;
        case 'C':
            treeType = Cycle;
            break;
        case 'R':
            treeType = Root;
            break;
    }
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
        addAgent(*aSession.agents.at(i));
    }
    return *this;
}

 const Graph& Session:: GetGraph() const {
    return this->g;
}

int Session::GetCycle() const {
    return this->cycle;
}

void Session::simulate()
{

    while(g.numOfInfected() != 2) // need to modify the exit clause
    {
        int numOfCurrentAgents = agents.size();
        for(int i=0;i<numOfCurrentAgents;i++)
        {
           agents.at(i)->act();
        }
    }
    cycle++;
}
void Session:: addAgent(const Agent& agent)
{
    if(&agent != nullptr)
        agents.push_back(const_cast<Agent*>(&agent)); // cast to pointer to be able to add to agents
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
                    addAgent(*newVirus);

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


