#include "HashTable.h"

//Default constructor that sets all values to null
//and calls fileInput()
hashTable::hashTable(){

	names = new Hash* [size]; //Initalizes the size for an array of pointers to size
	dummyNode = new Hash* [size]; 
	for (int i = 0; i < size; i++) {
		names[i] = NULL;
		dummyNode[i] = NULL;
	}
	fileInput();
}

//Function turns key into hashKey then finds the key and places it
//in the correct position. If spot is taken, will move down one
//position until next available one is found
void hashTable::insert(string key, string value){

	int hashKey = keyCode(key);
	
	while (names[hashKey] != NULL && names[hashKey]->getKey() != key) {
		hashKey = (hashKey + 1) % size;
	}
	if (names[hashKey] == NULL  /*&& names[hashKey]->getKey() == key*/) {
		names[hashKey] = new Hash(key, value);
	}
}

//Function iterates through string and converts
//each character into its ascii value. 
//when ascii value is found, will keep 
//track of total in count and return that number
int hashTable::convertToAscii(string key){

	int count = 0;
	for (int i = 0; i < key.length(); i++) {
		count = count + (int)key[i];
	}
	return count;
}

//Function converts string key to a hashKey of type int
int hashTable::keyCode(string key){

	int ascii = convertToAscii(key);

	int hashKey = ascii % size;
	return hashKey;
}

//Function will iterate through the hash table and look
//for the node to delete.
//If not found, will return a message
string hashTable::deleteHash(string key){

	int index = keyCode(key);

	while (names[index] != NULL) {
		if (names[index]->getKey() == key) {
			names[index] = dummyNode[index];
			size--;
			return "Value deleted\n";
		}
		index++;
		index = index % size;
	}
	return "Value not found\n";
}

//Function takes in a key and outputs the value associated with that key
//If not found, will return with a message
string hashTable::get(string key){

	int index = keyCode(key);
	int i = 0;

	while (names[index] != NULL) {
		if (names[index]->getKey() == key) {
			return names[index]->getValue();
		}
		if (i > size) {
			return "That does not exist\n";
		}
		i++;
		index++;
		index = index % size;
	}
}

void hashTable::fileOutput(){
	for (int i = 0; i < size; i++) {
		if (names[i] != NULL) {
			fileOut << names[i]->getKey() << "\t" << names[i]->getValue() << endl;
		}
	}
}

string hashTable::addComma(string number){
	int counter = number.length() - 3;

	for (int i = 0; counter > 0; counter -= 3) {
		number.insert(counter, ",");
	}
	return number;
}

void hashTable::viewCountry(){
	for (int i = 0; i < size; i++) {
		if (names[i] != NULL) {
			cout << names[i]->getKey() << endl;
		}
	}
}

//This function opens the file and reads the key and the data
//that goes with that key
void hashTable::fileInput(){

	string allergyKey = "";
	string allergyValue = "";

	fileIn.open("countryAllergy.txt");

	for (int i = 0; i < size; i++) {
		fileIn >> allergyKey >> allergyValue;
		insert(allergyKey, allergyValue);
	}

	fileIn.close();
}


