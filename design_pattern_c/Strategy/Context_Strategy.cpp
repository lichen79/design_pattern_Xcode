///////////////////////////////////////////////////////////
//  Context_Strategy.cpp
//  Implementation of the Class Context
//  Created on:      09-十月-2014 22:21:07
//  Original author: colin
///////////////////////////////////////////////////////////

#include "Context_Strategy.h"

Context_Strategy::Context_Strategy(){
}

Context_Strategy::~Context_Strategy(){
}

void Context_Strategy::algorithm(){
	m_pStrategy->algorithm();
}

void Context_Strategy::setStrategy(Strategy* st){
	m_pStrategy = st;
}

