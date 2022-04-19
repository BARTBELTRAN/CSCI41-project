//CityManip.h holds the struct and class inorder to
//set up the linked list to hold city nodes and data

#pragma once
#include<iostream>
#include<fstream>
#include "City.h"
using namespace std;

//Holds the next city pointer and city data
struct cityNode
{
	cityNode* nextCity = nullptr;	//Pointer to next node
	City cityData;			//Holds name and the number of hospitalizations
};

//Holds the functions and varibles for city
//from the menu
class CityManip
{
private:
	cityNode* cityListHead = nullptr;	//Pointer to head node
	cityNode* cityListTail = nullptr;	//Pointer to tail node

	int cityLenght = 0;
	ofstream dataOut;
	ifstream dataIn;
	string cityName;

public:
	void addCity(City);		//Declares add city funtion, passes city object
	void removeCity(string);	//Declares remove city function, passes sting
	void printCities();		//Declares print city funtion
	void cityFilesOutput();		//Delcares file output function, updates file
	void searchCity(string);	//Delcares search function, returns city if found
	void readFile();		//Delcares read file function
	CityManip() {			//Constructor to with readfile
		readFile();
	}
};
