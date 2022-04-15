
// This functions holds the file open and menu functions

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "CountryManip.h"
#include "SeasonalAllergy.h"
#include <windows.h>
#include "CityManip.h"

using namespace std;

void addAllergyData(Country&);

//*********************************************************
//	Menu function, displays various options for the user to
//	view different data pertaining to food allergies.
//
//*********************************************************
void menuCountry()
{
	char exit = 'Y';
	int enter;
	Country newCountry;
	Country delCountry;
	CountryArray allergyData;
	string countryName;
	string eraseCountry;
	int choice;
	int before = 0;
	int after = 0;
	cout << "This program allows for the user to store and access various allergy data for ";
	cout << "various countries. \n \n";

	do
	{
		cout << "Press 1 to add country" << endl;
		cout << "Press 2 to remove country" << endl;
		cout << "Press 3 to view data" << endl;
		cout << "Press 4 to sort data" << endl;
		cout << "Press 0 to exit" << endl;
		cin >> enter;
	
			switch (enter)
			{
			case 1:
				cout << "What is the name of the country you would like to add?: ";
				cin >> countryName;
				cout << endl;
				addAllergyData(newCountry);
				newCountry.setName(countryName);
				allergyData.addCountry(newCountry);
				allergyData.fileOutput();
				break;
			case 2:

				int check;
				do {
					cout << "Would you like to continue deleting a country? Press 0 to exit or 1 to continue: ";
					cin >> check;

					if (check == 0) {
						cout << "Delete function will now be exited. Please restart program. \n";
						return;
					}

					else if (check == 1) {
						cout << "You can now proceed to deleting a country. \n";
					}
					cin.ignore();
				} while (check != 0 && check != 1);


				cout << "What is the name of the country you want to remove?: ";
				getline(cin, eraseCountry);

				allergyData.deleteCountry(eraseCountry);
				allergyData.fileOutput();
				break;
			case 3:
				allergyData.Print();
				allergyData.fileOutput();
				break;
			case 4:
				cout << "Would you like the list to be sorted in ascending or"
					<< " desending order" << endl;
				cout << "Press 1 for ascending order" << endl;
				cout << "Press 2 for desending order" << endl;
				cin >> choice;

				if (choice == 1) {
					allergyData.mergeSortAscending(0, allergyData.sizeOfCountry() - 1);
					allergyData.printCountryNames();
					allergyData.fileOutput();
				}
				else if (choice == 2) {
					allergyData.mergeSortDescending(0, allergyData.sizeOfCountry() - 1);
					allergyData.printCountryNames();
					allergyData.fileOutput();
				}
			
			
			case 0:
				return;
			default:
				cout << "Please only enter 1, 2, 3, or 4: ";
				cin >> enter;
				break;
			}
			//cout << "Would you like to continue? Press Y for yes or N for no: " << endl;
			//cin >> exit;
		
	} while (enter != 0);
}

//******************************************************************
// addAllergyData function takes in allergy data input from the user
// and sets it with the Country set functions.
//******************************************************************

void addAllergyData(Country& newData) {
	int popData, milkData, peanutData, treeNutData, fishData,
		eggData, wheatData, soyData, seasameData, shellfishData;

	cout << "Please enter data for population: ";
	cin >> popData;
	newData.setPop(popData);
	cout << "Please enter data for milk allergies: ";
	cin >> milkData;
	newData.setMilk(milkData);
	cout << "Please enter data for peanut allergies: ";
	cin >> peanutData;
	newData.setPeanut(peanutData);
	cout << "Please enter data for tree nut allergies: ";
	cin >> treeNutData;
	newData.setTreeNut(treeNutData);
	cout << "Please enter data for fish allergies: ";
	cin >> fishData;
	newData.setFish(fishData);
	cout << "Please enter data for egg allergies: ";
	cin >> eggData;
	newData.setEgg(eggData);
	cout << "Please enter data for wheat allergies: ";
	cin >> wheatData;
	newData.setWheat(wheatData);
	cout << "Please enter data for soy allergies: ";
	cin >> soyData;
	newData.setSoy(soyData);
	cout << "Please enter data for sesame allergies: ";
	cin >> seasameData;
	newData.setSeasame(seasameData);
	cout << "Please enter data for shellfish allergies: ";
	cin >> shellfishData;
	newData.setShellfish(shellfishData);
}

