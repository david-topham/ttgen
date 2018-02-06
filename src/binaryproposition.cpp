/*
 * binaryproposition.cpp
 *
 *  Created on: Oct 7, 2010
 *      Author: equilibrium
 */

#include "binaryproposition.h"

binaryproposition::binaryproposition(proposition::binaryoperator operator_, proposition* childPropositionLeft, proposition* childPropositionRight){
	this->operator_=operator_;
	this->childPropositionLeft=childPropositionLeft;
	this->childPropositionRight=childPropositionRight;
}

binaryproposition::~binaryproposition(){
}

bool binaryproposition::evaluate(){
	switch(operator_){
		case proposition::And:
			return childPropositionLeft->evaluate() && childPropositionRight->evaluate();
		case proposition::Or:
			return childPropositionLeft->evaluate() || childPropositionRight->evaluate();
		case proposition::Xor:
			return childPropositionLeft->evaluate() ? !childPropositionRight->evaluate() : childPropositionRight->evaluate();
		case proposition::Implies:
			return childPropositionLeft->evaluate() ? childPropositionRight->evaluate() : true;
		case proposition::Iff:
			return childPropositionLeft->evaluate() ? childPropositionRight->evaluate() : !childPropositionRight->evaluate();
		default:
			return false;
	}
}

std::string* binaryproposition::print(){
	std::string* s = childPropositionLeft->print();
	s->insert(0,"(");
	switch(operator_){
		case proposition::And:
			s->append(" \\wedge ");
			break;
		case proposition::Or:
			s->append(" \\vee ");
			break;
		case proposition::Xor:
			s->append(" \\oplus ");
			break;
		case proposition::Implies:
			s->append(" \\rightarrow ");
			break;
		case proposition::Iff:
			s->append(" \\leftrightarrow ");
			break;
		default:
			break;
	}
	std::string* s2 = childPropositionRight->print();
	s->append(s2->c_str());
	delete s2;
	s->append(")");
	return s;
}
