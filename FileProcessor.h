/* Jack Donnelly
2342203
CPSC 350-02
Assignment 4
*/
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include "GenStack.h"
#include "DNAComplement.h"

using namespace std;

class FileProcessor {
public:
	//constructor 
	FileProcessor();

	//destructor
	~FileProcessor();

	bool canOpen(string fileName);

	string readFileToString(string filename);

	void processContents(string fileContents);

	//reset contents of file
	void clearFile(string fileToClear);

	void outputToFile(string outputFile, string data);
private:
	//void removeWhiteSpace(string& line);
};

#endif