#ifndef AGENT_H_
#define AGENT_H_

#include <vector>
#include "Session.h"

class Agent{
public:
    Agent(Session& ses);
    Agent(const Agent &agent);
    virtual ~Agent(){}
    Agent& operator=(const Agent& agent);

    virtual Agent* clone()=0;
    virtual void act()=0;

protected:
    Session& session;
};

class ContactTracer: public Agent{
public:
    ContactTracer(Session& session);
    ContactTracer(const ContactTracer&contactTracer);
    virtual ~ContactTracer(){}
    virtual Agent* clone();
    virtual void act();
};


class Virus: public Agent{
public:
    Virus(int nodeInd, Session& session);
    Virus(const Virus&virus);
    virtual ~Virus(){}
    virtual void act();
    virtual Agent* clone();

private:
    const int nodeInd;
};

#endif