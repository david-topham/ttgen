/*
 * unaryproposition.h
 *
 *  Created on: Oct 7, 2010
 *      Author: equilibrium
 */

#ifndef UNARYPROPOSITION_H_
#define UNARYPROPOSITION_H_

#include "proposition.h"

#include<iostream>

class unaryproposition : public proposition{
public:
	unaryproposition(proposition::unaryoperator,proposition*);
	virtual ~unaryproposition();
	bool evaluate();
	std::string* print();
private:
	proposition::unaryoperator operator_;
	proposition* childProposition;
};

#endif /* UNARYPROPOSITION_H_ */
