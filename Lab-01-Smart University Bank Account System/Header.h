#include <iostream>
using namespace std;
class StudentAccount {
private:
	string accountNumber;
	string studentName;
	string universityID;
	double balance;
	double withdraw;
public:
	void setaccountNumebr(string number) {
		accountNumber = number;
	}
	void setStudentName(string name) {
		studentName = name;
	}
	void setUniversityID(string id) {
		universityID = id;
	}
	void set_Balance(double bal) {
		balance = bal;
	}
	void setWithdraw(double money) {
		withdraw = money;
	}
	string getAccountNumber() {
		return accountNumber;
	}
	string getStudentName() {
		return studentName;
	}
	string getUniversityID() {
		return universityID;
	}
	double getBalance() {
		return balance;
	}
	double getWithdraw() {
		return withdraw;
	}
};