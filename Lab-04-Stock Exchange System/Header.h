// Header.h

#include <iostream>
#include <string>
using namespace std;

class StockEx {
private:
	string currency;
	float mktrate;
	string date;
public:
	StockEx(){}
	StockEx(string a, float b, string c) : currency(a), mktrate(b), date(c) {}
	double operator*(double amount) {
		return (amount * mktrate);
	}
	float operator-(const StockEx& other) {
		return (mktrate - other.mktrate);
	}
	void setCurrency(string c) {
		currency = c;
	}
	string getCurrency() {
		return currency;
	}
	void setMktrate(float m) {
		mktrate = m;
	}
	float getMktrate() {
		return mktrate;
	}
	void setDate(string d) {
		date = d;
	}
	string getDate() {
		return date;
	}
	friend bool operator>(const StockEx& left, const StockEx& right);
};

bool operator>(const StockEx& left, const StockEx& right) {
	return left.mktrate > right.mktrate;
}
ostream& operator<<(ostream& out, StockEx& s) {
	out << "Currency: " << s.getCurrency() << endl;
	out << "Market Rate: " << s.getMktrate() << endl;
	out << "Date: " << s.getDate() << endl;
	return out;
}
istream& operator>>(istream& in, StockEx& s) {
	string Currency;
	float Rate;
	string Date;
		cout << "Enter currency: ";
		in >> Currency;
		cout << "Enter market rate: ";
		in >> Rate;
		cout << "Enter date: ";
		in >> Date;
		s.setCurrency(Currency);
		s.setMktrate(Rate);
		s.setDate(Date);
	return in;
}