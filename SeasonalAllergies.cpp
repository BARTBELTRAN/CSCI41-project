//Bart Beltran Justin Soun
#pragma once
#include "SeasonalAllergy.h"

void PollenArray::readPollen() {
	ifstream fileIn;
	ofstream fileOut;
	Pollen pol1;
	string pollenData;

	fileIn.open("pollen.txt");


	for (size_t i = 0; i < pollenSize; i++)
	{
		fileIn >> pollenData;
		

		if (pollenData.find('*') != string::npos)
		{
			pollenData.erase(pollenData.find('*'), 1);
			pol1.pollenName = pollenData;
		}
		
		fileIn >> pol1.typeOfGeography >> pol1.numOfCases
			>> pol1.totalPollenCases;

		ptrPollen[i] = pol1;
	}

}


int PollenArray::countPollen()
{
	int num = 0;
	string line;
	fstream fileIn;

	fileIn.open("pollen.txt");

	while (getline(fileIn, line))
	{
		if (line.find('*') != string::npos)
		{
			num++;
		}
	}

	fileIn.close();
	return num;
}


void PollenArray::AddPollen(Pollen pollenName)
{
	tempPollen = new Pollen[pollenSize];

	for (int i = 0; i < pollenSize; i++)
	{
		tempPollen[i] = ptrPollen[i];
	}

	delete[] ptrPollen;
	ptrPollen = new Pollen[pollenSize + 1];

	for (int i = 0; i < pollenSize; i++)
	{
		ptrPollen[i] = tempPollen[i];
	}

	ptrPollen[pollenSize] = pollenName;

	delete[] tempPollen;

	pollenSize++;
}

void PollenArray::deletePollen(string erase)
{
	searchPollen(erase);

	while (searchPollen(erase) == -1) {
		cout << "Please enter a valid country to delete: ";
		getline(cin, erase);
	}
	tempPollen = new Pollen[pollenSize];
	for (int i = 0; i < pollenSize; i++)
	{
		tempPollen[i] = ptrPollen[i];
	}
	delete[] ptrPollen;

	ptrPollen = new Pollen[pollenSize - 1];

	int j = 0;
	for (int i = 0; i < pollenSize; i++)
	{

		if (tempPollen[i].pollenName != erase)
		{
			ptrPollen[j] = tempPollen[i];
			j++;
		}
	}

	delete[] tempPollen;

	pollenSize--;
}

int PollenArray::searchPollen(string search){
	for (int i = 0; i < pollenSize; ++i){
		if (ptrPollen[i].pollenName == search) {
			return i;
		}
	}
		return -1;

}

//*********************************************************************************
//This function outputs the pollen name along with the percentage of pollen cases
// a certain pollen takes up in a certain area.
//*********************************************************************************
void PollenArray::printPollen() {
	for (int i = 0; i < pollenSize; i++) {
		cout << "Total number of " << ptrPollen[i].pollenName <<
			" pollen cases is " << ptrPollen[i].numOfCases << endl <<endl;
	}
}
//*********************************************************************************
//This function outputs to an external file the total number of pollen cases for a 
// certain pollen
//*********************************************************************************
void PollenArray::fileOutput() {
	ofstream fileOut;
	fileOut.open("pollenUpdate.txt");

	for (int i = 0; i < pollenSize; i++) {
		fileOut << "Total number of " << ptrPollen[i].pollenName <<
			" pollen cases is " << ptrPollen[i].numOfCases << endl;
		
	}
}

void PollenArray::mergeAscending(int const left, int const mid, int const right)
{
int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;
	

	Pollen* leftArray = new Pollen[subArrayOne];
	Pollen* rightArray = new Pollen[subArrayTwo];

	for (int i = 0; i < subArrayOne; i++)
		leftArray[i] = ptrPollen[left + i];
	for (int j = 0; j < subArrayTwo; j++)
		rightArray[j] = ptrPollen[mid + 1 + j];

	int indexOfSubArrayOne = 0, 
		indexOfSubArrayTwo = 0; 
	int indexOfMergedArray = left; 

	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne].calcPercent()<= rightArray[indexOfSubArrayTwo].calcPercent()) {
			ptrPollen[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			ptrPollen[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	while (indexOfSubArrayOne < subArrayOne) {
		ptrPollen[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	while (indexOfSubArrayTwo < subArrayTwo) {
		ptrPollen[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

void PollenArray::mergeSortAscending(int const begin, int const end)
{
	if (begin >= end)
		return; 

	int mid = begin + (end - begin) / 2;
	mergeSortAscending(begin, mid);
	mergeSortAscending(mid + 1, end);
	mergeAscending(begin, mid, end);
}

void PollenArray::mergeDescending(int const left, int const mid, int const right)
{
	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;


	Pollen* leftArray = new Pollen[subArrayOne];
	Pollen* rightArray = new Pollen[subArrayTwo];

	for (int i = 0; i < subArrayOne; i++)
		leftArray[i] = ptrPollen[left + i];
	for (int j = 0; j < subArrayTwo; j++)
		rightArray[j] = ptrPollen[mid + 1 + j];

	int indexOfSubArrayOne = 0,
		indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;

	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
	{
		if (leftArray[indexOfSubArrayOne].calcPercent() > rightArray[indexOfSubArrayTwo].calcPercent())
		{
			ptrPollen[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			ptrPollen[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	while (indexOfSubArrayOne < subArrayOne) {
		ptrPollen[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	while (indexOfSubArrayTwo < subArrayTwo) {
		ptrPollen[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}


}

void PollenArray::mergeSortDescending(int const begin, int const end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSortDescending(begin, mid);
	mergeSortDescending(mid + 1, end);
	mergeDescending(begin, mid, end);

}