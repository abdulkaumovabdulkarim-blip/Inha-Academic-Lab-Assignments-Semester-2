// Abdulqayumiv Abdukarim. ID: U2510080. Date: 2026.02.13. 

#include "Header.h"
int main() {
    // 1 student
	StudentAccount studentacc1;
	studentacc1.setaccountNumebr("123456");
	studentacc1.setStudentName("Abdukarim");
	studentacc1.setUniversityID("U2510080");
	studentacc1.set_Balance(3500);
	studentacc1.setWithdraw(100);
	
	cout << "1 Student account data: " << endl;
	cout << "\nAccount Number 1 student: " << studentacc1.getAccountNumber() << endl;
	cout << "Student name 1 student: " << studentacc1.getStudentName() << endl;
	cout << "University ID 1 student: " << studentacc1.getUniversityID() << endl;
	cout << "Balance 1 student: " << studentacc1.getBalance() << endl;
	cout << "Withdraw 1 student: " << studentacc1.getWithdraw() << endl;
	// 2 student
	StudentAccount studentacc2;
	studentacc2.setaccountNumebr("11223344");
	studentacc2.setStudentName("Ali");
	studentacc2.setUniversityID("U2510090");
	studentacc2.set_Balance(2500);
	studentacc2.setWithdraw(80);
	cout << "\n2 Student account data: " << endl;
	cout << "\nAccount Number 2 student: " << studentacc2.getAccountNumber() << endl;
	cout << "Student name 2 student: " << studentacc2.getStudentName() << endl;
	cout << "University ID 2 student: " << studentacc2.getUniversityID() << endl;
	cout << "Balance 2 student: " << studentacc2.getBalance() << endl;
	cout << "Withdraw 2 student: " << studentacc2.getWithdraw() << endl;
	cout << "\nThank you! Program ended!";
	return 0;
}