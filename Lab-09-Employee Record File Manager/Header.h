// Header.h
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Employee {
	// variables
private:
	int ID;
	char Name[20];
	double Salary;
public:
	// Default constructor
	Employee(int = 0, string = "", double = 0.0);
	// seters
	void setID(int id);
	void setName(string name);
	void setSalary(double salary);
	// geters
	int getID();
	string getName();
	double getSalary();
};
// Default constructor
Employee::Employee(int a, string b, double c) {
	setID(a);
	setName(b);
	setSalary(c);
}
// Set Id
void Employee::setID(int id) {
	ID = id;
}
// Set Name
void Employee::setName(string name) {

	int length = (name.size() < 20) ? name.size() : 19; // length
	for (int i = 0; i < length; ++i)
		Name[i] = name[i];
	Name[length] = '\0';
}
// Set Salary
void Employee::setSalary(double salary) {
	Salary = salary;
}
// Get Id
int Employee::getID() {
	return ID;
}
// Get Name
string Employee::getName() {
	return Name;
}
// Get Salary
double Employee::getSalary() {
	return Salary;
}