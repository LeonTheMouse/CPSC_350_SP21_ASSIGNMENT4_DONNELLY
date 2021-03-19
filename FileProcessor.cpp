/* Jack Donnelly
2342203
CPSC 350-02
Assignment 4
*/
#include "FileProcessor.h"

FileProcessor::FileProcessor() {}//constructor

FileProcessor::~FileProcessor() {}//destructor

bool FileProcessor::canOpen(string fileName) {//checks if file exists/can open
    ifstream iFS;
    iFS.open(fileName);
    if (iFS.is_open()) {
        return true;
    }
    else {
        return false;
    }
}

string FileProcessor::readFileToString(string filename) {//gets entire file and stores it in a single string
    ifstream IFS(filename);
    if (IFS.is_open()) {
        return string((istreambuf_iterator<char>(IFS)), istreambuf_iterator<char>());
    }
}

void FileProcessor::processContents(string fileContents) {//reads string into multiple lines to be operated on
    DNAComplement DNA;
    transform(fileContents.begin(), fileContents.end(), fileContents.begin(), ::toupper);
    fileContents += "\n";
    string sequence;//stores current line
    string output;//collects lines after they are operated on
    for (int i = 0; i < fileContents.size(); i++) {//iterate through whole string
        if (fileContents[i] != '\n') {//add non newline chars to string to be operated on
            sequence += fileContents[i];
        }
        else if (fileContents[i] == '\n') {
            if (fileContents[i] == fileContents[i + 1]) {
                continue;
            }
            string complement = DNA.getComplement(sequence);
            string reverseComplement = DNA.getReverseComplement(sequence);
            output += "Sequence Given: " + sequence + "\n";//formatting for output file
            output += "Complement: " + complement + "\n";
            output += "Reverse Complement: " + reverseComplement + "\n";
            sequence = "";//resets sequence so the next string can be operated on.
        }
    }
    outputToFile("dnaoutput.txt", output);//write string to file called dnaoutput
    cout << "File Processed, output can be found in 'output.txt'." << endl;
}

void FileProcessor::clearFile(string fileToClear) {
    ofstream OFS;
    OFS.open(fileToClear);
    OFS.close();
}

void FileProcessor::outputToFile(string outputFile, string data) {
    ofstream OFS;
    clearFile(outputFile);
    OFS.open(outputFile, ios_base::app);//append to the file because it get's cleared before we call this function anyway
    OFS << data << endl;
    OFS << '\n';
    OFS.close();
}