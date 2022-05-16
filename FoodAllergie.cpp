// Driver 
// This program displays the amount of people that are affected by different types of 
// food allergies from different counties around the world.

//	Project 5 Bart Beltran. Added TrialApplicants.cpp and .h. Also added to Menu.h
//	list of applicants are enqueued to list and updated to external file. 
//	list of applicants are then dequeued and determined to kept or erased.

//	Project 6 Bart Beltran. Added applicantStatisticsList.cpp . h. Also added applicantStatistics.cpp
//  and .h which hash the values of allery and age from trial applicants 

// Justin Soun, Bart Beltran

#include <iostream>
#include "Menu.h"
#include <iomanip>
using namespace std;



int main()
{	
	int opMenu = 0;
	
	int after = 0;
	while (opMenu != 9)
	{
		cout << setfill('*') << setw(55) << "*\n";
		cout << "Enter 1 for the country menu" << endl <<
			"Enter 2 for the Pollen menu" << endl <<
			"Enter 3 for the City menu" << endl <<
			"Enter 4 for the clinical trial application\n" <<
			"Enter 5 for the clinical trial applicant statistics list\n" <<
			"Press 9 to exit" << endl << endl;
		cout << setfill('*') << setw(55) << "*\n";
		cin >> opMenu;
		inputCheck(opMenu);
		cout << "\n";
		cout << "Number entered : " << opMenu << endl << endl;
		
		switch (opMenu)
		{
		case 1:
			menuCountry();				//Call to allergy menu function
			break;
		case 2:
			pollenMenu();				//Call to pollen menu funtion
			break;
		case 3: 
			cityMenu();					//Call to city menu function
			break;
		case 4:							//Call to clinical trial application function
			trialApplicationMenu();
			break;
		case 5:
			acceptedApplicantStatistics();	//call to manipulate applicant list
		default:
			break;
		}

	}
	return 0;

}