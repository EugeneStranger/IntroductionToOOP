#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class Fraction;
int nod_evklid(int num, int den);
int nok(int den1, int den2);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction left, const Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);


class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}
	// Constructors
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Default Constructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "2ArgConstructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "3ArgConstructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "Copy Constructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//Operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}

	Fraction& operator++() //Prefix increment
	{
		this->integer++;
		return *this;
	}
	Fraction operator++(int) //Postfix increment
	{
		Fraction old = *this; //сохраняем исходное значение объекта
		integer++;
		return old;
	}
	Fraction& operator--() //Prefix increment
	{
		this->integer--;
		return *this;
	}
	Fraction operator--(int) //Postfix increment
	{
		Fraction old = *this; //сохраняем исходное значение объекта
		integer--;
		return old;
	}
	// Methods
	void print()const
	{
		if (integer) cout << integer;
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		std::swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
	{
		int nod = nod_evklid(this->numerator, this->denominator);
		this->numerator = this->numerator / nod;
		this->denominator = this->denominator / nod;
		//if (nod == 1) cout << "Невозможно сократить дробь." << endl;
		return *this;
	}
};

int nod_evklid(int num, int den)
{
	int nod = 1;
	while ((num != 0) and (den != 0))
	{
		if (num > den)	num = num % den;
		else den = den % num;
	}
	nod = den + num;
	return nod;
}
int nok(int den1, int den2)
{
	return (den1 * den2) / nod_evklid(den1, den2);
}
Fraction operator*( Fraction left,  Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator/(const Fraction left,const Fraction right)
{
	return left*right.inverted();
}
Fraction operator+(Fraction left,  Fraction right)
{
	left.to_improper();
	right.to_improper();
	int nok1 = nok(left.get_denominator(), right.get_denominator());
	return Fraction
	(
		(left.get_numerator()*(nok1/left.get_denominator())+ right.get_numerator() * (nok1 / right.get_denominator())),
		nok1
	).to_proper();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	int nok1 = nok(left.get_denominator(), right.get_denominator());
	return Fraction
	(
		(left.get_numerator() * (nok1 / left.get_denominator()) - right.get_numerator() * (nok1 / right.get_denominator())),
		nok1
	).to_proper();
}

bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	left.reduce();
	right.reduce();
	int nok1 = nok(left.get_denominator(), right.get_denominator());
	return ((left.get_numerator() * (nok1 / left.get_denominator())) < (right.get_numerator() * (nok1 / right.get_denominator())));
}
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	left.reduce();
	right.reduce();
	int nok1 = nok(left.get_denominator(), right.get_denominator());
	return ((left.get_numerator() * (nok1 / left.get_denominator())) == (right.get_numerator() * (nok1 / right.get_denominator())));
}
bool operator>(Fraction left, Fraction right)
{
	bool result = true;
	if ((left < right) || (left == right)) result = false;
	return result;
}
bool operator!=(Fraction left, Fraction right)
{
	bool result = true;
	if ((left == right)) result = false;
	return result;
}
bool operator>=(Fraction left, Fraction right)
{
	bool result = false;
	if ((left > right)||(left == right)) result = true;
	return result;
}
bool operator<=(Fraction left, Fraction right)
{
	bool result = false;
	if ((left < right) || (left == right)) result = true;
	return result;
}
//#define CONSTRUCTORS_CHECK
//#define 

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;				//Default constructor
	A.print();

	Fraction B = 5;			//1 Arg constructor
	B.print();

	Fraction C(1, 2);		//2 Arg constructor
	C.print();

	Fraction D(2, 3, 4);	//3 Arg constructor
	D.print();

	Fraction E = C;		    //CopyConstructor
	E.print();

	Fraction F;				//CopyAssignment
	F = D;
	F.print();
#endif;
	Fraction A(1, 2, 5);
	A.print();
//	Fraction B(1, 5, 10);
//	B.print();
	A--;
	A.print();

	//if (B >= A) { cout << "B>=A" << endl;}
	
}