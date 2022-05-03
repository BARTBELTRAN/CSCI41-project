#pragma once
#include "string"
#include "fstream"
using namespace std;

class liveCity {
private:
	liveCity* cities = nullptr;
	int top = 0;
	string nameOfCity = "";
	string topAllergy = "";
public:
	ifstream fileIn;
	ofstream fileOut;
	int numOfCities = 0;
	int size = 0;
	void push(liveCity&);
	liveCity pop();
	liveCity peek();
	void fileInput();
	void fileOutput();
	liveCity(const liveCity& temp);
	liveCity operator=(const liveCity&);
	void cityComparison(string);
	bool isEmpty();
	~liveCity();
	
	void setNameOfCity(string cityName) { nameOfCity = cityName; }
	void setTopAllergy(string allergyInfo) { topAllergy = allergyInfo; }
	string getNameOfCity() { return nameOfCity; }
	string getTopAllergy() { return topAllergy; }
	
	liveCity() {
		size = numOfCities;
		top = -1;
		cities = new liveCity[size];
	}
};
