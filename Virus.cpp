//
// Created by az123 on 11/3/2020.
//
#include "Agent.h"
Virus::Virus(int nodeind,Session &session)  : Agent(session),nodeInd(nodeind)
{

}
void Virus::act() {
    Session& ses = getSession();

    ses.actAsVirus(nodeInd);
}

