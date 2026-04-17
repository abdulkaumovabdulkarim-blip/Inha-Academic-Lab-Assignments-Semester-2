// Abdulqayumiv Abdukarim. ID: U2510080.
// Source.cpp
#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	bool exit = true;
	int choice;

	// Loop 
	while (exit == true) {

		// Take user choice
		choice = main_menu();

		switch (choice) {
			// Write studnets in file students.txt
			case 1: {
				writeStudents();
				break;
			}
			case 2: {
				// Get studnets dat from students.txt
				getStudents();
				break;
			}
			case 3: {
				// Write studnets data in binary file students.dat
				b_writeStudents();
				break;
			}
			case 4: {
				// Get studnets dat from binary file students.dat
				b_getStudents();
				break;
			}
			case 0:
				// Exit the loop
				exit = false;
				break;
			default:
				cout << "Please enter only one number between (0-4)! Try again." << endl;
				break;
			}
	}
	cout << "Thank you! Program ended." << endl;


	return 0;
}