// Abdulqayumiv Abdukarim. ID: U2510080.
// Source.cpp

#include "Header.h"
int main() {
	// Class Objects
	// Objects Student
	Student student1("Ali", 20, 'L', -12, "Mathematics", 110);
	Teacher teacher1("Salima", 40, 'F', "Object Oriented Programming");
	// Objects Teacher
	Student student2("Malika", 19, 'F', 102, "Physics", 95);
	Teacher teacher2("Bekzod", 35, 'D', "Data Structure");
	// Call show function to show the data
	student1.show();
	student2.show();
	teacher1.show();
	teacher2.show();
	return 0;
}
