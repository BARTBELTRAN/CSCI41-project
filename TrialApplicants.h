#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

struct Trial
{
	Trial* nextApp = nullptr;
	string name;
	int age;
	int date;
	bool preExistCondion;
	string allergens;
};

class TrialApplicantQueue
{
private:
	Trial* trialFront = nullptr;
	Trial* trialRear = nullptr;

	ofstream dataOut;
	ifstream dataIn;

public:
	
	void buildApplicantList();
	void enqueue(Trial*);
	void fileOut();
	void dequeue();
	void reviewApplicants();
	TrialApplicantQueue(){
		buildApplicantList();
	}

};
