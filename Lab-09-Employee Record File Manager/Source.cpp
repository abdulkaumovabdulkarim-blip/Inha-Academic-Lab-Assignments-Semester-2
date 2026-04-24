// Abdulqayumiv Abdukarim. ID: U2510080.
// Source.cpp
#include "Header.h"
// Functions
/*
Exercise 9: Employee Record File Manager
Objective: You will create a C++ program that works with both text files and binary
files. The program must demonstrate correct file handling and exception handling.
Tasks:
Create a menu-driven program called Employee Record File Manager. Your
program will manage employee records using a text file named employees.txt and a
binary file named employees.dat.
Define a class Employee. The class contain ID, Name[20] and salary. The class also
must provide setters and getters.
Create menu-driven interface:
1. Create text file and save records.
Write student records into employees.txt. Create and write 5 employee records
into employees.txt.
2. Create binary file and save records.
Store employee records in fixed-size format so that any record can be
accessed directly. Create employees.dat and initialize it with 10 empty
records.
3. Add record to binary file.
Add a record into a specific position in the binary file.
4. Delete an employee record at a specific position.
Delete a record by replacing it with an empty record.
5. Update record in binary file.
Update salary or name of a record.
Exception Handling:
Your program must use try, catch, and throw. You must handle at least these errors
file cannot be opened, invalid record position, salary cannot be negative and trying to
read an empty record. For example: If user enters position 0 or 11, throw an
exception. If salary is less than 0, throw an exception. If file opening fails, throw an
exception message.
*/
int Menu();
void addRecord(fstream& file);
void deleteRecord(fstream& file);
void updateRecord(fstream& file);

int main() {
	// Create txt file if it does not exist
	try {
		ofstream createEmployeeTxtFile("employee.txt", ios::app);
		if (!createEmployeeTxtFile.is_open()) {
			throw string("Txt File could not be created.");
		}
		createEmployeeTxtFile.close();
	}
	catch(string x) {
		cerr << x << endl;
		exit(1);
	}

	fstream employeeTxtFile("employee.txt", ios::in | ios::out);
	try {
		if (!employeeTxtFile.is_open()) {
			throw string("Txt File could not be opened.");
		}
	}
	catch (string x) {
		cerr << x << endl;
		exit(1);
	}

	// Creating 5 employee record
	Employee staff[5] = {
		Employee(1, "Ali", 1000.0),
		Employee(2, "Asad", 2000.0),
		Employee(3, "Anvar", 3000.0),
		Employee(4, "Axad", 4000.0),
		Employee(5, "Akmal", 5000.0)
	};

	for (int i = 0; i < 5; i++) {
		employeeTxtFile << staff[i].getID() << " "
			            << staff[i].getName() << " "
			            << staff[i].getSalary() << endl;
	}
	employeeTxtFile.close();
	cout << "5 Employee records saved in employee.txt file successfully!\n" << endl;


	// Create binary file if it does not exist
	ofstream createEmployeeBinFile("employee.dat", ios::app | ios::binary);
	try {
		if (!createEmployeeBinFile) {
			throw string("Binary File could not be created.");
		}
		createEmployeeBinFile.close();
	}
	catch (string x) {
		cerr << x << endl;
		exit(1);
	}

	fstream employeeFile("employee.dat", ios::in | ios::out | ios::binary);
	try {
		if (!employeeFile) {
			throw string("Binary File could not be opened.");
		}
	}
	catch (string x) {
		cerr << x << endl;
		exit(1);
	}

	// Write 10 blank records to the file
	employeeFile.seekg(0, ios::end);
	if (employeeFile.tellg() == 0) {
		Employee emptyRecord(0, "", 0.0);
		for (int i = 0; i < 10; ++i)
			employeeFile.write(reinterpret_cast<char*>(&emptyRecord), sizeof(Employee));
	}
	else {
		cout << "Bin file already has 10 empty spaces" << endl;
	}

	cout << "Binary file initialized with 10 empty records.\n" << endl;

	// Create loop
	int choice;
	while ((choice = Menu()) != 0) {
		cout << endl;
		switch (choice) {
		case 1:
			addRecord(employeeFile);
			break;
		case 2:
			deleteRecord(employeeFile);
			break;
		case 3:
			updateRecord(employeeFile);
			break;
		default:
			cout << "Incorrect choice." << endl;
			break;
		}
	}
	employeeFile.close();


	return 0;
}

// Menu function
int Menu() {
	int ch;
	// Menu from 3 options
	cout << "1 - Add record to binary file" << endl;
	cout << "2 - Delete an empl0yee record at a specific position" << endl;
	cout << "3 - Update record in binary file" << endl;
	cout << "0 - Exit" << endl;
	cout << "Enter choice: ";
	cin >> ch;
	return ch;
}

// Add Record Function
void addRecord(fstream& file) {
	file.clear(); // Clear from all errors
	try {
		int pos;
		cout << "Enter position (1-10): "; 
		cin >> pos;
		// Exception: Invalid record position
		if (pos < 1 || pos > 10) 
			throw string("Invalid record position! Range is 1-10.");

		int id; 
		string name; 
		double salary;
		cout << "Enter ID: "; 
		cin >> id;
		cout << "Enter Name: "; 
		cin >> name;
		cout << "Enter Salary: "; 
		cin >> salary;

		// Exception: Salary cannot be negative
		if (salary < 0) 
			throw string("Salary cannot be negative!");

		Employee employee(id, name, salary);

		// Position pointing
		file.seekp((pos - 1) * sizeof(Employee));
		file.write(reinterpret_cast<char*>(&employee), sizeof(Employee));
		cout << "Record added to position " << pos << " successfully!" << endl;
	}
	catch (string e) {
		cerr << "Error: " << e << endl;
	}
}

void deleteRecord(fstream& file) {
	try {
		int pos;
		cout << "Enter position to delete (1-10): "; 
		cin >> pos;
		if (pos < 1 || pos > 10) 
			throw string("Invalid record position!");

		// Creatint empty space to replace
		Employee emptyRecord(0, "", 0.0);
		file.seekp((pos - 1) * sizeof(Employee));
		file.write(reinterpret_cast<char*>(&emptyRecord), sizeof(Employee));
		cout << "Record at position " << pos << " has been deleted (replaced with empty)." << endl;
	}
	catch (string e) {
		cerr << "Error: " << e << endl;
	}
}

void updateRecord(fstream& file) {
	try {
		int pos;
		cout << "Enter position to update (1-10): "; 
		cin >> pos;
		if (pos < 1 || pos > 10) 
			throw string("Invalid record position!");
		file.clear(); // Clear from all errors

		// Check whether it is empty
		Employee employee;
		file.seekg((pos - 1) * sizeof(Employee));
		file.read(reinterpret_cast<char*>(&employee), sizeof(Employee));

		// Exception: Trying to read an empty record
		if (employee.getID() == 0) 
			throw string("Trying to update an empty record!");

		string newName; 
		double newSalary;
		cout << "Current record at position " << pos << ": " << employee.getName() << " ($" << employee.getSalary() << ")" << endl;
		cout << "Enter new name: "; 
		cin >> newName;
		cout << "Enter new salary: "; 
		cin >> newSalary;

		if (newSalary < 0) 
			throw string("Salary cannot be negative!");

		employee.setName(newName);
		employee.setSalary(newSalary);

		file.seekp((pos - 1) * sizeof(Employee));
		file.write(reinterpret_cast<char*>(&employee), sizeof(Employee));
		cout << "Record updated successfully!" << endl;
	}
	catch (string e) {
		cerr << "Error: " << e << endl;
	}
}