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
	int numAllergicReactions;		//Holds alergic reactions data
	int numHospitalizations;		//Holds hospitalizaton data
public:
	
	//Default constructor
	City() {
		numAllergicReactions = 0;
		numHospitalizations = 0;
	}

	//Function declaration

	void setNumAllergicReactions(int  allergicReactions) { numAllergicReactions = allergicReactions; }

	void setNumHospitalizations(int hospitalizations) { numHospitalizations = hospitalizations; }

	int getNumAllergicReactions() { return numAllergicReactions; }

	int getNumHospitalizations() {return numHospitalizations; }

};
