//function definitions for the hash, search, add, and delete

//Bart Beltran
//Project 6 Hash tables
//Function definitions for hash table

#include "applicantStatistics.h"

//hashes a key value
int applicantStatistics::Hash(string key)
{
	unsigned val = 54;
	
	for (char element: key)
	{
		val *= 37487;
		val += element * 2749;
	}
	return val % 7;		//0 - 6 buckets
}

//searches for a allergy type
int applicantStatistics::searchHash(string allergen)
{
	int bucket = Hash(allergen);

	return hashTable[bucket].search(allergen);
}

//searches for an age
int applicantStatistics::searchHash(int yearsOld)
{
	int bucket = Hash(to_string(yearsOld));

	return hashTable[bucket].search(yearsOld);
}

//adds value to bucket for strings
void applicantStatistics::addHash(string allergy)
{
	int bucket = Hash(allergy);
	
	hashTable[bucket].add(allergy);

}

//add value to bucket for integers
void applicantStatistics::addHash(int age)
{	
	int bucket = Hash(to_string(age));

	hashTable[bucket].add(age);
	
}

//delets value in bucket for strings
void applicantStatistics::deleteHash(string allergy)
{
	int bucket = Hash(allergy);

	hashTable[bucket].deleteNode(allergy);
}

//delets value in bucket for integers
void applicantStatistics::deleteHash(int age)
{
	int bucket = Hash(to_string(age));

	hashTable[bucket].deleteNode(age);
}

//reads in acceptedApplicants.txt file
void applicantStatistics::readFile(bool ageAllergyOpt)
{
	fstream dataIn;
	int integer;	//used to set and ignore data
	string input;	//used to set and ignore data

	dataIn.open("acceptedApplicants.txt");

	getline(dataIn, input, '\n');		//ignore for line in txt file

	if (ageAllergyOpt)		//checks for integer
	{
		//only uses int as addHash parameter
		while (getline(dataIn, input, '\t'))
		{
			dataIn >> integer;
			addHash(integer);
			dataIn >> input >> input >> input;
		}
	}
	//checks for string
	else
	{
		//only uses string as addhash parameter
		while (getline(dataIn, input, '\t'))
		{
			dataIn >> integer >> input;
			addHash(input);
			dataIn >> input >> input;
		}
	}
}

void applicantStatistics::outputFile(bool ageAllergyOpt)
{
	fstream dataOut;

	//only uses int as addHash parameter
	for (size_t i = 0; i < 7; i++)
	{
		hashTable[i].outputList(ageAllergyOpt);
	}
}
