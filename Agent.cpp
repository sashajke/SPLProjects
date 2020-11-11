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