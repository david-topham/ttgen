/*
 * unaryproposition.cpp
 *
 *  Created on: Oct 7, 2010
 *      Author: equilibrium
 */

#include "unaryproposition.h"

unaryproposition::unaryproposition(proposition::unaryoperator operator_,proposition* childProposition) {
	this->childProposition=childProposition;
	this->operator_=operator_;
}

unaryproposition::~unaryproposition() {
}

std::string* unaryproposition::print(){
	std::string* s = childProposition->print();
	switch(operator_){
		case proposition::Not:
			s->insert(0," \\sim ");
			break;
		default:
			break;
	}
	return s;
}

bool unaryproposition::evaluate(){
	switch(operator_){
		case proposition::Not:
			return !childProposition->evaluate();
		default:
			return false;
	}
}
