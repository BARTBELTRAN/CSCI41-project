//linked list function definitions used in conjunction with hash
//functinos based on accepted applicants

//Bart Beltran
//Project 6 hash tables
//Function defintions for link list in hash table
#include "applicantStatisticsList.h"

//adds allergy type and increments count if type exists
void applicantStatisticsList::add(string allergen)
{
	AppNode* tempNode;

	if (search(allergen) == 0)		//new allergy type
	{
		tempNode = new AppNode;		//create new node
		
		tempNode->allergy = allergen;		//passes allergy data type

		tempNode->count++;			//increments count

		//if list is empty temp node is head and tail
		if (head == nullptr)
		{
			head = tempNode;
			tail = tempNode;
		}
		else
		{
			tail->nextNode = tempNode;		//list not empty, new node becomes tail
			tail = tempNode;
		}
	}
	else
	//existing allergy type
	{
		tempNode = head;

		//tranverses the list and incrments allgery type when found
		while (tempNode != nullptr)
		{
			if (tempNode->allergy == allergen)
			{
				tempNode->count++;
				break;
			}

			tempNode = tempNode->nextNode; //next node to check
		}
	}
}

//adds age and incrments age count if age already exists
void applicantStatisticsList::add(int yearsOld)
{

	AppNode* tempNode;

	if (search(yearsOld) == 0)		//creates new age
	{
		tempNode = new AppNode;		//makes new node

		tempNode->age = yearsOld;	//tempNode receves age data

		tempNode->count++;			//increments count

		//if list is empty tempnode is head and tail
		if (head == nullptr)
		{
			head = tempNode;
			tail = tempNode;
		}
		else
		//else tempnode becomes tail
		{
			tail->nextNode = tempNode;
			tail = tempNode;
		}
	}
	else
	{
		tempNode = head;

		//tranverses the list and increments all instances of age value
		while (tempNode != nullptr)
		{
			if (tempNode->age == yearsOld)
			{
				tempNode->count++;
				break;
			}

			tempNode = tempNode->nextNode;	//goes to next node
		}

	}

}

//searches for an allergy type
int applicantStatisticsList::search(string allergen)
{
	AppNode* tempNode = head;
	AppNode* deleteNode = nullptr;
	bool found = false;


	while (tempNode != nullptr)
	{
		if (tempNode->allergy == allergen)
		{
			found = true;
			return tempNode->count;
			break;
		}
		tempNode = tempNode->nextNode;
	}
	if (!found)
	{
		cout << "Data was not found!\n";
		return 0;
	}

}

//searches for an age
int applicantStatisticsList::search(int yearsOld)
{
	AppNode* tempNode = head;
	AppNode* deleteNode = nullptr;
	bool found = false;


	while (tempNode != nullptr)
	{
		if (tempNode->age == yearsOld)
		{
			found = true;
			return tempNode->count;
			break;
		}
		tempNode = tempNode->nextNode;
	}
	if (!found)
	{
		cout << "Data was not found!\n";
		return 0;
	}

}

//deletes allergen
void applicantStatisticsList::deleteNode(string allergen)
{
	AppNode* tempNode = head;
	AppNode* deleteNode = nullptr;


	if (tempNode != nullptr)
	{
		if (tempNode->allergy == allergen)
		{
			head = tempNode->nextNode;
			delete tempNode;
			tempNode = nullptr;
		}
		while (tempNode != nullptr)
		{
			if (tempNode->nextNode->allergy == allergen)
			{
				deleteNode = tempNode->nextNode;
				tempNode->nextNode = deleteNode->nextNode;
			}
			tempNode = tempNode->nextNode;
		}
	}
	else
	{
		cout << "Data not found";
	}

	delete deleteNode;
}

//delets age
void applicantStatisticsList::deleteNode(int yearsOld)
{
	AppNode* tempNode = head;
	AppNode* deleteNode = nullptr;

	if (tempNode != nullptr)
	{
		if (tempNode->age == yearsOld)
		{
			head = tempNode->nextNode;
			delete tempNode;
			tempNode = nullptr;
		}
		while (tempNode != nullptr)
		{
			if (tempNode->nextNode->age == yearsOld)
			{
				deleteNode = tempNode->nextNode;
				tempNode->nextNode = deleteNode->nextNode;
			}
			tempNode = tempNode->nextNode;
		}
	}
	else
	{
		cout << "Data not found";
	}
	delete deleteNode;
}

