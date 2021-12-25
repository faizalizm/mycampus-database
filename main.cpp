/*	
		|------------------------------------------------------------------
		|	Program Developed and Maintained w/ ❤  :-
		|	DeadLine Chasers | DLC
		|------------------------------------------------------------------
		|	Works Best on the IDE :-
		|	Replit.com
		|------------------------------------------------------------------
*/	

#include "myCampus.h"

int main() {
	MyCampus mcp;
	int choice, staffCount = 0;

	// header
	cout << "\n====================================================  ❤\n"
		<< "\n\t\t-= Welcome to MyCampus's Database =-\n"
		<< "\n====================================================  ❤";

	// body
	do {
		choice = mcp.menu();
		cout << fixed << setprecision(2);

		switch (choice) {
		  case 1 :
				mcp.newStaff(staffCount);
				break;
    	case 2 :
				mcp.findStaff(staffCount);
				break;
			case 3 :
				mcp.displayStaff(staffCount);
				break;
			case 4 :
				cout << "\n\t-= !! Exiting : Have A Nice Day Ahead !! =-\n";
				break;
		}
		
		if (choice > 4 || choice < 1)
			cout << "\n\t-= !! Error : Value Out of Bound !! =-";
			
	} while (choice != 4);

	// footer
	cout << "\n====================================================  ❤\n"
		<< "\n    © 2021 MyCampus Database All Rights Reserved           "
		<< "\n      -----------------------------------------           "
		<< "\n      Program Developed and Maintained w/ ❤  :-          "
		<< "\n      DeadLine Chasers | DLC \n                           "
		<< "\n====================================================  ❤\n";

	return 0;
} 
