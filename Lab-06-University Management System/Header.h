// Header.h

#include <iostream>
#include <string>
using namespace std;
// Class
// Class Person
class Person {
// Protected members
protected:
	string Name;
	int Age;
	char Gender;
	// Public members
public:
	Person(string a, int b, char c) : Name(a), Age(b), Gender(c) {
		if (b < 0) {
			cout << "Invalid age! Setting it positive" << endl;
			Age = abs(b);
		}
		if (c != 'M' && c != 'F') {
			cout << "Invalid gender for " << Name <<".Gender set to U." << endl;
			Gender = 'U';
		}
	}
	// Virtual members
	virtual void show() {
		cout << "Name: " << Name << endl;
		cout << "Age: " << Age << endl;
		cout << "Gender: " << Gender << endl;
	}
	virtual ~Person(){}
};
// Class Student
class Student : public Person {
	// Private members
	int IDnumber;
	string subject;
	int grade;
	// Public members
public:
	Student(string a, int b, char c, int e, string f, int g) : Person(a, b, c) {
		setStudent(e, f, g);
	}
	void setStudent(int ID, string sub, int gr) {
		if (ID < 0) {
			cout << "Invalid student ID for " << Name << ".ID set to 0." << endl;
			ID = 0;
		}
		if (gr < 0 || gr > 100) {
			cout << "Invalid grade for " << Name << ". Grade set to 8." << endl;
			gr = 8;
		}
		IDnumber = ID;
		subject = sub;
		grade = gr;
	}
	// Overrided function show
	void show() override {
		cout << "Student details" << endl;
		Person::show();
		cout << "ID Number:" << IDnumber << endl;
		cout << "Subject: " << subject << endl;
		cout << "Grade: " << grade << endl;
	}
};
// Class Teacher
class Teacher : public Person {
	// Private members
private:
	string courseInfo;
	// Public members
public:
	Teacher(string a, int b, char c, string d) : Person(a, b, c) {
		setTeacher(d);
	}
	void setTeacher(string crsInfo) {
		courseInfo = crsInfo;
	}
	// Overrided function show
	void show() override {
		cout << "Teacher details" << endl;
		Person::show();
		cout << "Course Info: "<< courseInfo << endl;
	}
};

