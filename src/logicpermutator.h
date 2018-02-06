/*
 * logicpermutator.h
 *
 *  Created on: Oct 9, 2010
 *      Author: equilibrium
 */

#ifndef LOGICPERMUTATOR_H_
#define LOGICPERMUTATOR_H_

#include "simpleproposition.h"

#include<vector>

class logicpermutator{
public:
	logicpermutator(std::vector<simpleproposition*>*,std::vector<proposition*>*,bool,bool,bool,bool,void(*)(std::vector<simpleproposition*>*,std::vector<proposition*>*,bool,bool,bool));
	virtual ~logicpermutator();
	void permutate();
private:
	void permutate(unsigned int);
	std::vector<simpleproposition*>* simplePropositions;
	std::vector<proposition*>* propositions;
	void (*evaluatePermutation)(std::vector<simpleproposition*>*,std::vector<proposition*>*,bool,bool,bool);
	bool hline;
	bool detailed;
	bool reverse;
    bool circuit;
};

#endif /* LOGICPERMUTATOR_H_ */
