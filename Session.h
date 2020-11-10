#ifndef SESSION_H_
#define SESSION_H_

#include "queue"
#include <vector>
#include <string>
#include "Graph.h"


class Agent;

enum TreeType{
    Cycle,
    MaxRank,
    Root
};

class Session{
public:

    Session(const std::string& path);
    Session(const Session &aSession);
    ~Session();
    void simulate();
    void addAgent(const Agent& agent);
    void setGraph(const Graph& graph);
    void actAsVirus(int nodeint);
    void actAsContactTracer();
    Session & Session::operator=(const Session &aSession);
    void enqueueInfected(int);
    int dequeueInfected();
    TreeType getTreeType() const;
    const Graph& GetGraph() const;
int GetCycle() const;
private:
    int cycle;
    Graph g;
    TreeType treeType;
    std::vector<Agent*> agents;
};

#endif
