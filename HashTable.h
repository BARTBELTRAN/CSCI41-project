#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int SIZE = 8;

class Hash {
private:
	string key;
	string value;

public:
	Hash(string key, string value) {
		this->key = key;
		this->value = value;
	}

	string getKey() { return key; }
	string getValue() { return value; }
};

class hashTable {
private:
	Hash** names;
	Hash** dummyNode;
public:
	ifstream fileIn;
	ofstream fileOut;

	hashTable();
	void put(string key, string value);
	int convertToAscii(string key);
	int keyCode(string key);
	void fileInput();
	string deleteHash(string key);
	string get(string key);
};