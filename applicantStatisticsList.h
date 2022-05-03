//Bart Beltran
// Project 6 Hash tables
//Linked list used for hash table in applicantStatistics
#pragma once
#include <string>
using namespace std;

//characteristics of node
struct AppNode
{
	AppNode* nextNode = nullptr;	//pointer to next node
	int age;
	string allergy;
	int count;						// increments when node found in hash table
};

//linked list functions to use with hash table
class applicantStatisticsList
{
private:
	AppNode* head = nullptr;		//pointer to head node
	AppNode* tail = nullptr;		//pointer to tail node

public:
	void add(string);	//FIXME	Add add for int
	void search();		//search in hash table
	void deleteNode();	//delede in hash table
};

