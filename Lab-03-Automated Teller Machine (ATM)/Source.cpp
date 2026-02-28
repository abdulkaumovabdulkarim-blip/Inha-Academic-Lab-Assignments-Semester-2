// Abdulqayumiv Abdukarim. ID: U2510080. Date: 2026.02.26. 

#include "Header.h"
int main() {
	int ATMusers, cardNumber, PIN, index, deposit;
	string accountName;
	double balance;
	bool indexbool;
	cout << "Enter number of ATM users: ";
	cin >> ATMusers;
	ATM* atm = new ATM[ATMusers];
	for (int i = 0; i < ATMusers; i++) {
		cout << "\nEnter info for user " << i+1 << endl;//Help
		cout << "Card number: ";
		cin >> cardNumber;
		while (cardNumber < 0) {
			cout << "Invalid number! Bank Card has to be more than 0. Try again:";
			cin >> cardNumber;
		}
		cout << "Account name: ";
		cin >> accountName;
		cout << "PIN (4 didgits): ";
		cin >> PIN;
		while (PIN < 1000 || PIN > 9999) {
			cout << "Invalid number! PIN number has to contain 4 digits (1000-9999). Try again:";
			cin >> PIN;
		}
		cout << "Initial balance: ";
		cin >> balance;
		atm[i] = ATM(cardNumber, accountName, PIN, balance);
	}
	// Before transactions
	cout << "\n\nBEFORE TRANSACTIONS" << endl;
	for (int i = 0; i < ATMusers; i++) {
		cout << "User " << i+1 << ": " << endl;
		atm[i].print();
	}
	// Deposit process
	do{
	cout << "\nEnter user index for deposit (1.." << ATMusers << "): ";
	cin >> index;
	indexbool = 1;
	if (index < 0 || index > ATMusers) {
		cout << "Invalid number! Try again ->" << endl;
		indexbool = 0;
	}
	}while (indexbool == 0);
	for (int i = 0; i < ATMusers; i++) {
		if (i == index - 1) {
			cout << "Enter deposit amount: ";
			cin >> deposit;
			atm[i].deposit(deposit);
		}
	}
	// Withdraw process
	do {
		cout << "\nEnter user index for withdrawal (1.." << ATMusers << "): ";
		cin >> index;
		indexbool = 1;
		if (index < 0 || index > ATMusers) {
			cout << "Invalid number! Try again ->" << endl;
			indexbool = 0;
		}
	} while (indexbool == 0);
	for (int i = 0; i < ATMusers; i++) {
		if (i == index - 1) {
			cout << "Enter withdraw amount: ";
			cin >> deposit;
			atm[i].withdraw(deposit);
		}
	}
	// After transactions
	cout << "\n\nAFTER TRANSACTIONS" << endl;
	for (int i = 0; i < ATMusers; i++) {
		cout << "User " << i + 1 << ": " << endl;
		atm[i].print();
	}
	// Static counters
	cout << "\n\n STATIC COUNTERS" << endl;
	cout << "Total Account objects\t: " << ATM::getAccountCount() << endl;
	cout << "Total Balance objects\t: " << ATM::getBalanceCount() << endl;
	cout << "Total ATM objects\t: " << ATM::getATMCount() << endl;
	return 0;
}