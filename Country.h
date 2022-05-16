//Holds the country class and multiple variables for the country
//class
#pragma once
#include <string>
using namespace std;


//*********************************************************
//Class definition of country setting country and allergy 
//names and setting default values for country and allergies
//
//*********************************************************
class Country
{
private:
protected:
	string name;
	string allergyType;
	int population;
	int milk;
	int peanut;
	int treeNut;
	int fish;
	int egg;
	int wheat;
	int soy;
	int seasame;
	int shellfish;

public:
	//Default Counstructor
	Country()
	{
		string allergyType = " ";
		milk = 0;
		peanut = 0;
		treeNut = 0;
		fish = 0;
		egg = 0;
		wheat = 0;
		soy = 0;
		seasame = 0;
		shellfish = 0;

	}

	//Mutators
	

	void setPop(int countryPop) { population = countryPop;}

	void setName(string countryName) { name = countryName; }

	void setAllergyType(string allergy) { allergyType = allergy; }

	void setMilk(int numMilk) { milk = numMilk; }

	void setPeanut(int numPeanut) { peanut = numPeanut; }

	void setTreeNut(int numTreeNut) { treeNut = numTreeNut; }

	void setFish(int numFish) { fish = numFish; }

	void setEgg(int numEgg) { egg = numEgg; }

	void setWheat(int numWheat) { wheat = numWheat; }

	void setSoy(int numSoy) { soy = numSoy; }

	void setSeasame(int numSeasame) { seasame = numSeasame; }

	void setShellfish(int numShellfish) { shellfish = numShellfish; }

	//Accessors

	string getName() { return name; }

	string getAllergyType() { return allergyType; }

	int getMilk() { return milk; }

	int getPeanut() { return peanut; }

	int getTreeNut() { return treeNut; }

	int getFish() { return fish; }

	int getEgg() { return egg; }

	int getWheat() { return wheat; }

	int getSoy() { return soy; }

	int getSeasame() { return seasame; }

	int getShellfish() { return shellfish; }

	int getPop() { return population; }

};