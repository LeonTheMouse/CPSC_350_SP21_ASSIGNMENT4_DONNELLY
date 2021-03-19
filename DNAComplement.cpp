/* Jack Donnelly
2342203
CPSC 350-02
Assignment 4
*/
#include "DNAComplement.h"
#include "GenStack.h"
#include <iostream>
#include <sstream>
using namespace std;

DNAComplement::DNAComplement() {};
DNAComplement::~DNAComplement() {};

string DNAComplement::getComplement(string sequence) {
	string complement = "";//converts bases accordingly and ignores any non base letters or symbols
	for (int i = 0; i < sequence.size(); ++i) {
		if (sequence[i] == 'A') {
			complement += 'T';
		}
		else if (sequence[i] == 'T') {
			complement += 'A';
		}
		else if (sequence[i] == 'C') {
			complement += 'G';
		}
		else if (sequence[i] == 'G') {
			complement += 'C';
		}
	}
	return complement;
}

string DNAComplement::getReverseComplement(string sequence) {
	string reversed = reverseSequence(sequence);//reverse sequence
	string reverseComplement = getComplement(reversed);//compute complement
	return reverseComplement;
}

string DNAComplement::reverseSequence(string sequence) {
	GenStack<char> stack;
	int count = 0;
	string reversed = "";
	for (char base : sequence) {
		stack.push(base);//push all to stack
		count++;//count elements pushed to stack
	}
	for (int i = 0; i < count; i++) {
		reversed += stack.pop();//new string is reverse of original sequence
	}
	return reversed;
}