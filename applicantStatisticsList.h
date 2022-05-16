//Link list function declarations to be used with hash functions
//based on accepted applicants

//Bart Beltran
// Project 6 Hash tables
//Linked list used for hash table in applicantStatistics
#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//characteristics of node
struct AppNode
{
	AppNode* nextNode = nullptr;	//pointer to next node
	int age;
	string allergy;
	int count = 0;						// increments when node found in hash table
};

//linked list functions to use with hash table
class applicantStatisticsList
{
private:
	AppNode* head = nullptr;		//pointer to head node
	AppNode* tail = nullptr;		//pointer to tail node

public:
	void add(string);			//add allergy to hash table
	void add(int);				//add age to hash table
	int search(string) const;		//search allergy in hash table
	int search(int) const;			//search age in hash table
	void deleteNode(string);	//delede string hash table
	void deleteNode(int);		//delete int in hash tabel
	void outputList(bool);		//output to external file
};

