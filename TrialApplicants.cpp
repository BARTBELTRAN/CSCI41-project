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
	ifstream dataIn;					//Holds values from the newapplicants list
	Trial* newNode = new Trial;			//Creates a new node from the trial struct
	string preCondition;				//Holds a value for a pre existing condition
	
	dataIn.open("newApplicants.txt");		//Opens newApplicants file
	
	getline(dataIn, preCondition, '\n');		//Ignores the first line of the external file

	//while loop reads in name, age, aggergy, pre condition, and 
	//date of application
	while (getline(dataIn, newNode->name, '\t'))
	{
		dataIn >> newNode->age >> newNode->allergens >> preCondition >>
			newNode->date;

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

//******************************************************
//Enqueue function adds node and into the front of the
//queue from the buildApplicantList function
//******************************************************
void TrialApplicantQueue::enqueue(Trial* appNode)
{
	if (trialFront == nullptr)		//checks for empty queue
	{
		trialFront = appNode;		//appNode becomes head
		trialRear = appNode;		//appNode becomes tail
	}
	else {								//queue is not empty
		trialRear->nextApp = appNode;	//tails next points to appNode
		trialRear = appNode;			//appNode becomes tail
	}
}

//************************************************************
//Outputs queued list to the external file, newApplicants.txt
//************************************************************
void TrialApplicantQueue::fileOut()
{
	fstream dataOut("newApplicants.txt");
	Trial* traverse = trialFront;			//traverse stars at head

	//user categories
	dataOut << "Name\t\tAge\t\tAllergy\t\tPre-Existing Condition\t\tDate\n";
	
	while (traverse != nullptr)		//check if traverse had data
	{
		//outputs user info
		dataOut << traverse->name << "\t\t" << traverse->age << "\t\t" <<
			traverse->allergens << "\t\t";
		
		//bool value, changes output to yes or no
		if (traverse->preExistCondion)		
		{
			dataOut << "yes";
		}
		else
		{
			dataOut << "no";
		}
		dataOut << "\t\t\t";

		dataOut << traverse->date << endl;

		traverse = traverse->nextApp;	//points to next user in list or null
	}

}

//***************************************************
// Dequeues applicant node out of the list
//***************************************************
void TrialApplicantQueue::dequeue()
{
	Trial* temp = trialFront;		//Sets temporary node to head

	if (temp != nullptr)		//Whlie queue is not empty
	{
		trialFront = trialFront->nextApp;	//trialFront point to next node

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
	bool age;				//holds user age
	bool check = false;		//holds bool for potential applicants
	int enter;				//used to manipulate menu

	ofstream dataOutNew("newApplicants.txt");
	ofstream dataOutAccept("acceptedApplicants.txt", fstream::app); //opens in append mode

	dataOutNew << "Name\t\tAge\t\tAllergy\t\tPre-Existing Condition\t\tDate\n";

	//goes through the list
	while (trialFront != nullptr)
	{
		if (trialFront->age >= 8 && trialFront->age <= 80)		//does not accept aplicants too young or old
		{
			age = true;
		}
		else
		{
			age = false;
		}

		if (trialFront->preExistCondion && age)		//must have pre-existing condition and correct age
		{
			check = true;		//initialize check

			//Sub menu for potential applicant
			cout << trialFront->name << " is a potential applicant\n";
			cout << "Press 1 to accept " << trialFront->name <<
				" or 2 to decline " << trialFront->name << endl;
			cin >> enter;
			cout << "\n";
			switch (enter)
			{
			//Outputs to accepted applicant file
			case 1: dataOutAccept << trialFront->name << "\t" << trialFront->age << "\t\t" <<
				trialFront->allergens << "\t\t";

				if (trialFront->preExistCondion) 
				{
					dataOutAccept << "yes";
				}
				else {
					dataOutAccept << "no";
				}
				
				dataOutAccept << "\t\t\t\t" << trialFront->date << endl;
			break;
			//Outputs to potental applicants
			case 2:dataOutNew << trialFront->name << "\t" << trialFront->age << "\t\t" <<
				trialFront->allergens << "\t\t";

				if (trialFront->preExistCondion)
				{
					dataOutNew << "yes";
				}
				else {
					dataOutNew << "no";
				}

				dataOutNew << "\t\t\t\t" << trialFront->date << endl;
			break;
			default:
				break;
			}
		}
		dequeue();	//call to dequeue function
	}

	if (!check) {
		cout << "No qualifying applicants were found in the list\n";
	}

	buildApplicantList();	//rebuild applicant list
}

//*******************************************************************
//Sets the applicant information corresponding to the Trial* struct,
// name, age, allergy type, pre-existing condition and date
//*******************************************************************
Trial* TrialApplicantQueue::getAppInfo()
{
	Trial* newInfo;			//holds the info of applicants
	newInfo = new Trial;	//dynamic node
	string check;			//holds value of pre-existing condition

	cin.ignore();		//ignores check value, getline used right after

	cout << "Please enter your name" << endl;		//gets name
	getline(cin, newInfo->name);
	cout << "\n";
	cout << "Please enter your age" << endl;		//gets age
	cin >> newInfo->age;						
	cout << "\n";
	cout << "What are you allergic to(please only enter one allergy)" << endl;	//gets allergy type
	cin >> newInfo->allergens;
	cout << "\n";
	//check for pre-existing condition
	do
	{
		cout << "Do you have any pre existing conditions(enter yes or no)" << endl;
		cin >> check;
		cout << "\n";
		//handles erroneous error for check value
		for (int i = 0; i < check.length(); ++i)
		{
			check.at(i) = tolower(check.at(i));	//changes check to lower case
		}

		if (check == "yes")
		{
			newInfo->preExistCondion = true;
		}
		else
		{
			newInfo->preExistCondion = false;
		}

	} while (check != "yes" && check != "no");

	cout << "Please enter todays date" << endl;		//gets date
	cin >> newInfo->date;	
	cout << "\n";
	return newInfo;	//returns info of newInfo
}