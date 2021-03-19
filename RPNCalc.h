/* Jack Donnelly
2342203
CPSC 350-02
Assignment 4
*/
#ifndef RPNCALC_H
#define RPNCALC_H
#include "GenStack.h"

#include <iostream>
#include <string>
using namespace std;

class RPNCalc {
public:
	RPNCalc();//constructor
	~RPNCalc();//destructor

	bool InputIsGood(string calcInput);
	int Calculate(string input);

};

#endif