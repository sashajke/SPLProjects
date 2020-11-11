//
// Created by az123 on 11/3/2020.
//
#include "Agent.h"
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