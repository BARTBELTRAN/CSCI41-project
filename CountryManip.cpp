#include <fstream>
#include <iomanip>
#include "CountryManip.h"
#include "Country.h"

//*****************************************************
// DynamicArray constructor that call the countCountry
// to obtain integer for number of countries to store
// as dynamic array value. Also, calls readFile() to
// initialize all the values in the country class
//*****************************************************
CountryArray::CountryArray()
{
	countrySize = countCountry();
	Array = new Country[countrySize];
	readFile();
}

int CountryArray::sizeOfCountry()
{
	return countrySize;
}


//*********************************************************
//Function used to read names and data from external file 
//and store set the values into the country class variables
//*********************************************************
void CountryArray::readFile()
{
	//string outPut;
	string hold;			//Used as a place holder
	string countryData;
	int numData;			//Country population
	int milkData,
		  peanutData,
		  treeNutData,
		  fishData,
		  eggData,
		  wheatData,
		  soyData,
		  sesameData,
		  shellFishData;

	dataIn.open("allergyData.txt");

	for (size_t i = 0; i < countrySize; i++)
	{
		Country temp;

		getline(dataIn, countryData, ';');

		if (countryData.find('*') != string::npos)
		{
			countryData.erase(countryData.find('*'), 1);
			
			temp.setName(countryData);
			//cout << temp.getName() << endl;
			
			dataIn >> numData;
			temp.setPop(numData);

			dataIn >> hold;
			dataIn >> milkData;
			temp.setMilk(milkData);

			dataIn >> hold;
			dataIn >> peanutData;
			temp.setPeanut(peanutData);

			dataIn >> hold;
			dataIn >> treeNutData;
			temp.setTreeNut(treeNutData);

			dataIn >> hold;
			dataIn >> fishData;
			temp.setFish(fishData);

			dataIn >> hold;
			dataIn >> eggData;
			temp.setEgg(eggData);

			dataIn >> hold;
			dataIn >> wheatData;
			temp.setWheat(wheatData);

			dataIn >> hold;
			dataIn >> soyData;
			temp.setSoy(soyData);

			dataIn >> hold;
			dataIn >> sesameData;
			temp.setSeasame(sesameData);

			dataIn >> hold;
			dataIn >> shellFishData;
			temp.setShellfish(shellFishData);
			getline(dataIn, countryData, '\n');	//getline hold
			getline(dataIn, countryData, '\n');

			Array[i] = temp;
		}
	}

		
	dataIn.close();
	
}

//****************************************************
//Counts each instance of "*" in order to use value to
//initalize dynamic array with a specific value
//****************************************************
int CountryArray::countCountry()
{
	int num = 0;
	string line;

	dataIn.open("allergyData.txt");

	while (getline(dataIn, line))
	{
		if (line.find('*') != string::npos)
		{
			num++;
		}
	}

	dataIn.close();
	return num;
}

//*****************************************************
//addCountry function adds a user selected country when 
// called upon in the menu function
//*****************************************************
void CountryArray::addCountry(Country countryName)
{
	tempArray = new Country[countrySize];

	for (int i = 0; i < countrySize; i++)
	{
		tempArray[i] = Array[i];
	}

	delete[] Array;
	Array = new Country[countrySize + 1];

	for (int i = 0; i < countrySize; i++)
	{
		Array[i] = tempArray[i];
	}

	Array[countrySize] = countryName;
		
	delete[] tempArray;
	
	countrySize++;
}


//*****************************************************************
//deleteCountry function deletes a user selected country when 
// called upon in the menu function
//*****************************************************************
void CountryArray::deleteCountry(string erase)
{
	searchArray(erase);
	
	while (searchArray(erase) == -1) {
		cout << "Please enter a valid country to delete: ";
		getline(cin, erase);
	}
	tempArray = new Country[countrySize];
	for (int i = 0; i < countrySize; i++)
	{
		tempArray[i] = Array[i];
	}
	delete[] Array;

	Array = new Country[countrySize - 1];

	int j = 0;
	for (int i = 0; i < countrySize; i++)
	{
		
		if (tempArray[i].getName() != erase)
		{
			Array[j] = tempArray[i];
			j++;
		}
	}

	delete[] tempArray;

	countrySize--;
}

//*****************************************************************
//print function outputs all of the country and allergy information
// to the user when called upon in the user menu.
//*****************************************************************
void CountryArray::Print() const
{
	char pressToContinue;
	for (int i = 0; i < countrySize; ++i)
	{
		cout << left << setw(25) << "Country" << "Population" << endl;
		cout << left << setw(25) << Array[i].getName() << Array[i].getPop() << endl << endl;
		cout << left << setw(25) << "Milk allergies: " << Array[i].getMilk() << endl;
		cout << left << setw(25) << "Peanut allergies: " << Array[i].getPeanut() << endl;
		cout << left << setw(25) << "Tree Nut allergies: " << Array[i].getTreeNut() << endl;
		cout << left << setw(25) << "Fish allergies: " << Array[i].getFish() << endl;
		cout << left << setw(25) << "Egg allergies: " << Array[i].getEgg() << endl;
		cout << left << setw(25) << "Wheat allergies: " << Array[i].getWheat() << endl;
		cout << left << setw(25) << "Soy allergies: " << Array[i].getSoy() << endl;
		cout << left << setw(25) << "Sesame allergies: " << Array[i].getSoy() << endl;
		cout << left << setw(25) << "Shell fish allergies: " << Array[i].getShellfish() << endl << endl;
		cout << "Input any character to continue viewing allergy data: ";
		cin >> pressToContinue;
		cout << endl;
	}
	
}

