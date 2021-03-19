/* Jack Donnelly
2342203
CPSC 350-02
Assignment 4
*/

#include "RPNCalc.h"
#include "GenStack.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

RPNCalc::RPNCalc() {
	string inputString = "";
}

RPNCalc::~RPNCalc() {}

bool RPNCalc::InputIsGood(string input) {//makes sure input doesn't contain letters 
	for (int i = 0; i < input.size(); i++) {
		if (isalpha(input[i])) {
			return false;
		}
	}
	return true;
}

int RPNCalc::Calculate(string input) {
	GenStack<int> numStack;//stack for numbers
	int numCount = 0;
	int opCount = 0;
	stringstream s(input);
	string temp;
	int num;
	char op;
	while (!s.eof()) {
		s >> temp;
		if (stringstream(temp) >> num) {
			numCount++;
			numStack.push(num);//push to numstack
			temp = "";
		}
		else if (stringstream(temp) >> op) {
			opCount++;
			int rightOp;
			int leftOp;
			if (op == '+') {
				int rightOp = numStack.pop();
				int leftOp = numStack.pop();
				numStack.push(leftOp + rightOp);
			}
			if (op == '-') {
				int rightOp = numStack.pop();
				int leftOp = numStack.pop();
				numStack.push(leftOp - rightOp);
			}
			if (op == '*') {
				int rightOp = numStack.pop();
				int leftOp = numStack.pop();
				numStack.push(leftOp * rightOp);
			}
			if (op == '/') {
				int rightOp = numStack.pop();
				int leftOp = numStack.pop();
				numStack.push(leftOp / rightOp);
			}
			if (op == '%') {
				int rightOp = numStack.pop();
				int leftOp = numStack.pop();
				numStack.push(leftOp % rightOp);
			}
			//cout << op << "in op" << endl;
			temp = "";
		}
	}
	if (numCount > opCount + 1) {
		throw runtime_error("Invalid input, please try again.");
	}
	return numStack.pop();
}


