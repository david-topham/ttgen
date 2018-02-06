/*
 * simpleproposition.h
 *
 *  Created on: Oct 6, 2010
 *      Author: equilibrium
 */

#ifndef SIMPLEPROPOSITION_H_
#define SIMPLEPROPOSITION_H_

#include "proposition.h"

#include<iostream>
#include<cstring>

class simpleproposition : public proposition {
public:
	simpleproposition(char);
	virtual ~simpleproposition();
	void setValue(bool);
	char getName();
	bool evaluate();
	std::string* print();

private:
	char name;
	bool value;
};

#endif /* SIMPLEPROPOSITION_H_ */
