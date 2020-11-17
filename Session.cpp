//
// Created by az123 on 11/3/2020.
//
#include "Session.h"
#include "Agent.h"
#include "Tree.h"
#include "json.hpp"
#include <fstream>// std::ifstream


// for convenience
using json = nlohmann::json;


Session::Session(const std::string& path)
{
    cycle = 0;
    std::ifstream stream(path);
    json j;
    stream >> j;


    std::vector<std::vector<int>> edges = j["graph"]; // initialize the graph
    setGraph(edges);
    for(size_t i=0;i< j["agents"].size();i++) // agents addition
    {
        Agent* v;
        if(j["agents"][i][0] == "V")
        {
            v = new Virus(j["agents"][i][1],*this);
            g.insertVirus(j["agents"][i][1]);
        }
        else
            v = new ContactTracer(*this);
        addAgent(*v);
    }

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
    for(size_t i=0;i<agents.size();i++)
    {
        delete agents.at(i);
    }
    agents.clear();
}
Session ::Session(const Session &aSession)
{
    g = aSession.g;
    cycle = aSession.cycle;
    treeType = aSession.treeType;
    for(int i=0;i<(int)aSession.agents.size();i++)
    {
        addAgent(*aSession.agents[i]->clone());
    }
}
Session::Session(const Session &&aSession) : g(aSession.g),cycle(aSession.cycle),treeType(aSession.treeType),agents(std::move(aSession.agents)){

}
Session & Session::operator=(const Session &&aSession) {
    if (this == &aSession)
    {
        return *this;
    }
    setGraph(aSession.g);
    treeType = aSession.treeType;
    for(size_t i=0;i<agents.size();i++)
    {
        delete agents.at(i);
    }
    agents.clear();
    agents = std::move(aSession.agents);
    return *this;

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
    for(size_t i=0;i<agents.size();i++)
    {
        delete agents.at(i);
    }
    agents.clear();
    for(size_t i=0;i<aSession.agents.size();i++)
    {
        addAgent(*aSession.agents[i]->clone());
    }
    return *this;
}

 const Graph& Session:: GetGraph() const {
    return this->g;
}

int Session::GetCycle() const {
    return this->cycle;
}

void Session::simulate() {
    bool stop = isFinished();
    while (!isFinished()) {
        int numOfCurrentAgents = agents.size();
        for (int i = 0; i < numOfCurrentAgents; i++) {
            agents.at(i)->act();
        }
        cycle++;
    }
    creatOutputJson();
}
void Session::creatOutputJson() {
    json output;
    output["graph"] = g.getGraph();
    std::vector<int> statusOfNodes = g.getNodesStatus();
    int counterOfInfected =0;
    for(size_t i=0;i<statusOfNodes.size();i++)
    {
        if(statusOfNodes[i] != 0)
            output["infected"][counterOfInfected++] = i;
    }


    std::ofstream stream("./output.json");

    stream << output;

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
    for(size_t i=0;i<virusRow.size();i++)
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
    int sickNode = g.dequeueInfected();
    if(sickNode != -1)
    {
        Tree* tree = Tree::createTree(*this,sickNode);
        int nodeToDisconnect = tree->traceTree();
        g.disconnectNode(nodeToDisconnect);
        delete tree;
    }

}
bool Session::isFinished() {
    return g.checkIfAllSickDisconnected();
}

int Session::getNumberOfNodes() const {
    return g.GetNumbeOfVertices();
}


