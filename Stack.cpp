#include "Stack.h"
#include <iostream>
using namespace std;

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

void liveCity::push(liveCity& info) {
	cities = new liveCity[size++];
	cities[++top] = info;
}

liveCity liveCity::pop() {
	return cities[top--];
}

liveCity liveCity::peek() {
		return cities[top];
}

void liveCity::fileOutput() {
	liveCity temp;
	fileOut.open("cityAllergyData.txt");

	while (isEmpty() == false) {
		fileOut << temp.getNameOfCity() << "/t" << temp.getTopAllergy() << endl;
	}
	fileOut.close();
}

bool liveCity::isEmpty() {
	return top == -1;
}

liveCity::~liveCity(){
	delete[] cities;
}


liveCity::liveCity(const liveCity& temp){
	nameOfCity = temp.nameOfCity;
	topAllergy = temp.topAllergy;

}

liveCity liveCity::operator=(const liveCity&){
	return liveCity();
}

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

/*Potential Ideas for Stacks Project
Make a list of big cities and the most prevalent allergy in that country 
then ask user for their allergies then compare those all to the countries
then use the program to spit out the top countries that don't have that allergy
or less of that allergy. give the user an option to say if it was a good suggestion
if yes, end program, if no, output the next top city.
*/