#pragma once
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

public:
	void addCity(City);
	void removeCity(string);
	void printCities();				//Prints all cities
};
