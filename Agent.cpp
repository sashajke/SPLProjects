//
// Created by az123 on 11/3/2020.
//
#include "Agent.h"
Agent::Agent(Session& ses) : session(ses)
{

}
Agent::Agent(const Agent &agent) : session(agent.session)
{

}
Agent & Agent::operator=(const Agent &agent)
{
    session = agent.session;
    return *this;
}
Virus::Virus(int nodeind,Session &session)  : Agent(session),nodeInd(nodeind)
{

}
void Virus::act()
{
    session.actAsVirus(nodeInd);
}
Virus::Virus(const Virus &virus) : Agent(virus.session),nodeInd(virus.nodeInd) {

}
Agent* Virus::clone()
{
    return new Virus(*this);
}
ContactTracer::ContactTracer(Session &session)  : Agent(session)
{

}
ContactTracer::ContactTracer(const ContactTracer &contactTracer) : Agent(contactTracer.session) {}
void ContactTracer::act() {
    session.actAsContactTracer();

}
Agent* ContactTracer::clone()
{
    return new ContactTracer(*this);
}