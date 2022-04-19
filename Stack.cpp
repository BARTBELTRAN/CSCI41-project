#include "Stack.h"
#include <iostream>
using namespace std;

void Stack::push(double info) {
	node* temp = new node();

	if (!temp) {
		cout << "Stack is full\n";
		return;
	}
	temp->newData = info;
	temp->next = top;
	top = temp;

}

double Stack::peek() {
	if (top != nullptr) {
		return top->newData;
	}
	else {
		return;
	}
}

void Stack::pop() {
	node* temp;
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

void Stack::printStack() {
	node* temp;

	if (top == nullptr) {
		cout << "Stack is empty\n";
		return;
	}
	else {
		temp = top;

		while (temp != nullptr) {
			cout << temp->newData << endl;
			temp = temp->next;
		}
	}
}
/*Potential Ideas for Stacks Project
Taking in all allergy information worldwide, then comparing them against each other
in order to find the most prevalent allergy worldwide

Taking in all demographics regarding allergy affliction and then calculating what 
race/ethnicity is more sensitive to certain types of allergies due to genetic
predispositions. This list will constantly be updated because more and more 
people develop allergies everyday. Allergies can develop later on in life. This 
will also take into account age as well.

Adding data regarding certain hospitals and the availablity of certain allergy medications.
There will also be more data in regards to the development of cities and countries using
WW Rostow's Stages of Economic Growth "Stage 1 - 5". Using this, the program will
calculate the safest city/country to live in. This will keep changing based on 
any city or country data added later on during the duration of the program's 
life.
*/