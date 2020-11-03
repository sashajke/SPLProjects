#ifndef AGENT_H_
#define AGENT_H_

#include <vector>
#include "Session.h"

class Agent{
public:
    Agent(Session& ses);
    Session& getSession();
    virtual void act()=0;

private:
    Session& session;
};

class ContactTracer: public Agent{
public:
    ContactTracer(Session& session);

    virtual void act();
};


class Virus: public Agent{
public:
    Virus(int nodeInd, Session& session);

    virtual void act();
private:
    const int nodeInd;
};

#endif