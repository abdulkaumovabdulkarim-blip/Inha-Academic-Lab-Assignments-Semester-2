// Abdulqayumiv Abdukarim. ID: U2510080. Date: 2026.02.13. 

#include "Header.h"
int main() {
	cout << "-- Display Books ---" << endl;
	// 1 object
	Book book1;
	book1.Display();
	// 2 object
	Book book2(101, "clean Code", "Robert C. Martin", 45.50);
	book2.Display();
	// 3 object 
	Book book3(102, "The C++ Programmin Language", "Bjarne Stroustrup", -10);
	book3.Display();
	// 4 object
	Book book4 = book2;
	book4.Display();
	// Test setter and getter
	cout << "\n--- Test setter/getter ---" << endl;
	cout << "Old price of b2: " << book2.getPrice() << endl;
	book2.setPrice(60.00);
	cout << "New price of b2: " << book2.getPrice() << endl;
	book2.setPrice(-5.00);
	return 0;
}