//function declarations for the hash functions

//Bart Beltran
//Project 6 hash tables
#pragma once
#include "applicantStatisticsList.h"
#include <fstream>
#include <string>

//hash table class with add, delete, search functions
class applicantStatistics
{
private:
	applicantStatisticsList hashTable[7]; //0-7
	ifstream dataIn;
	ofstream dataOut;

public:
	int Hash(string);
	int searchHash(string);
	int searchHash(int);
	void addHash(string);
	void addHash(int);			
	void deleteHash(string);
	void deleteHash(int);
	void readFile(bool);

};
