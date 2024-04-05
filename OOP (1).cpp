#include <iostream>
#include <string>

using namespace std;

class Person {
	string name;
	Person* spouse;
public:
	Person() :spouse(nullptr) {}
	Person(string newName) :spouse(nullptr) { name = newName; }
	bool marry(Person& other);

};

bool Person::marry(Person& other) {
	if (spouse != nullptr || other.spouse != nullptr)
		return false;
	spouse = &other;
	other.spouse = this;
	return true;
}

class Measurement {
	int feet;
	int inches;
	void normalize();
public:
	Measurement() : feet(0), inches(0) {}
	Measurement(int newInches) : feet(0), inches(newInches) { normalize(); }
	int getFeet()const { return feet; }
	int getInches()const { return inches; }
	int getAbsoluteInches()const { return 12 * feet + inches; }
	void setFeet(int newFeet) { feet = newFeet; }
	void setInches(int newInches) { inches = newInches; normalize(); }
	Measurement operator++(int);
	Measurement& operator++();
	Measurement operator--(int);
	Measurement& operator--();
	friend ostream& operator<<(ostream& outs, const Measurement& rhs); //NON MEMBER!!!
};
ostream& operator<<(ostream& outs, const Measurement& rhs) {
	outs << rhs.feet << "' " << rhs.inches << "\""; // 6' 0"
	return outs;
}
Measurement Measurement::operator++(int) { //int is an indication that this is POST-increment obj++ (not ++obj)
	Measurement temp(*this);
	inches++;
	normalize();
	return temp;
}

Measurement& Measurement::operator++() { //this is a PRE-INCREMENT function! (++obj)
	inches++;
	normalize();
	return *this; // (++(++obj)) or ++++obj
}

Measurement operator+(const Measurement& lhs, const Measurement& rhs) { //x+y -> x is lhs and y is rhs
	Measurement temp;
	temp.setInches(lhs.getAbsoluteInches() + rhs.getAbsoluteInches());
	return temp;
}

void Measurement::normalize() {
	while (inches >= 12) {
		feet++;
		inches -= 12;
	}
	while (inches < 0) {
		feet--;
		inches += 12;
	}
}

int main()
{
	Measurement m1(10);
	Measurement m2(5);
	Measurement m3 = m1 + m2;  //operator+(m1,m2)

	cout << "M3= " << m3 << endl; //(((cout<< "M3=" ) << m3) <<endl)
}