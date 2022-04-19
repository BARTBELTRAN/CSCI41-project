#pragma once
#include "CityManip.h"
#include <windows.h>

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

void CityManip::printCities()
{
	cityNode* tempNode = cityListHead;
	
	while (tempNode != nullptr)
	{
		cout << tempNode->cityData.getName() << endl;
		cout << tempNode->cityData.getNumAllergicReactions() << endl;
		cout << tempNode->cityData.getNumHospitalizations() << endl;

		tempNode = tempNode->nextCity;
	}

}

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
			cout << tempNode->cityData.getNumAllergicReactions() << endl;
			cout << tempNode->cityData.getNumHospitalizations() << endl;
			break;
		}
		tempNode = tempNode->nextCity;
	}
	if (!found)
	{
		cout << "Data was not found!\n";
	}
}

void CityManip::readFile()
{
	City tempCity;
	string cityName;
	int cityReactions;
	int cityHospitalizations;

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