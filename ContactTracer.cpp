//
// Created by az123 on 11/3/2020.
//
#include "Agent.h"
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