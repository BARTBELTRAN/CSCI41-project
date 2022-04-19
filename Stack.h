#pragma once
using namespace std;

struct node {
	struct node* next = nullptr;
	Stack newData;
};

class Stack {
private:
	node* top;
public:
	void push(double);
	double peek();
	void pop();
	void printStack();

	Stack() {
		top = nullptr;
	}
};