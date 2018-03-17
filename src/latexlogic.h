/*
 * latexlogic.h
 *
 *  Created on: Oct 9, 2010
 *      Author: equilibrium
 */

#ifndef LATEXLOGIC_H_
#define LATEXLOGIC_H_

#include <vector>
#include <cstring>

#include "logicpermutator.h"
#include "propositionparser.h"
#include "proposition.h"
#include "simpleproposition.h"

namespace latexlogic{
	void printTruthTable(const char*,bool,bool,bool,bool,bool,bool,bool);
	void printPermutation(std::vector<simpleproposition*>*,std::vector<proposition*>*,bool,bool,bool);
}

#endif /* LATEXLOGIC_H_ */
