// Header.h

#include <iostream>
#include <string>
using namespace std;
// Class
// Class Person
class Person{
	// Protected members
protected:
	string Name;
	int age;
	int id;
public:
	// Constructor
	Person(string a, int b, int c) : Name(a), age(b), id(c) {
		while (age < 0) {
			cout << "Invalid Age! Enter only positive number\nPlease try again" << endl;
			cout << "Age: ";
			cin >> age;
		}
		while (id < 0) {
			cout << "Invalid Id! Enter only positive number\nPlease try again" << endl;
			cout << "Id: ";
			cin >> id;
		}
	}
	void displayPerson() const {
		cout << "Name: " << Name << endl;
		cout << "Age: " << age << endl;
		cout << "Id: " << id << endl;
	}
	void setPerson() {
		cout << "Name: ";
		getline(cin, Name);
		while (true) {
			cout << "Age: ";
			cin >> age;
			if (age < 0) cout << "Invalid Age! Enter only positive number\nPlease try again" << endl;
			else break;
		}
		while (true) {
			cout << "Id: ";
			cin >> id;
			if (id < 0) cout << "Invalid Id! Enter only positive number\nPlease try again" << endl;
			else break;
		}
		cin.ignore();
	}
};
// Class Student
class Student : public Person {
	// Private members
	string major;
	double gpa;
	int semester;
public:
	// Constructor
	Student(string d, int e, int f, string a, double b, int c) : Person(d, e, f), major(a), gpa(b), semester(c){
		while (gpa < 0 or gpa > 4) {
			cout << "Invalid Gpa! Enter only positive number and between 0-4\nPlease try again" << endl;
			cout << "Gpa: ";
			cin >> gpa;
		}
		while (semester < 0) {
			cout << "Invalid Semester! Enter only positive number\nPlease try again" << endl;
			cout << "Semester: ";
			cin >> semester;
		}
	}
	void displayStudent() const {
		cout << "\n--- Student Details ---" << endl;
		displayPerson();
		cout << "Major: " << major << endl;
		cout << "Gpa: " << gpa << endl;
		cout << "Semester: " << semester << endl;
	}
	void setStudent() {
		cout << "\n--- Set Student ---" << endl;
		setPerson();

		cout << "Major: ";
		getline(cin, major);
		while (true){
			cout << "Gpa: ";
			cin >> gpa;
			if (gpa < 0 || gpa > 4) cout << "Invalid Gpa! Enter only positive number and between 0-4\nPlease try again" << endl;
			else break;
		}
		while (true) {
			cout << "Semester: ";
			cin >> semester;
			if (semester < 0) cout << "Invalid Semester! Enter only positive number\nPlease try again" << endl;
			else break;
		}
		cin.ignore();
	}
};
// Class Teacher
class Teacher : public Person {
	// Private members
	string department;
	double salary;
	string subject;
public:
	// Constructor
	Teacher(string d, int e, int f, string a, double b, string c) : Person(d, e, f) , department(a), salary(b), subject(c){
		while (salary < 0) {
			cout << "Invalid Salary! Enter only positive number\nPlease try again" << endl;
			cout << "Salary: ";
			cin >> salary;
		}
	}
	void displayTeacher() const {
		cout << "\n--- Teacher Details ---" << endl;
		displayPerson();
		cout << "Department: " << department << endl;
		cout << "Salary: " << salary << endl;
		cout << "Subject: " << subject << endl;
	}
	void setTeacher() {
		cout << "\n--- Set Teacher ---" << endl;
		setPerson();

		cout << "Department: ";
		getline(cin, department);
		while (true) {
			cout << "Salary: ";
			cin >> salary;
			if (salary < 0) cout << "Invalid Salary! Enter only positive number\nPlease try again" << endl;
			else break;
		}
		cin.ignore();
		cout << "Subject: ";
		getline(cin, subject);
	}
};
// Class Staff
class Staff : public Person {
	// Private members
	string position;
	double monthlySalary;
	int workingHours;
public:
	// Constructor
	Staff(string d, int e, int f, string a, double b, int c) : Person(d, e, f), position(a), monthlySalary(b), workingHours(c){
		while (monthlySalary < 0) {
			cout << "Invalid Monthly Salary! Enter only positive number\nPlease try again" << endl;
			cout << "Monthly Salary: ";
			cin >> monthlySalary;
		}
		while (workingHours < 0) {
			cout << "Invalid Working Hours! Enter only positive number\nPlease try again" << endl;
			cout << "Working Hours: ";
			cin >> workingHours;
		}
	}
	void displayStaff() const {
		cout << "\n--- Staff Details ---" << endl;
		displayPerson();
		cout << "Position: " << position << endl;
		cout << "Monthly Salary: " << monthlySalary << endl;
		cout << "Working Hours: " << workingHours << endl;
	}
	void setStaff() {
		cout << "\n--- Set Staff ---" << endl;
		setPerson();

		cout << "Position: ";
		getline(cin, position);
		while (true) {
			cout << "Monthly Salary: ";
			cin >> monthlySalary;
			if (monthlySalary < 0) cout << "Invalid Monthly Salary! Enter only positive number\nPlease try again" << endl;
			else break;
		}
		while (true) {
			cout << "Working Hours: ";
			cin >> workingHours;
			if (workingHours < 0) cout << "Invalid Working Hours! Enter only positive number\nPlease try again" << endl;
			else break;
		}
		cin.ignore();
	}
};