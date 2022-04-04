//Bart Beltran Justin Soun
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct Pollen
{
	string pollenName;			//Name of Pollen
	string typeOfGeography;		//Geography where pollen is found
	double numOfCases;			//Total number of cases
	double aveCases;			//Average number of cases
	int totalCases;				//Total number of types of pollen
	double pollenPercentage;
	double totalPollenCases;
	double calcPercent() {
		return (numOfCases
			/ totalPollenCases) * 100;
	}
};

class PollenArray
{
public:
	void readPollen();

	int countPollen();

	void AddPollen(Pollen pollenName);

	void deletePollen(string erase);

	int searchPollen(string search);

	void printPollen();

	void fileOutput();

	void mergeAscending(int const, int const, int const);

	void mergeSortAscending(int const,int const);

	void mergeDescending(int const, int const, int const);

	void mergeSortDescending(int const, int const);

	int getPollenSize()
	{
		return pollenSize;
	}

	PollenArray() {
		pollenSize = countPollen();
		ptrPollen = new Pollen[pollenSize];
		readPollen();
	}

private:

	Pollen* tempPollen;
	int pollenSize;
	Pollen* ptrPollen;

};
