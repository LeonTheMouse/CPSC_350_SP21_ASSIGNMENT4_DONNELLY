/* Jack Donnelly
2342203
CPSC 350-02
Assignment 4
*/
#ifndef DNACOMPLEMENT_H
#define DNACOMPLEMENT_H

#include <iostream>
#include <sstream>
#include "GenStack.h"

using namespace std;

class DNAComplement {
public:
	DNAComplement();//default constructor
	~DNAComplement();//destructor
	
	string getComplement(string sequence);

	string getReverseComplement(string sequence);

	string reverseSequence(string sequence);

};


#endif