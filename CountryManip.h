#pragma once
#include <iostream>
#include <fstream>
#include "Country.h"

using namespace std;

//**************************************************
//The DynamicArray class stores multiple variables
// mainly used to obtain a value for a dynamic array
// of multiple countries and 
//
class CountryArray
{
private:
	int countrySize = 0;			//Holds the size of counties in the list
	Country* Array = nullptr;		//Dynamic array to hold new country values
	Country* tempArray = nullptr;	//Dynamic array used to hold copy of Array for manip
	fstream dataIn;
	ofstream dataOut;


public:
	CountryArray();						//initiates number of countries and updates user list

	void readFile();					//reads data from file

	int countCountry();					//Counts number of counties in file

	void Print() const;					//Prints data to user

	void addCountry(Country);			//Resizes the array to add a new country

	void deleteCountry(string);         //Searches the array for an element and deletes it

	void fileOutput();					//Outputs data to external file

	int searchArray(string);            //Searches the array for a specific element

	
	void mergeAscending(int const, int const, int const);

	void mergeSortAscending(int const,int const);

	void mergeDescending(int const, int const, int const);

	void mergeSortDescending(int const, int const);
	
	int binarySearch(int, int, string);
	
	void printCountryNames();

	int sizeOfCountry();

};

