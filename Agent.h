#ifndef AGENT_H_
#define AGENT_H_

#include <vector>
#include "Session.h"

class Agent{
public:
    Agent(Session& ses);
    virtual ~Agent(){}
    virtual void act()=0;

protected:
    Session& session;
};

class ContactTracer: public Agent{
public:
    ContactTracer(Session& session);
    virtual ~ContactTracer(){}
    virtual void act();
};


class Virus: public Agent{
public:
    Virus(int nodeInd, Session& session);
    virtual ~Virus(){}
    virtual void act();
private:
    const int nodeInd;
};

#endif