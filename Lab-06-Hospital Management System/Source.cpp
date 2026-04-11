// Abdulqayumiv Abdukarim. ID: U2510080.
// Source.cpp
#include "Header.h"
int main() {
	Doctor doctor("Ali", 101, 45, "Cardiologist", 500);
	Nurse nurse("Malika", 201, 31, "Emergency", 2500);
	Technician tech("Bekzod", 301, 29, "Radiology", 15, 160);

	// Doctor Patiants add to vector
	doctor.addPatiants("Hasan");
	doctor.addPatiants("Salima");
	doctor.addPatiants("Kamola");

	// Nurse Duties add to vector
	nurse.addDuties("Check patiants");
	nurse.addDuties("Give medicine");
	nurse.addDuties("Assisit doctor");

	// Technician Handled add to vector
	tech.addMachines("X-Ray");
	tech.addMachines("MRI");

	// Doctor Info
	cout << "Doctor Information" << endl;
	doctor.display();
	cout << "Salary: " << doctor.calculateSalary() << endl;

	// Nurse Info
	cout << "-------------------------------------" << endl;
	cout << "Nurse Information" << endl;
	nurse.display();
	cout << "Salary: " << nurse.calculateSalary() << endl;
	cout << "-------------------------------------" << endl;

	// Technician Info
	cout << "Technician Information" << endl;
	tech.display();
	cout << "Salary: " << tech.calculateSalary() << endl;
	cout << "-------------------------------------" << endl;

	return 0;
}
