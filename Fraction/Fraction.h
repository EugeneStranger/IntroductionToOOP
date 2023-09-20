#pragma once
#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

/*class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction left, const Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);*/

class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);
	// Constructors
	Fraction();
	explicit Fraction(int integer);
	Fraction(double decimal);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();
	//Operators
	Fraction& operator=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);
	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	Fraction& operator++(); //Prefix increment
	Fraction operator++(int); //Postfix increment
	Fraction& operator--(); //Prefix increment
	Fraction operator--(int); //Postfix increment
	
	//Type-cast operators
	explicit operator int() const;
	explicit operator double() const;

	// Methods
	void print()const;
	Fraction& to_proper();
	Fraction& to_improper();
	Fraction inverted()const;
	Fraction& reduce();
};
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction left, const Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
bool operator<(Fraction left, Fraction right);
bool operator==(Fraction left, Fraction right);
bool operator>(const Fraction& left, const Fraction& right);
bool operator!=(const Fraction& left, const Fraction& right);
bool operator>=(const Fraction& left, const  Fraction& right);
bool operator<=(const Fraction& left, const  Fraction& right);

std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& is, Fraction& obj);