/*
 * latexlogic.cpp
 *
 *  Created on: Oct 9, 2010
 *      Author: equilibrium
 */

#include "latexlogic.h"

void latexlogic::printTruthTable(const char* propositionString,bool mute,bool hline,bool detailed,bool reverse,bool circuit, bool sort, bool fit){
	propositionparser pp(propositionString);
	pp.getPropositions();

	if (fit) std::cout << "\\resizebox{\\columnwidth}{!}{" << std::endl;
	if (!mute) {
		std::cout << "\\begin{table}[ht]" << std::endl;
		std::cout << "\\caption{Truth Table}" << std::endl;
		std::cout << "\\centering" << std::endl;
	}
	std::cout << "\\begin{tabular}{|";
	for(unsigned int i=0;i<pp.elementaryPropositions.size();i++)
		std::cout << "c|";
	std::cout << "|";
	if(detailed)
		for(unsigned int i=0;i<pp.propositions.size();i++)
			std::cout << "c|";
	else
		std::cout << "c|";
	std::cout << "}" << std::endl;

	std::cout << "\\hline" << std::endl;

	if (sort)
		pp.sortPropositions();
	std::cout << "$ " << pp.elementaryPropositions[0]->print()->c_str() << " $";
	for(unsigned int i=1;i<pp.elementaryPropositions.size();i++)
		std::cout << " & $ " << pp.elementaryPropositions[i]->print()->c_str() << " $";
	if(detailed)
		for(unsigned int i=0;i<pp.propositions.size();i++)
			std::cout << " & $ " << pp.propositions[i]->print()->c_str() << " $";
	else
		std::cout << " & $ " << pp.propositions.back()->print()->c_str() << " $";
	std::cout << " \\\\" << std::endl;

	std::cout << "\\hline" << std::endl;

	logicpermutator lp(&pp.elementaryPropositions,&pp.propositions,hline,detailed,reverse,circuit,&printPermutation);
	lp.permutate();

	if(!hline)
		std::cout << "\\hline" << std::endl;

	std::cout << "\\end{tabular}" << std::endl;
	if (!mute) {
		std::cout << "\\label{table:tt1}" << std::endl;
		std::cout << "\\end{table}" << std::endl;
	}
	if (fit) std::cout << "}" << std::endl;
}

void latexlogic::printPermutation(std::vector<simpleproposition*>* simplePropositions,std::vector<proposition*>* propositions,bool hline,bool detailed,bool circuit){
	if(simplePropositions->at(0)->evaluate())
		std::cout << (circuit ? "1" : "T");
	else
		std::cout << (circuit ? "0" : "F");
	for(unsigned int i=1;i<simplePropositions->size();i++)
		if(simplePropositions->at(i)->evaluate())
			std::cout << (circuit ? " & 1" : " & T");
		else
			std::cout << (circuit ? " & 0" : " & F");

	if(detailed)
		for(unsigned int i=0;i<propositions->size();i++)
			if(propositions->at(i)->evaluate())
				std::cout << (circuit ? " & 1" : " & T");
			else
				std::cout << (circuit ? " & 0" : " & F");
	else{
		if(propositions->back()->evaluate())
			std::cout << (circuit ? " & 1" : " & T");
		else
			std::cout << (circuit ? " & 0" : " & F");
	}

	std::cout << " \\\\" << std::endl;

	if(hline)
		std::cout << "\\hline" << std::endl;
}
