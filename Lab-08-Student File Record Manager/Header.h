// Header.h

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Main menu function
int main_menu() {
	int choice;
	cout << "Student file record" << endl;
	cout << "1. Write student records to text file" << endl;
	cout << "2. Read student records from text file" << endl;
	cout << "3. Convert text file to binary file" << endl;
	cout << "4. Read student records from binary file" << endl;
	cout << "0. Exit" << endl;
	cout << "Enter choice: ";
	cin >> choice;
	return choice;
}

// Function to write students in file
void writeStudents() {
	ofstream writeStudents("students.txt");
	if (!writeStudents) {
		cout << "Cannot open file!" << endl;
		return;
	}

	int num_of_students, id;
	string name;
	double gpa;
	cout << "How many students do you want to enter? ";
	cin >> num_of_students;

	for (int i = 0; i < num_of_students; i++) {
		while (true) {
			cout << "\nStudent " << i + 1 << ": " << endl;
			cout << "Enter ID: ";
			cin >> id;
			if (cin.fail()) {
				cout << "Enter only numbers" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			}
			if (id < 0) {
				cout << "ID has to be positive number" << endl;
				continue;
			}
			break;
		}
		cout << "Enter full name: ";
		cin >> name;
		while (true) {
			cout << "Enter GPA: ";
			cin >> gpa;
			if (cin.fail()) {
				cout << "Enter only numbers" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			}
			if (gpa < 0) {
				cout << "GPA has to be positive number" << endl;
				continue;
			}
			break;
		}

		writeStudents << id << " " << name << " " << gpa << endl;
	}
	writeStudents.close();
	cout << "Records written successfully to students.txt.\n" << endl;
}

// Function to get students from file
void getStudents() {
	ifstream getStudents("students.txt");

	int id;
	double gpa;
	string name;

	if (!getStudents) {
		cout << "Cannot open file!" << endl;
		return;
	}

	cout << "\nID\tName\tGPA" << endl;
	cout << "---------------------------" << endl;
	while (getStudents >> id >> name >> gpa) {

		if (getStudents.eof()) {
			cout << "Reached end of file\n" << endl;
			break;
		}

		cout << id << "\t" << name << "\t" << gpa << endl;

	}
	getStudents.close();
	cout << endl;
}

// Function to write students in binary file
void b_writeStudents() {
	ofstream b_writeStudents("students.dat", ios::binary);
	if (!b_writeStudents) {
		cout << "Cannot open binary file!" << endl;
		return;
	}

	ifstream readStudents("students.txt");
	if (!readStudents) {
		cout << "Cannot open txt file!" << endl;
		return;
	}

	int n_students = 0, id;
	string name;
	double gpa;

	while (readStudents >> id >> name >> gpa) {
		n_students++;

		b_writeStudents.write((char*)&id, sizeof(id));

		int nameLen = name.size();
		b_writeStudents.write((char*)&nameLen, sizeof(nameLen));

		b_writeStudents.write(name.c_str(), nameLen);

		b_writeStudents.write((char*)&gpa, sizeof(gpa));
	}
	b_writeStudents.close();
	cout << "\n" << n_students << " record(s) converted successfully to students.dat.\n" << endl;
}

// Function to get students from binary file
void b_getStudents() {
	ifstream b_getStudents("students.dat", ios::binary);

	int id;
	double gpa;
	string name;

	if (!b_getStudents) {
		cout << "Cannot open file!" << endl;
		return;
	}

	cout << "\nID\tName\tGPA" << endl;
	cout << "---------------------------" << endl;

	while (b_getStudents.read((char*)&id, sizeof(id))) {

		int nameLen;
		b_getStudents.read((char*)&nameLen, sizeof(nameLen));

		name.resize(nameLen);

		b_getStudents.read(&name[0], nameLen);

		b_getStudents.read((char*)&gpa, sizeof(gpa));

		cout << id << "\t" << name << "\t" << gpa << endl;
	}
	b_getStudents.close();
	cout << endl;
}