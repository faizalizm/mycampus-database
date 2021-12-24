#include <iostream>
#include <list>
#include <string>
#include <iomanip>
using namespace std;

struct Staff {
		int ID;
		string Name;
		string Position;
		float Salary;
};

const int tableSize = 100;
list<Staff> *table;

class MyCampus {
	public :
	MyCampus() {
		// create an array of list with size 100 that will hold Staff structs
		table = new list<Staff>[tableSize];
	}

	int menu() {
		int choice;
		cout << "\n\n\tMain Menu :-"
			<< "\n\t[1] Add Staff"
			<< "\n\t[2] Find Staff Data Location"
			<< "\n\t[3] Display All Staff Nodes"
			<< "\n\t[4] Exit Program"
			<< "\n->\tEnter Choice : ";
		cin >> choice;
		
		// error checking for if a user entered string instead of int
		while (cin.fail()) {
			cin.clear(); // clear the error flag on cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore characters in input buffer until \n is found
			cout << "\n\t-= !! Error : Entered String Value !! =-\n"
				<< "\n->\tRe-Enter Choice : ";
			cin >> choice;
		}

		return choice;
	}

	int hashFunction(int key) {
		// this will calculate the index to place/find each staff node
		int index = key % 9002000 % tableSize;
		return index;
	}

	void newStaff(int &staffCount) {
		Staff* aRec = new Staff();
		cout << "\n\t-= !! Adding Staff !! =-\n";
		cout << "\n->\tStaff ID No : ";
		cin >> aRec->ID;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n\t-= !! Error : Entered String Value !! =-\n"
				<< "\n->\tRe-Enter Staff ID No : ";
			cin >> aRec->ID;
		}

		while (aRec->ID < 90020000 || aRec->ID > 90020999) {
			cout << "\n\t-= !! Staff ID starts from 90020000 to 90020999 !! =-\n"
				<< "\n->\tRe-Enter Staff ID No : ";
			cin >> aRec->ID;
		}

		cout << "->\tStaff Name : ";
		cin >> ws;
		getline(cin, aRec->Name);
		cout << "->\tStaff Position : ";
		cin >> ws;
		getline(cin, aRec->Position);
		cout << "->\tStaff Salary : RM ";
		cin >> aRec->Salary;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n\t-= !! Error : Entered String Value !! =-\n"
				<< "\n->\tRe-Enter Staff Salary : ";
			cin >> aRec->Salary;
		}

		// push the structure pointer in regard with its index location
		int index = hashFunction(aRec->ID);
		table[index].push_back(*aRec);
		staffCount++;

		cout << "\n\t-= !! Staff Sucessfully Added !! =-\n";
		cout << "\n====================================================  ❤";
	}

	void findStaff(int staffCount) {
		int findID, count = 1;
		bool flag;
		if (staffCount != 0) {
			cout << "\n\t-= !! Staff Searching !! =-\n";
			cout << "\n====================================================  ❤\n";

			while (true) {
				cout << "\n\t[0] Enter 0 to Quit Searching";
				cout << "\n->\tEnter Staff ID : ";
				cin >> findID;
				
				while (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n\t-= !! Error : Entered String Value !! =-\n"
						<< "\n->\tRe-Enter Staff ID No : ";
					cin >> findID;
				}

				if (findID == 0) {
					cout << "\n\t-= !! Exiting Search Menu !! =-\n";
					break;
				}

				while (findID != 0 && (findID < 90020000 || findID > 90020999)) {
					cout << "\n\t-= !! Staff ID starts from 90020000 to 90020999 !! =-\n"
						<< "\n->\tRe-Enter Staff ID No : ";
					cin >> findID;
				}

				int index = hashFunction(findID);
				// reinitialize variables after each search
				flag = 0;
				count = 1;

				// iterator that visits every node of an index
				for (auto find = table[index].begin(); find != table[index].end(); find++) {
					if (find->ID == findID) {
						cout << "\n\tResult : \n\tData Location : Index " << index << " (Node : " << count << ")"
							<< "\n\tStaff Name : " << find->Name
							<< "\n\tStaff Position : " << find->Position
							<< "\n\tStaff Salary : RM " << find->Salary << endl;
						flag = 1;
						cout << "\n====================================================  ❤\n";
						break; // break out of for loop if staff is found
					}
					count++;
				}

				if (!flag)
					cout << "\n\t-= !! Error 404 : Staff Doesn't Exist !! =-\n";
			}
		}
		else
				cout << "\n\t-= !! No Staff Added Yet !! =-\n";

		cout << "\n====================================================  ❤";
	}

	void displayStaff(int staffCount) {
		if (staffCount != 0) {
			cout << "\n\t-= !! Showing All Staff Record !! =-\n"
				<< "\n\tIndex : --> Node 1 --> Node 2 --> Node 3 ..."
				<< "\n  -----------------------------------------------\n";

			for (int index = 0; index < tableSize; index++) {
				if (!table[index].empty()) {
					cout << "\t" << index << " : ";
					for (auto node : table[index]) // foreach statement to iterate through nodes of an index 
						cout << " --> " << node.ID;
					cout << endl;
				}
			}

			cout << "  -----------------------------------------------"
				<< "\n\tTotal Staff in MyCampus Database : " << staffCount << " staff(s)\n";
		}
		else
				cout << "\n\t-= !! No Staff Added Yet !! =-\n";

		cout << "\n====================================================  ❤";
	}
};
