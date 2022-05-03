//Bart Beltran
//Project 6 Hash tables
//Function definitions for hash table

#include "applicantStatistics.h"

//hashes a key value
int applicantStatistics::Hash(string key)
{
	int val = 54;
	
	for (char element: key)
	{
		val *= 37487;
		val += element * 2749;
	}
	return val % 8;		//0 - 8 buckets
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

	hashTable[bucket].add(to_string(age));
	
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

	hashTable[bucket].deleteNode(to_string(age));
}
