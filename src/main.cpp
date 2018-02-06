/*
 * main.cpp
 *
 *  Created on: Oct 5, 2010
 *      Author: equilibrium
 *  Modifed on: Feb 14, 2018
 *      Mingyun Kim and David Topham
 *         added options for reverse, mute, circuit, and sort
 *         changed negation to \sim instead of \neg
 */

#include "latexlogic.h"

#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

void displayHelp(){
	cout << "LaTeX Truth Table Generator v1.0" << endl;
	cout << "by Equilibrium - equilibriumtr@gmail.com - ayberkozgur.blogspot.com" << endl;
	cout << "Generates a truth table code for LaTeX from the given logic proposition." << endl;
	cout << endl;
	cout << "Usage: ttgen [OPTIONS] proposition" << endl;
	cout << endl;
	cout << "	-d, --detailed     Includes all subpropositions of given proposition." << endl;
	cout << "	-h, --hline        Prints a horizontal line between each permutation." << endl;
	cout << "	-m, --mute         Prints without the table environment." << endl;
	cout << "	-r, --reverse      Prints reverse order for TT rows." << endl;
    cout << "	-c, --circuits     Prints 0/1 instead of F/T." << endl;
    cout << "	-s, --sort         Prints alphabetical order." << endl;
	cout << "	    --help         Prints this text." << endl;
	cout << endl;
	cout << "Elementary propositions must consist of a single character of A-Z or a-z. Use '(' and ')' to denote parentheses." << endl;
	cout << "Following logic operators are valid:" << endl;
	cout << "~      not" << endl;
	cout << "&      and" << endl;
	cout << "|      or" << endl;
	cout << "^      xor" << endl;
	cout << "->     implies" << endl;
	cout << "<->    if and only if" << endl;
}

int main(int argc, char **argv) {
	if(argc==1 || (argc==2 && !strcmp("--help",argv[1]))){
		displayHelp();
		return EXIT_SUCCESS;
 	}
	else{
		string propositionString;
		bool mute = false, hline = false, detailed = false, 
             reverse = false, circuit = false, sort = false;
		for(int i = 1; i<argc; i++){
			if(!strcmp("--hline",argv[i]) || !strcmp("-h",argv[i]))
				hline=true;
			else if (!strcmp("--mute",argv[i]) || !strcmp("-m",argv[i]))
				mute=true;
			else if(!strcmp("--detailed",argv[i]) || !strcmp("-d",argv[i]))
				detailed=true;
			else if(!strcmp("--reverse",argv[i]) || !strcmp("-r",argv[i]))
				reverse=true;
           	else if(!strcmp("--circuit",argv[i]) || !strcmp("-c",argv[i]))
				circuit=true;
           	else if(!strcmp("--sort",argv[i]) || !strcmp("-s",argv[i]))
				sort=true;
			else{
				if(propositionString.empty())
					propositionString.assign(argv[i]);
				else{
					cout << "Error: Invalid arguments." << endl;
					return EXIT_FAILURE;
				}
			}
		}
		if(propositionString.empty()){
			cout << "Error: No proposition provided." << endl;
			return EXIT_FAILURE;
		}

		latexlogic::printTruthTable(propositionString.c_str(),mute,hline,detailed,reverse,circuit,sort);
	}
}
