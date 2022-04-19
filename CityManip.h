#pragma once
#include<iostream>
#include<fstream>
#include "City.h"
using namespace std;

struct cityNode
{
	cityNode* nextCity = nullptr;
	City cityData;
};


class CityManip
{
private:
	cityNode* cityListHead = nullptr;
	cityNode* cityListTail = nullptr;

	int cityLenght = 0;
	ofstream dataOut;
	ifstream dataIn;
	string cityName;

public:
	void addCity(City);
	void removeCity(string);
	void printCities();
	void cityFilesOutput();
	void searchCity(string);
	void readFile();
	CityManip() {
		readFile();
	}
};