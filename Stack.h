#ifndef Stack.h
#define Stack.h
#include "string"
#include "fstream"
using namespace std;

struct stackNode {
	stackNode* next = nullptr;
	liveCity newData;
	//string nameofCity;
	//string topAllergy;
};

class liveCity {
private:
	stackNode* top = nullptr;
	string nameOfCity;
	string topAllergy;
public:
	ifstream fileIn;
	ofstream fileOut;

	void push(liveCity);
	double peek();
	void pop();
	void printStack();
	void fileInput();
	void setNameOfCity(string cityName) { nameOfCity = cityName; }
	void setTopAllergy(string allergyInfo) { topAllergy = allergyInfo; }
	string getNameOfCity() { return nameOfCity; }
	string getTopAllergy() { return topAllergy; }



	liveCity() {
		fileInput();
	}
};
#endif