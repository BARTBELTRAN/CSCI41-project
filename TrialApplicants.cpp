//Bart Beltran
//Trail application drivers. Contains all of the 
//function definitions for the trial application 
//queues
#include "TrialApplicants.h"

//**************************************************
//Retreves data from an external file and enters the 
//data into a queue.
//**************************************************
void TrialApplicantQueue::buildApplicantList()		//List of new applicants
{
	fstream dataIn;					//Holds values from the newapplicants list
	Trial* newNode = new Trial;		//Creates a new node from the trial struct
	string preCondition;			//Holds a value for a pre existing condition
	
	dataIn.open("newApplicants.txt");		//Opens newApplicants file
	
	dataIn.ignore(100, '\n');		//Ignores the first line of the external file

	//while loop reads in name, age, aggergy, pre condition, and 
	//date of application
	while (dataIn >> newNode->name >> newNode->age >> newNode->allergens >> preCondition >>
		newNode->date)
	{
		//Checks for a pre condition returning true 
		//or false
		if (preCondition == "yes")
		{
			newNode->preExistCondion = true;
		}
		else
		{
			newNode->preExistCondion = false;
		}

		enqueue(newNode);		//Adds patient data into queue

		newNode = new Trial;	//Moves to next node in the queue
	}
}

//*************************************************
//Enqueue function adds node and into the front of
// the que
//*************************************************
void TrialApplicantQueue::enqueue(Trial* appNode)
{
	if (trialFront == nullptr)
	{
		trialFront = appNode;
		trialRear = appNode;
	}
	else {
		trialRear->nextApp = appNode;
		trialRear = appNode;
	}
}

void TrialApplicantQueue::fileOut()
{
	fstream dataOut("newApplicants.txt");
	Trial* traverse = trialFront;

	dataOut << "Name\t\tAge\t\tAllergy\t\tPre-Existing Condition\t\tDate\n";
	
	while (traverse != nullptr)
	{

		dataOut << traverse->name << "\t\t" << traverse->age << "\t\t" <<
			traverse->allergens << "\t\t";
		
		if (traverse->preExistCondion)
		{
			dataOut << "yes\t\t";
		}
		else
		{
			dataOut << "no\t\t";
		}

		dataOut << traverse->date << endl;

		traverse = traverse->nextApp;
	}

}

void TrialApplicantQueue::dequeue()
{
	Trial* temp = trialFront;

	if (temp != nullptr)
	{
		trialFront = trialFront->nextApp;

		delete temp;
	}
}

//*************************************************************
//Reviews the potental applicants, if not accpted, then person
// is dequeued. If accepted, then person is moved to
// list of acctedted applicants
//*************************************************************
void TrialApplicantQueue::reviewApplicants()
{
	bool age;
	int enter;
	ofstream dataOutNew("newApplicants.txt");
	ofstream dataOutAccept("acceptedApplicants.txt", fstream::app);

	while (trialFront != nullptr)
	{
		if (trialFront->age >= 8 && trialFront->age <= 80)
		{
			age = true;
		}
		else
		{
			age = false;
		}

		if (trialFront->preExistCondion && age)
		{
			cout << trialFront->name << " is a potential applicant\n";
			cout << "Press 1 to accept " << trialFront->name <<
				" or 2 to decline " << trialFront->name << endl;
			cin >> enter;
			
			switch (enter)
			{
			case 1: dataOutAccept << trialFront->name << trialFront->age <<
				trialFront->allergens << trialFront->date << endl;
				dequeue();
				break;
			case2: dataOutNew << trialFront->name << trialFront->age <<
				trialFront->allergens << trialFront->date << endl;
			dequeue();
			break;
			default:
				break;
			}
		}
		
	}

}



//Good stuff
/*
cout << "Enter your current allergy type: \n";
	cout << "Enter 1 for food Allergy: \n Enter 2 for pollen allergy: \n";

	switch (enter)
	{
	case 1:
		cout << "Food Allergy";
		break;
	case 2:
		cout << "Pollen Allergy";
		break;
	default:
		break;
	}


*/