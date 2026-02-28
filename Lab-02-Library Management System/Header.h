#include <iostream>
#include <string>
using namespace std;

class Book {
private:
	int bookID;
	string title;
	string author;
	double price;
public:
	Book() : bookID(0), title("Unknown"), author("Unknown"), price(0.0) { }
	Book(int a, string b, string c, double d) {
		bookID = a;
		title = b;
		author = c;
		if (d < 0)
			price = 0.0;
		else
			price = d;
	}
	Book(const Book& other) {
		bookID = other.bookID;
		title = other.title;
		author = other.author;
		price = other.price;
	}
	~Book() {
		cout << "The book is deleted" << endl;
	}
	void setPrice(double d) {
		if (d < 0) {
			cout << "Invalid input! Price cannot be negative. Keeping old price" << endl;
		}
		else
			price = d;
	}
	double getPrice() {
		return price;
	}
	void Display() const {
		cout << "\nBook Details:" << endl;
		cout << "\tID: " << bookID << endl;
		cout << "\tTitle: " << title << endl;
		cout << "\tAuthor: " << author << endl;
		cout << "\tPrice: " << price << endl;
	}
};