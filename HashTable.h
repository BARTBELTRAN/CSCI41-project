#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


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
	Hash** names; //declaration for an array of pointers named names
	Hash** dummyNode; //declaration for an array of pointers named dummyNode
public:
	ifstream fileIn;
	ofstream fileOut;
	int size = 8;
	hashTable();
	void insert(string key, string value);
	int convertToAscii(string key);
	int keyCode(string key);
	void fileInput();
	string deleteHash(string key);
	string get(string key);
	void fileOutput();
	string addComma(string number);
	void viewCountry();
};