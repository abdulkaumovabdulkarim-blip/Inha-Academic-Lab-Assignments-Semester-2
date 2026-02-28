// Header.h

#include <iostream>
#include <string>
using namespace std;

// Class Account
class Account{
// Private members
private:
	int bankCard;
	string accountName;
	int pinNumber;
	static int accountCount;
	// Public members
public:
	// Constructors
	Account() : bankCard(0), accountName(""), pinNumber(0) {
		accountCount++;
	}
	Account(int a, string b, int c) : bankCard(a), accountName(b), pinNumber(c) {
	}
	// member functions
	void display() const {
		cout << "Account Details: " << endl;
		cout << "  Card Number\t: " << bankCard << endl;
		cout << "  Name\t\t: " << accountName << endl;
		cout << "  PIN\t\t: " << pinNumber << endl;
	}
	static int getAccountlCount() {
		return accountCount;
	}
};
int Account::accountCount = 0;
// Class Balance
class Balance { // CHECK !!!
// Private members
private:
	double balance;
	static int balanceObjects;
	// Public members
public:
	// Constructors
	Balance() : balance(0.0) {
		balanceObjects++;
	}
	Balance(double a) : balance(a) {
		if (a < 0)
			balance = 0;
	}
	// member functions
	void deposit(double amount) {
		while (amount < 0) {
			cout << "Invalid number! Deposit can not be less than 0. Please try again: ";
			cin >> amount;
		}
		balance += amount;
	}
	bool withdraw (double amount) {
		while (amount < 0) {
			cout << "Invalid number! Withdraw can not be less than 0. Please try again: ";
			cin >> amount;
		}
		if (balance >= amount) {
			balance -= amount;
			return true;
		}
		else {
			cout << "Insufficient balance!" << endl;
			return false;
		}
	}
	void showBalance() const {
		cout << "Balance: " << endl;
		cout << "  Current Balance: " << balance << endl;
	}
	static int getBalanceObjectCount() {
		return balanceObjects;
	}
};
int Balance::balanceObjects = 0;
// Class ATM
class ATM { // CHECK !!!
// Private mebers
private:
	Account account;
	Balance balance;
	static int atmCount;
	// Public members
public:
	// Constructor
	ATM() : account(), balance() {
		atmCount++;
	}
	ATM(int a, string b, int c, double d) : account(a, b, c), balance(d) {}
	void print() const {
		account.display();
		balance.showBalance();
	}
	void deposit(double amount) {
		balance.deposit(amount);
	}
	void withdraw(double amount) {
		balance.withdraw(amount);
	}
	static int getATMCount() {
		return atmCount;
	}
	static int getAccountCount() {
		return Account::getAccountlCount();
	}
	static int getBalanceCount() {
		return Balance::getBalanceObjectCount();
	}
};

int ATM::atmCount = 0;