void pollenMenu()
{
	Pollen pol;
	string erasePollen;
	int enter;
	PollenArray pollen;
	int orderChoice;
	string searchPollen;


	do
	{
		cout << "Press 1 to add pollen type" << endl;
		cout << "Press 2 to remove pollen type" << endl;
		cout << "Press 3 to view pollen" << endl;
		cout << "Press 4 to sort allergy data" << endl;
		cout << "Press 0 to exit" << endl;
		cin >> enter;

		switch (enter)
		{
		case 1:
			cout << "What is the name of the pollen type you would like to add?: ";
			cin >> pol.pollenName;
			cout << endl;
			cout << "What type of geogrphy is this type of pollen most common?: ";
			cin >> pol.typeOfGeography;
			cout << endl;
			cout << "What is the number of people that are allergic to this pollen type?: ";
			cin >> pol.numOfCases;

			break;
		case 2:

			int check;
			do {
				cout << "Would you like to continue deleting a pollen type? Press 0 to exit or 1 to continue: ";
				cin >> check;

				if (check == 0) {
					cout << "Delete function will now be exited. Please restart program. \n";
					return;
				}

				else if (check == 1) {
					cout << "You can now proceed to deleting a pollen type. \n";
				}
				cin.ignore();
			} while (check != 0 && check != 1);


			cout << "What is the name of the pollen type you want to remove?: ";
			getline(cin, erasePollen);

			pollen.deletePollen(erasePollen);
			pollen.fileOutput();
			break;
		case 3:
			pollen.printPollen();
			break;
		case 4:
			cout << "Would you like the list to be sorted in ascending or"
				<< " desending order" << endl;
			cout << "Press 1 for ascending order" << endl;
			cout << "Press 2 for desending order" << endl;
			cin >> orderChoice;

			if (orderChoice == 1) {
				pollen.mergeSortAscending(0, pollen.getPollenSize() - 1);
				pollen.printPollen();
				pollen.fileOutput();
			}
			else if (orderChoice == 2) {
				pollen.mergeSortDescending(0, pollen.getPollenSize() - 1);
				pollen.printPollen();
				pollen.fileOutput();
			}

			break;
		case 0:
			
			return;
		default:
			cout << "Please only enter 1, 2, 3, or 4: ";
			
			break;
		}

	} while (enter != 0);
}

void cityMenu() {
	int enter = 0;
	string cityAdd = "";
	CityManip city;
	int deleteChoice;
	string cityDelete = "";
	string citySearch = "";
	City add;
	int cityReactions;
	int cityHospitalizations;

	do {
		cout << "Press 1 to add a city" << endl;
		cout << "Press 2 to remove a city" << endl;
		cout << "Press 3 to view city data" << endl;
		cout << "Press 4 to search for certain city data" << endl;
		cout << "Press 0 to exit" << endl;
		cin >> enter;

		switch (enter) {
		case 1:
			cout << "Enter the name of the city you would like to add \n";
			cout << "Followed by the number of total allergic reactions in given city \n";
			cout << "And the total number of hospitalizations \n";
			cout << "Ex: (Reedley xxxxx xxxxx): \n";
			cin >> cityAdd;
			
			city.addCity(add);
			city.cityFilesOutput();
		case 2:
			cout << "Are you sure you would like to remove a city?" << endl;
			cout << "Enter 1 to proceed or 0 to exit: ";
			cin >> deleteChoice;

			if (deleteChoice == 1) {
				cout << "Enter the name of the city you would like to delete: ";
				cin >> cityDelete;
				city.removeCity(cityDelete);
				city.cityFilesOutput();
			}
			else if (deleteChoice == 0) {
				cout << "Delete function will now be executed. Please restart program." << endl;
				return;
			}
			break;
		case 3:
			//city.printCities();
			city.cityFilesOutput();
			break;
		case 4:
			cout << "Enter the name of the city you would like to search for: ";
			cin >> citySearch;
			city.searchCity(citySearch);
			break;
		case 0:
			return;
		default:
			cout << "Please enter only 1, 2, 3, or 4: ";
			break;
		}

	} while (enter != 0);
}

//add menu function for city class