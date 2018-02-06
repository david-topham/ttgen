/*
 * simpleproposition.cpp
 *
 *  Created on: Oct 6, 2010
 *      Author: equilibrium
 */

#include "simpleproposition.h"

simpleproposition::simpleproposition(char name){
	this->name=name;
	this->value=false;
}

simpleproposition::~simpleproposition(){
}

bool simpleproposition::evaluate(){
	return value;
}

std::string* simpleproposition::print(){
	std::string* s = new std::string();
	(*s)=name;
	return s;
}

void simpleproposition::setValue(bool value){
	this->value=value;
}

char simpleproposition::getName(){
	return name;
}