//******************************************************************
//fileOutput function updates updates all of the country and allergy
// information to an external file
//******************************************************************

void CountryArray::fileOutput()
{
	dataOut.open("allergyData.txt");

	for (int i = 0; i < countrySize; ++i)
	{
		dataOut << "*" << Array[i].getName() << ";" << '\t' <<'\t' << Array[i].getPop() << endl;
		dataOut << left << setw(20) << "Milk" << Array[i].getMilk() << endl;
		dataOut << left << setw(20) << "Peanut" << Array[i].getPeanut() << endl;
		dataOut << left << setw(20) << "Treenut" << Array[i].getTreeNut() << endl;
		dataOut << left << setw(20) << "Fish" << Array[i].getFish() << endl;
		dataOut << left << setw(20) << "Egg" << Array[i].getEgg() << endl;
		dataOut << left << setw(20) << "Wheat" << Array[i].getWheat() << endl;
		dataOut << left << setw(20) << "Soy" << Array[i].getSoy() << endl;
		dataOut << left << setw(20) << "Sesame" << Array[i].getSoy() << endl;
		dataOut << left << setw(20) << "Shellfish  " << Array[i].getShellfish() << endl << endl;
	}

	dataOut.close();
}

//******************************************************************
//searchArray iterates through the Array and sees if any item in the 
// Array matches the input from the user. If it matches, it will return
// the position, if not, it will return -1.
//******************************************************************
int CountryArray::searchArray(string search){
	for (int i = 0; i < countrySize; ++i){
		if (Array[i].getName() == search) {
			return i;
		}
	}
		return -1;

}

//*****************************************************************
//This function merges all elements in the array in ascending 
// order
//*****************************************************************
void CountryArray::mergeAscending(int const left, int const mid, int const right) {
	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;
	

	Country* leftArray = new Country[subArrayOne];
	Country* rightArray = new Country[subArrayTwo];

	for (int i = 0; i < subArrayOne; i++)
		leftArray[i] = Array[left + i];
	for (int j = 0; j < subArrayTwo; j++)
		rightArray[j] = Array[mid + 1 + j];

	int indexOfSubArrayOne = 0, 
		indexOfSubArrayTwo = 0; 
	int indexOfMergedArray = left; 

	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne].getName()<= rightArray[indexOfSubArrayTwo].getName()) {
			Array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			Array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	while (indexOfSubArrayOne < subArrayOne) {
		Array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	while (indexOfSubArrayTwo < subArrayTwo) {
		Array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}

}

//*****************************************************************
//This function splits up elements within the array using recursion
// then calls the mergeAscending function to put all the elements
// back into one array in ascending order
//*****************************************************************
void CountryArray::mergeSortAscending(int const begin, int const end) {
	if (begin >= end)
		return; 

	int mid = begin + (end - begin) / 2;
	mergeSortAscending(begin, mid);
	mergeSortAscending(mid + 1, end);
	mergeAscending(begin, mid, end);

}
//*****************************************************************
//This function merges all elements in the array in Descending 
// order
//*****************************************************************

void CountryArray::mergeDescending(int const left, int const mid, int const right) {
	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;


	Country* leftArray = new Country[subArrayOne];
	Country* rightArray = new Country[subArrayTwo];

	for (int i = 0; i < subArrayOne; i++)
		leftArray[i] = Array[left + i];
	for (int j = 0; j < subArrayTwo; j++)
		rightArray[j] = Array[mid + 1 + j];

	int indexOfSubArrayOne = 0, 
		indexOfSubArrayTwo = 0; 
	int indexOfMergedArray = left; 

	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) 
	{
		if (leftArray[indexOfSubArrayOne].getName() <= rightArray[indexOfSubArrayTwo].getName()) 
		{
			Array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			Array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	while (indexOfSubArrayOne < subArrayOne) {
		Array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	while (indexOfSubArrayTwo < subArrayTwo) {
		Array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}


}

//*****************************************************************
//This function splits up elements within the array using recursion
// then calls the mergeAscending function to put all the elements
// back into one array in ascending order
//*****************************************************************
void CountryArray::mergeSortDescending(int const begin, int const end) {
	if (begin >= end)
		return; 

	int mid = begin + (end - begin) / 2;
	mergeSortDescending(begin, mid);
	mergeSortDescending(mid + 1, end);
	mergeDescending(begin, mid, end);
}
//*****************************************************************
//BinarySearch utilizes recursion and splitting up the array multiple
// times. After this, it will search for a singular element of the 
// user's choosing then return that location of the value within 
// the array
//*****************************************************************
int CountryArray::binarySearch(int a, int b, string name) {
	mergeSortAscending(0, countrySize);

	if (a <= b) {
		int mid = (a + b) / 2;
		if (Array[mid].getName() == name)
			return mid;
		if (Array[mid].getName() > name)
			return binarySearch(a, mid + 1, name);
		if (Array[mid].getName() < name)
			return binarySearch(a, mid - 1, name);
	}
	return -1;
}

void CountryArray::printCountryNames() {
	for (int i = 0; i < countrySize; i++) {
		cout << Array[i].getName() << endl;
	}
}