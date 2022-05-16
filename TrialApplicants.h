//Bart Beltran
//contains the struct for Trial info and the trialapplicationqueue
//and the privte nodes for the queue and all the functions for
//application menu
#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

//Holds the information of applicant and node for queue
struct Trial
{
	Trial* nextApp = nullptr;	//next pointer
	string name;
	int age;
	string date;
	bool preExistCondion;
	string allergens;
};

class TrialApplicantQueue
{
private:
	Trial* trialFront = nullptr;	//head node
	Trial* trialRear = nullptr;		//tail node

	ofstream dataOut;
	ifstream dataIn;

public:
	
	void buildApplicantList();
	void enqueue(Trial*);
	void fileOut();
	void dequeue();
	void reviewApplicants();
	Trial* getAppInfo();
	TrialApplicantQueue(){
		buildApplicantList();	//buildApplicationList constructor to build at start
	}

};
