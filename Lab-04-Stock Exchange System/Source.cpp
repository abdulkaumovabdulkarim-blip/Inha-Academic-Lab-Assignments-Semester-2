// Abdulqayumiv Abdukarim. ID: U2510080.
// Source.cpp
#include "Header.h"
int main() {
	StockEx M1, M2;
	cout << "Enter details for first market: " << endl;
	cin >> M1;
	cout << "\nEnter details for second market: " << endl;
	cin >> M2;

	cout << "\nFirst Market: " << endl;
	cout << M1;
	cout << "\nSecond Market: " << endl;
	cout << M2;

	int choice;
	double amount;
	cout << "\nChoose market for currency exchange: " << endl;
	cout << "1. First Market" << endl;
	cout << "2. Second Market" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	cout << "Enter amount to exchange: ";
	cin >> amount;
	if (choice == 1)
		cout << "Converted amount: " << M1 * amount << endl;
	else if (choice == 2)
		cout << "Converted amount: " << M2 * amount << endl;

	cout << "\nDifference between market rates: " << M1 - M2 << endl;
	if (M1 > M2) {
		cout << "First market rate is higher ." << endl;
	}
	else {
		cout << "Second market rate is higher ." << endl;
	}
	return 0;
}
