//City class is the child class of the Country class
//with unique varialbe numAllergicReactions and 
//numHospitalizations that store data for the number 
//of hospitalizations.

#pragma once
#include "Country.h"
#include <string>


//initialization of inherited 
//class city
class City : public Country			//Call to country as public
{
private:
	string name;
	int population;
	int numAllergicReactions;		//Holds alergic reactions data
	int numHospitalizations;		//Holds hospitalizaton data
protected:
public:
	
	//Default constructor
	City() {
		name = " ";
		population = 0;
		numAllergicReactions = 0;
		numHospitalizations = 0;
	}

	//Function declaration
	void setName(string);
	void setPop(int);
	void setNumAllergicReactions(int);
	void setNumHospitalizations(int);
	string getName();
	int getPop();
	int getNumAllergicReactions();
	int getNumHospitalizations();

};

//Override functions
void City::setName(string cityName) {
	name = cityName;
}

void City::setPop(int cityPop) {
	population = cityPop;
}

string City::getName() {
	return name;
}

int City::getPop() {
	return population;
}

//Unique functions t
int City::getNumAllergicReactions() {
	return numAllergicReactions;
}

int City::getNumHospitalizations() {
	return numHospitalizations;
}

void City::setNumAllergicReactions(int allergicReactions) {
	numAllergicReactions = allergicReactions;
}

void City::setNumHospitalizations(int hospitalizations) {
	numHospitalizations = hospitalizations;
}