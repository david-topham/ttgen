/*
 * propositionparser.cpp
 *
 *  Created on: Oct 7, 2010
 *      Author: equilibrium
 */

#include "propositionparser.h"

propositionparser::propositionparser(const char* propositionString){
	this->propositionString=new char[std::strlen(propositionString)+1];
	std::strcpy(this->propositionString,propositionString);
}

void propositionparser::getPropositions(){
	parseProposition(0,std::strlen(propositionString)-1);
}

proposition* propositionparser::parseProposition(int begin,int end){
	while(propositionString[begin]==' ')
		begin++;
	while(propositionString[end]==' ')
		end--;

	if(end<begin)
		throw std::runtime_error("Syntax error: Missing elementary proposition.");

	if(end==begin){
		char p = propositionString[end];
		if(p<65 || (p>90 && p<97) || p>122)
			throw std::runtime_error("Syntax error: Elementary proposition name is illegal, use a single character of A-Z or a-z.");

		for(unsigned int i=0;i<elementaryPropositions.size();i++)
			if(elementaryPropositions[i]->getName()==p)
				return elementaryPropositions[i];

		simpleproposition* simpleProposition = new simpleproposition(p);
		elementaryPropositions.push_back(simpleProposition);
		return simpleProposition;
	}

	int lastOperatorIndex=-1;
	int lastOperatorPrecedence = 6;
	char t;

	for(int i=begin;i<=end;i++){
		t=propositionString[i];

		if(t=='('){
			int para=1;
			do{
				if((i++)>end)
					throw std::runtime_error("Syntax error: Missing ')'.");
				if(propositionString[i]=='(')
					para++;
				else if(propositionString[i]==')')
					para--;
			}while(para>0);
		}
		else if(t=='~'){
			if(lastOperatorPrecedence>5){
				lastOperatorIndex=i;
				lastOperatorPrecedence=5;
			}
		}
		else if(t=='&'){
			if(lastOperatorPrecedence>4){
				lastOperatorIndex=i;
				lastOperatorPrecedence=4;
			}
		}
		else if(t=='|'){
			if(lastOperatorPrecedence>3){
				lastOperatorIndex=i;
				lastOperatorPrecedence=3;
			}
		}
		else if(t=='^'){
			if(lastOperatorPrecedence>2){
				lastOperatorIndex=i;
				lastOperatorPrecedence=2;
			}
		}
		else if(t=='-'){
			if(propositionString[i+1]=='>'){
				if(lastOperatorPrecedence>1){
					lastOperatorIndex=i;
					lastOperatorPrecedence=1;
				}
			}
			else
				throw std::runtime_error("Syntax error: Invalid 'Implies' operator, use '->'");
		}
		else if(t=='<'){
			if(propositionString[i+1]=='-' && propositionString[i+2]=='>'){
				if(lastOperatorPrecedence>0){
					lastOperatorIndex=i;
					lastOperatorPrecedence=0;
				}
			}
			else
				throw std::runtime_error("Syntax error: Invalid 'If And Only If' operator, use '<->'");
		}
	}

	if(lastOperatorIndex==-1){
		if(propositionString[begin]=='(' && propositionString[end]==')')
			return parseProposition(begin+1,end-1);
		else
			throw std::runtime_error("Syntax error: Elementary proposition must be single-character.");
	}

	switch(lastOperatorPrecedence){
		case 5: {
			if(begin!=lastOperatorIndex)
				throw std::runtime_error("Syntax error: Invalid usage of 'Not' operator.");

			proposition* proposition = new unaryproposition(proposition::Not,parseProposition(begin+1,end));
			std::string* s = proposition->print();
			std::string* s2;
			for(unsigned int i=0;i<propositions.size();i++){
				s2 = propositions[i]->print();
				if(!s->compare(s2->c_str())){
					delete s2;
					delete s;
					return propositions[i];
				}
				delete s2;
			}
			delete s;

			propositions.push_back(proposition);
			return proposition;
		}
		case 4:{
			proposition* proposition = new binaryproposition(proposition::And,parseProposition(begin,lastOperatorIndex-1),parseProposition(lastOperatorIndex+1,end));
			std::string* s = proposition->print();
			std::string* s2;
			for(unsigned int i=0;i<propositions.size();i++){
				s2 = propositions[i]->print();
				if(!s->compare(s2->c_str())){
					delete s2;
					delete s;
					return propositions[i];
				}
				delete s2;
			}
			delete s;

			propositions.push_back(proposition);
			return proposition;
		}
		case 3:{
			proposition* proposition = new binaryproposition(proposition::Or,parseProposition(begin,lastOperatorIndex-1),parseProposition(lastOperatorIndex+1,end));
			std::string* s = proposition->print();
			std::string* s2;
			for(unsigned int i=0;i<propositions.size();i++){
				s2 = propositions[i]->print();
				if(!s->compare(s2->c_str())){
					delete s2;
					delete s;
					return propositions[i];
				}
				delete s2;
			}
			delete s;

			propositions.push_back(proposition);
			return proposition;
		}
		case 2:{
			proposition* proposition = new binaryproposition(proposition::Xor,parseProposition(begin,lastOperatorIndex-1),parseProposition(lastOperatorIndex+1,end));
			std::string* s = proposition->print();
			std::string* s2;
			for(unsigned int i=0;i<propositions.size();i++){
				s2 = propositions[i]->print();
				if(!s->compare(s2->c_str())){
					delete s2;
					delete s;
					return propositions[i];
				}
				delete s2;
			}
			delete s;

			propositions.push_back(proposition);
			return proposition;
		}
		case 1:{
			proposition* proposition = new binaryproposition(proposition::Implies,parseProposition(begin,lastOperatorIndex-1),parseProposition(lastOperatorIndex+2,end));
			std::string* s = proposition->print();
			std::string* s2;
			for(unsigned int i=0;i<propositions.size();i++){
				s2 = propositions[i]->print();
				if(!s->compare(s2->c_str())){
					delete s2;
					delete s;
					return propositions[i];
				}
				delete s2;
			}
			delete s;

			propositions.push_back(proposition);
			return proposition;
		}
		case 0:{
			proposition* proposition = new binaryproposition(proposition::Iff,parseProposition(begin,lastOperatorIndex-1),parseProposition(lastOperatorIndex+3,end));
			std::string* s = proposition->print();
			std::string* s2;
			for(unsigned int i=0;i<propositions.size();i++){
				s2 = propositions[i]->print();
				if(!s->compare(s2->c_str())){
					delete s2;
					delete s;
					return propositions[i];
				}
				delete s2;
			}
			delete s;

			propositions.push_back(proposition);
			return proposition;
		}
		default:
			return 0;
	}
}

static bool alphaSort(simpleproposition *a,simpleproposition *b){
	return a->getName() < b->getName();
}

void propositionparser::sortPropositions(){
	std::sort(elementaryPropositions.begin(),elementaryPropositions.end(),alphaSort);
}
