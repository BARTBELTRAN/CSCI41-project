#include "Stack.h"
#include <iostream>
using namespace std;

void liveCity::push(liveCity info) {
	stackNode* temp = new stackNode();

	if (!temp) {
		cout << "Stack is full\n";
		return;
	}
	temp->newData = info;
	temp->next = top;
	top = temp;

}

double liveCity::peek() {
	if (top != nullptr) {
		return top->newData;
	}
	else {
		return;
	}
}

void liveCity::pop() {
	stackNode* temp;
	if (top == nullptr) {
		cout << "Stack is empty\n";
		return;
	}
	else {
		temp = top;
		top = top->newData;
		delete temp;
	}
}

void liveCity::printStack() {
	stackNode* temp;

	if (top == nullptr) {
		cout << "Stack is empty\n";
		return;
	}
	else {
		temp = top;

		while (temp != nullptr) {
			cout << temp->nameOfCity << endl; //Have 2 couts one or city name and allergy data
			temp = temp->next;
		}
	}
}

void liveCity::fileInput() {
	fileIn.open("cityAllergyData.txt");
	liveCity data;
	string cityName;
	string allergyInfo;

	while (fileIn >> cityName) {
		fileIn >> cityName;
		data.setNameOfCity(cityName);
		fileIn >> allergyInfo;
		data.setTopAllergy(allergyInfo);
		push(data);
	}
}
/*Potential Ideas for Stacks Project
Make a list of big cities and the most prevalent allergy in that country 
then ask user for their allergies then compare those all to the countries
then use the program to spit out the top countries that don't have that allergy
or less of that allergy. give the user an option to say if it was a good suggestion
if yes, end program, if no, output the next top city.
*/