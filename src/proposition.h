/*
 * proposition.h
 *
 *  Created on: Oct 6, 2010
 *      Author: equilibrium
 */

#ifndef PROPOSITION_H_
#define PROPOSITION_H_

#include<iostream>

class proposition {
public:
	enum unaryoperator{
		Not
	};

	enum binaryoperator{
		And,
		Or,
		Xor,
		Implies,
		Iff
	};
	proposition();
	virtual ~proposition();
	virtual bool evaluate() = 0;
	virtual std::string* print() = 0;
};

#endif /* PROPOSITION_H_ */
