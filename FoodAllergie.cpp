// This program displays the amount of people that are affected by different types of 
// food allergies from different counties around the world.

// Justin Soun, Bart Beltran

#include <iostream>
//#include "Country.h"
#include "Menu.h"
//#include "CountryManip.h"
//#include "SeasonalAllergy.h"
using namespace std;



int main()
{	
	int opMenu = 0;

	cout << "Enter 1 for the country menu" << endl <<
		"Enter 2 for the Pollen menu" << endl <<
		"Press 9 to exit" << endl;
	cin >> opMenu;

	while (opMenu != 9)
	{
		switch (opMenu)
		{
		case 1:
			menuCountry();				//Call to allergy menu function
			break;
		case 2:
			pollenMenu();				///Call to pollen menu funtion
		default:
			break;
		}
	}

	

	return 0;

}


