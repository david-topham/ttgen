/*
 * logicpermutator.cpp
 *
 *  Created on: Oct 9, 2010
 *      Author: equilibrium
 */

#include "logicpermutator.h"

logicpermutator::logicpermutator(std::vector<simpleproposition*>* simplePropositions, std::vector<proposition*>* propositions, bool hline, bool detailed, bool reverse, bool circuit, void (*evaluatePermutation)(std::vector<simpleproposition*>*,std::vector<proposition*>*,bool,bool,bool)){
	this->evaluatePermutation = evaluatePermutation;
	this->simplePropositions = simplePropositions;
	this->propositions = propositions;
	this->detailed = detailed;
	this->hline = hline;
	this->reverse = reverse;
    this->circuit = circuit;
}

logicpermutator::~logicpermutator(){
}

void logicpermutator::permutate(){
	permutate(0);
}

void logicpermutator::permutate(unsigned int level){
	if(level==simplePropositions->size()){
		evaluatePermutation(simplePropositions,propositions,hline,detailed,circuit);
		return;
	}
	if (reverse)	simplePropositions->at(level)->setValue(true);
	else			simplePropositions->at(level)->setValue(false);
	permutate(level+1);
	if (reverse)	simplePropositions->at(level)->setValue(false);
	else			simplePropositions->at(level)->setValue(true);
	permutate(level+1);
}
