/*
 * binaryproposition.h
 *
 *  Created on: Oct 7, 2010
 *      Author: equilibrium
 */

#ifndef BINARYPROPOSITION_H_
#define BINARYPROPOSITION_H_

#include "proposition.h"

#include<iostream>

class binaryproposition : public proposition{
public:
	binaryproposition(proposition::binaryoperator,proposition*,proposition*);
	virtual ~binaryproposition();
	bool evaluate();
	std::string* print();
private:
	proposition::binaryoperator operator_;
	proposition* childPropositionLeft;
	proposition* childPropositionRight;
};

#endif /* BINARYPROPOSITION_H_ */
