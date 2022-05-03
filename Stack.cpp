#include "Stack.h"
#include <iostream>
using namespace std;
//Reads in data from file
void liveCity::fileInput() {
	fileIn.open("cityAllergyData.txt");
	liveCity input;

	while (fileIn) {
		fileIn >> nameOfCity;
		input.setNameOfCity(nameOfCity);
		fileIn >> topAllergy;
		input.setNameOfCity(topAllergy);
		push(input);
		numOfCities++;
	}
	fileIn.close();
}
//Adds objects to stack
void liveCity::push(liveCity& info) {
	cities = new liveCity[size++];
	cities[++top] = info;
}
//Deletes top object and returns top object
liveCity liveCity::pop() {
	liveCity topOfStack = peek();
	cout << topOfStack.getNameOfCity();
	return cities[top--];
}
//This function looks at the top object in stack
liveCity liveCity::peek() {
		return cities[top];
}
//This program outputs data to the external file
void liveCity::fileOutput() {
	liveCity temp;
	fileOut.open("cityAllergyData.txt");

	while (isEmpty() == false) {
		fileOut << temp.getNameOfCity() << "/t" << temp.getTopAllergy() << endl;
	}
	fileOut.close();
}
//checks to see if top is equal to -1
//If it is, the isEmpty will return true
bool liveCity::isEmpty() {
	return top == -1;
}
//Destructor
liveCity::~liveCity(){
	delete[] cities;
}
//Copy Constructor
liveCity::liveCity(const liveCity& temp){
	nameOfCity = temp.nameOfCity;
	topAllergy = temp.topAllergy;

}
//Overloading the "=" operator
liveCity liveCity::operator=(const liveCity&){
	return liveCity();
}

//This function continuosly pops the stack and as long as 
//the allergy data for the objects in the stack do not match
//the user inputted allergy, it will reccomend the city to the user.
void liveCity::cityComparison(string allergyTop){
	liveCity data;
	int choice;
	do {
		data = pop();
		if (data.getTopAllergy() != allergyTop) {
			cout << "Would you like to live in " << data.getNameOfCity() <<
				" where the top allergy is " << data.getTopAllergy() << "?\n";
			cout << "Press 1 for yes or 2 for no: ";
			cin >> choice;
			if (choice == 1) {
				cout << "You have chosen " << data.getNameOfCity() <<
					" as a place to live.\n";
			}
			else if (choice == 2) {
				continue;
			}
		}
	} while (isEmpty() == false);
}

