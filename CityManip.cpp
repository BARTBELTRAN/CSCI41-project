#pragma once
#include "CityManip.h"
#include <windows.h>


void CityManip::addCity(City cityIn)
{
	int begin = GetTickCount64();
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
	int after = GetTickCount64();
	cout << after - begin << " milliseconds have elapsed" << endl;
}

void CityManip::removeCity(string cityOut)
{
	int begin = GetTickCount64();
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
	int after = GetTickCount64();
	cout << after - begin << " milliseconds have elapsed." << endl;
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
	int before = GetTickCount64();
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
	int after = GetTickCount64();
	cout << after - before << " milliseconds have elapsed" << endl;
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



//add time complexity function