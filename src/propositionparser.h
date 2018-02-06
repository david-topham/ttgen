/*
 * propositionparser.h
 *
 *  Created on: Oct 7, 2010
 *      Author: equilibrium
 */

#ifndef PROPOSITIONPARSER_H_
#define PROPOSITIONPARSER_H_

#include "proposition.h"
#include "simpleproposition.h"
#include "unaryproposition.h"
#include "binaryproposition.h"

#include<vector>
#include<iostream>
#include<stdexcept>
#include<algorithm>

class propositionparser{
public:
	propositionparser(const char*);
	std::vector<simpleproposition*> elementaryPropositions;
	std::vector<proposition*> propositions;
	void getPropositions();
	void sortPropositions();
private:
	proposition* parseProposition(int,int);
	char* propositionString;
};

#endif /* PROPOSITIONPARSER_H_ */
