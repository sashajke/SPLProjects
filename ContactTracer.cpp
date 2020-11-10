//
// Created by az123 on 11/3/2020.
//
#include "Agent.h"
ContactTracer::ContactTracer(Session &session)  : Agent(session)
{

}

void ContactTracer::act() {
	session.actAsContactTracer();

}