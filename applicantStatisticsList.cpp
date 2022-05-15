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
int applicantStatisticsList::search(string allergen) const
{
	AppNode* tempNode = head;		//initialize tempnode to head

	//travers the list
	while (tempNode != nullptr)		//while not nullptr
	{
		if (tempNode->allergy == allergen)	//if parameter is found in list
		{
			return tempNode->count;			//return count
		}
		tempNode = tempNode->nextNode;
	}
	return 0;

}

//searches for an age
int applicantStatisticsList::search(int yearsOld) const
{
	AppNode* tempNode = head;			//initialize tempnode to head

	//travers the list
	while (tempNode != nullptr)			//while not nullptr
	{
		if (tempNode->age == yearsOld)	//if parameter is found in list
		{
			return tempNode->count;		//return count
		}
		tempNode = tempNode->nextNode;
	}
	return 0;
}

//deletes allergen
void applicantStatisticsList::deleteNode(string allergen)
{
	AppNode* tempNode = head;			//initalize tempNode to head
	AppNode* deleteNode = nullptr;		//initalize deleteNode to nullptr

	//traverse the list
	if (tempNode != nullptr)
	{
		if (tempNode->allergy == allergen)		//if paramter is found
		{
			head = tempNode->nextNode;			//head is next node in list
			delete tempNode;					//delete current node
			tempNode = nullptr;
		}
		//travers the list
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
	AppNode* tempNode = head;				//initalize tempNode to head
	AppNode* deleteNode = nullptr;			//initalize deleteNode to nullptr

	if (tempNode != nullptr)
	{
		if (tempNode->age == yearsOld)			//if paramter is found
		{
			head = tempNode->nextNode;			//head is next node in list
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

//Determins which external file to send data to, depending on 
//age or allergy type
void applicantStatisticsList::outputList(bool ageAllergyOpt)
{
	fstream dataOut;			//out put data
	AppNode* temp = head;		//intialize temp to head

	if (ageAllergyOpt)		//if true, go to int
	{
		dataOut.open("ageData.txt", fstream::app);

		while (temp != nullptr)
		{
			dataOut << temp->age << "\t" << temp->count << endl;

			temp = temp->nextNode;
		}
		dataOut.close();
	}
	else
	{	//if fasle to sto string
		dataOut.open("allergyHash.txt", fstream::app);

		while (temp != nullptr)
		{
			dataOut << temp->allergy << "\t" << temp->count << endl;

			temp = temp->nextNode;
		}
		dataOut.close();
	}
}


