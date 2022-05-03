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
	applicantStatisticsList hashTable[7]; 
	ifstream dataIn;
	ofstream dataOut;

public:
	int Hash(string);
	void addHash(string);
	void addHash(int);			//Fixme convert integer to string in function
	void deleteHash(string);
	void deleteHash(int);
};

