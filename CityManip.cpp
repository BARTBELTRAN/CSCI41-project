#pragma once
#include "CityManip.h"
#include <windows.h>

//*************************************************
//Add city function adds a city and the number of
//hospitalization and number of alergic reactions
//*************************************************
void CityManip::addCity(City cityIn)
{
	cityNode* tempNode = new cityNode;
	tempNode->cityData = cityIn;

	if (cityListHead == nullptr)
	{
		cityListHead = tempNode;
		cityListTail = tempNode;
	}
	else
	{
		cityListTail->nextCity = tempNode;
		cityListTail = tempNode;
	}
}

//*************************************************
//Remove city function removes city along with city
//data from the list of cities. Returns not found
//if invalid data is entered
//*************************************************
void CityManip::removeCity(string cityOut)
{
	cityNode* tempNode = cityListHead;
	cityNode* deleteNode = nullptr;

	if (tempNode != nullptr)
	{
		if (tempNode->cityData.getName() == cityOut)
		{
			cityListHead = tempNode->nextCity;
			delete tempNode;
			tempNode = nullptr;
		}
		while (tempNode != nullptr)
		{
			if (tempNode->nextCity->cityData.getName() == cityOut)
			{
				deleteNode = tempNode->nextCity;
				tempNode->nextCity = deleteNode->nextCity;
			}
			tempNode = tempNode->nextCity;
		}
	}
	else
	{
		cout << "Data not found";
	}

	delete deleteNode;
}

//************************************************
//print cities function prints all cities and city
//data to the output for the user to view
//************************************************

void CityManip::printCities()
{
	cityNode* tempNode = cityListHead;
	
	while (tempNode != nullptr)
	{
		cout << tempNode->cityData.getName() << endl;
		cout << "Number of allergic reactions: " << tempNode->cityData.getNumAllergicReactions() << endl;
		cout << "Number of hospitalizations: " << tempNode->cityData.getNumHospitalizations() << endl;
		cout << endl;
		tempNode = tempNode->nextCity;
	}

}

//*****************************************************
//city files output function updates the external file
//*****************************************************
void CityManip::cityFilesOutput()
{
	cityNode* tempNode = cityListHead;

	dataOut.open("city.txt");

	while (tempNode != nullptr)
	{
		dataOut << tempNode->cityData.getName() << " ";
		dataOut << tempNode->cityData.getNumAllergicReactions() << " ";
		dataOut << tempNode->cityData.getNumHospitalizations() << endl;
		tempNode = tempNode->nextCity;
	}

	dataOut.close();
}

//******************************************************
//search city function searches for for a city based on
//the users input
//******************************************************
void CityManip::searchCity(string search)
{
	cityNode* tempNode = cityListHead;
	cityNode* deleteNode = nullptr;
	bool found = false;

	while (tempNode != nullptr)
	{
		if (tempNode->cityData.getName() == search)
		{
			found = true;
			cout << tempNode->cityData.getName() << endl;
			cout << "Number of allergic reactions: " << tempNode->cityData.getNumAllergicReactions() << endl;
			cout << "Number of hospitalizations: " << tempNode->cityData.getNumHospitalizations() << endl;
			cout << endl;
			break;
		}
		tempNode = tempNode->nextCity;
	}
	if (!found)
	{
		cout << "Data was not found!\n";
	}
	
}

//*******************************************************
//Read file function reads data from an external file and
//stores data in a temporary location
//*******************************************************
void CityManip::readFile()
{
	City tempCity;	//Temporary city object to store data
	string cityName;
	int cityReactions, cityHospitalizations;

	dataIn.open("city.txt");

	while (dataIn >> cityName)
	{
		
		tempCity.setName(cityName);
		dataIn >> cityReactions;
		tempCity.setNumAllergicReactions(cityReactions);
		dataIn >> cityHospitalizations;
		tempCity.setNumHospitalizations(cityHospitalizations);
		addCity(tempCity);
	}
	dataIn.close();
}