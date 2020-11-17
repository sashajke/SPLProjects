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
    Session(const Session&& aSession);
    ~Session();
    void simulate();
    void addAgent(const Agent& agent);
    void setGraph(const Graph& graph);
    void actAsVirus(int nodeint);
    void actAsContactTracer();
    Session & operator=(const Session &aSession);
    Session & operator=(const Session&& aSession);
    void enqueueInfected(int);
    int dequeueInfected();
    TreeType getTreeType() const;
    const Graph& GetGraph() const;
    int getNumberOfNodes() const;
    int GetCycle() const;
    void creatOutputJson();

private:
    bool isFinished();
    int cycle;
    Graph g;
    TreeType treeType;
    std::vector<Agent*> agents;
};

#endif
