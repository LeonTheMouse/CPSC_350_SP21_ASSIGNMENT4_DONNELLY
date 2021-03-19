/* Jack Donnelly
2342203
CPSC 350-02
Assignment 4
*/
#include "GenStack.h"
#include "FileProcessor.h"
#include "DNAComplement.h"
#include "TempNode.h"
#include "RPNCalc.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
	string str = argv[1];//get argument from command line
	string inputFile;
	string inputCalc;
	string runCalc = "yes";//make sure it runs the first time
	bool correctInput = false;
	FileProcessor fp;
	DNAComplement DNA;
	if (str == "RPN") {
		while (runCalc == "yes" || runCalc == "Yes") {
			RPNCalc calc;
			cout << "Please provide operand and operators in polish notation, each argument should be seperated by a space." << endl;
			getline(cin, inputCalc);
			correctInput = (calc.InputIsGood(inputCalc));//checks input
			while (correctInput == false) {//makes sure input works before trying anything
				cout << "Wrong input! Please enter intergers or operaters(+,-,*,/,%)" << endl;
				getline(cin, inputCalc);
				if (calc.InputIsGood(inputCalc)) {
					correctInput = true;
				}

			}
			try {
				cout << "Your input gave the output: " << calc.Calculate(inputCalc) << endl;
			}
			catch (runtime_error& e) {
				cout << "Incorrect input, please try again" << endl;//cathes error thrown by RPNCalc if stack tries to pop when empty
			}
			cout << "Would you like to make another calculation? (yes or no)" << endl;//for repeat operations
			getline(cin, runCalc);
		}
		cout << "Thanks for Calculating!" << endl;
	}
	else if (str == "DNA") {
		cout << "Please provide a file with DNA sequence." << endl;
		cin >> inputFile;
		if (fp.canOpen(inputFile)) {
			string fileContents = fp.readFileToString(inputFile);
			fp.processContents(fileContents);
			correctInput = true;
		}

		while (correctInput == false) {//check input
			cout << "File does not exist. Please provide a file with DNA sequence." << endl;
			cin >> inputFile;
			if (fp.canOpen(inputFile)) {
				correctInput = true;
			}
		}
	}
	else {
		cout << "You didn't specify your arguments, please try again with DNA or RPN." << endl;//if program is run with no command line parameters
	}
	return 0;
}