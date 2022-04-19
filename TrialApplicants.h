#pragma once
#include <string>
#include <fstream>

using namespace std;

struct Trial
{
	Trial* nextApp = nullptr;
	string name;
	int age;
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

};

