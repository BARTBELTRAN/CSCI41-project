#include "HashTable.h"

hashTable::hashTable(){
	names = new Hash* [SIZE];
	for (int i = 0; i < SIZE; i++) {
		names[i] = NULL;
	}
}

void hashTable::put(string key, string value)
{
	int hash = keyCode(key);
	while (names[hash] != NULL && names[hash]->getKey() != key) {
		hash = (hash + 1) % SIZE;
	}
	if (names[hash] != NULL) {
		delete names[hash];
	}
	names[hash] = new Hash(key, value);
	
}

int hashTable::convertToAscii(string key)
{
	int count = 0;
	for (int i = 0; i < key.length(); i++) {
		count = count + (int)key[i];
	}
	return count;
}

int hashTable::keyCode(string key)
{
	int ascii = convertToAscii(key);

	int hashKey = ascii % SIZE;
	return hashKey;
}


