// Abdulqayumiv Abdukarim. ID: U2510080.
// Source.cpp
#include "Header.h"
int main() {
	// Student class objetcs
	Student student1("Ali", 20, 101, "Computer Science", 3.8, 3);
	Student student2("Sara", 19, 102, "Software Engineering", 3.5, 2);
	student1.displayStudent();
	student2.displayStudent();
	// Teacher class objects
	Teacher teacher1("Mr. Karimov", 40, 201, "Engineering", 5000, "C++ Programming");
	Teacher teacher2("Ms. Nargiza", 35, 202, "Mathematics", 4500, "Descrete Math");
	teacher1.displayTeacher();
	teacher2.displayTeacher();
	// Staff class objects
	Staff staff1("Jasur", 30, 301, "Administator", 3000, 8);
	Staff staff2("Dilshod", 45, 302, "Administartor", 3200, 8);
	staff1.displayStaff();
	staff2.displayStaff();
	return 0;
}
