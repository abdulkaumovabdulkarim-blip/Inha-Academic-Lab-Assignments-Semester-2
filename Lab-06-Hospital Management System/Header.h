// Header.h

#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Class

// Abstract Class
class Hospital {
	// Protected members
protected:
	string Name;
	int Age;
	int ID;
public:
	Hospital(string a, int b, int c) : Name(a), Age(b), ID(c){}
	virtual void display() = 0;
	virtual double calculateSalary() = 0;
	virtual ~Hospital() = 0;
};
Hospital::~Hospital(){}
// Derive class Doctor from Hospital
class Doctor : public Hospital {
private:
	string specialization;
	double monthlySalary;
	vector<string> patiants;
public:
	Doctor(string a, int b, int c, string d, double e) : Hospital(a,b,c), specialization(d), monthlySalary(e){
		while (e < 0) {
			cout << "Invalid Salary! Salary has to be positive. Please try again: ";
			cin >> e;
			monthlySalary = e;
		}
	}
	void display() override {
		cout << "Name: " << Hospital::Name << endl;
		cout << "Age: " << Hospital::Age << endl;
		cout << "ID: " << Hospital::ID << endl;
		cout << "Specialization: " << specialization << endl;
		cout << "Monthly Salary: " << monthlySalary << endl;
		cout << "Patinats: ";
		for (int i = 0; i < patiants.size(); i++) {
			cout << patiants[i] << ", ";
		}
		cout << endl;
	}
	double calculateSalary() override {
		return monthlySalary;
	}
	void addPatiants(string p) {
		patiants.push_back(p);
	}
 };
// Derive class Nurse from Hospital
class Nurse : public Hospital {
private:
	string ward;
	double monthlySalary;
	vector<string> duties;
public:
	Nurse(string a, int b, int c, string d, double e) : Hospital(a, b, c), ward(d), monthlySalary(e){
		while (e < 0) {
			cout << "Invalid Salary! Salary has to be positive. Please try again: ";
			cin >> e;
			monthlySalary = e;
		}
	}
	void display() override {
		cout << "Name: " << Hospital::Name << endl;
		cout << "Age: " << Hospital::Age << endl;
		cout << "ID: " << Hospital::ID << endl;
		cout << "Ward: " << ward << endl;
		cout << "Monthly Salary: " << monthlySalary << endl;
		cout << "Duties: ";
		for (int i = 0; i < duties.size(); i++) {
			cout << duties[i] << ", ";
		}
		cout << endl;
	}
	double calculateSalary() override {
		return monthlySalary;
	}
	void addDuties(string d) {
		duties.push_back(d);
	}
};
// Derive class Technician from Hospital
class Technician : public Hospital {
private:
	string labType;
	double hourlyRate;
	int workingHours;
	vector<string> machinesHandled;
public:
	Technician(string a, int b, int c, string d, double e, int f) : Hospital(a, b, c), labType(d), hourlyRate(e), workingHours(f){
		while (e < 0) {
			cout << "Invalid Hourly Rate! Hourly Rate has to be positive. Please try again: ";
			cin >> e;
			hourlyRate = e;
		}
		while (f < 0) {
			cout << "Invalid Working Hours! Working Hours has to be positive. Please try again: ";
			cin >> f;
			workingHours = f;
		}
	}
	void display() override {
		cout << "Name: " << Hospital::Name << endl;
		cout << "Age: " << Hospital::Age << endl;
		cout << "ID: " << Hospital::ID << endl;
		cout << "Lab Type: " << labType << endl;
		cout << "Hourly Rate: " << hourlyRate << endl;
		cout << "Working Hours: " << workingHours << endl;
		cout << "Machines: ";
		for (int i = 0; i < machinesHandled.size(); i++) {
			cout << machinesHandled[i] << ", ";
		}
		cout << endl;
		cout << "Salary: " << calculateSalary() << endl;
	}
	double calculateSalary() override {
		return hourlyRate * double(workingHours); // Salary based on Hourly Rate and Working Hours
	}
	void addMachines(string m) {
		machinesHandled.push_back(m);
	}
};

