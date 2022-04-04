#pragma once
#include "CityManip.h"

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

void CityManip::removeCity(string)
{

}

void CityManip::printCities()
{
}
