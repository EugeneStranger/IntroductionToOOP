#include "Fraction.h"

#define delimiter "\n----------------------------------------------------\n"

#define CONSTRUCTORS_CHECK
//#define INPUT_CHECK1
//#define INPUT_CHECK2
//#define TYPE_CONVERSIONS
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OTHER


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
#endif;ghvh
#ifdef INPUT_CHECK1
	Fraction A(5,10);
	cout << "Введите простую дробь: ";	cin >> A;
	cout << A << endl;
	A.reduce();
	cout << A << endl;
#endif;
#ifdef INPUT_CHECK2
	Fraction A, B, C;
	cout << "Введите три простые дроби: "; cin >> A >> B >> C;
	cout << A << "\t" << B << "\t" << C << endl;
#endif;
#ifdef TYPE_CONVERSIONS
	int a = 2;			//No conversions
	double b = 3;		//Conversion from less to more (from int to double)
	int c = b;			//Conversion from more to less wihout data loss (from double to int)
	int d = 5.7;		//Conversion from more to less wih data loss (from double to int)
	//int e = "Hello";	//Types not compatible
	cout << 7. / 2 << endl; //Implicit conversion from less to more
#endif;
#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
	Fraction A = (Fraction)5; //Conversion from 'int' to 'Fraction'
					//Conversion from other to Class
					//Single-arguement constructor
	cout << A << endl;
	cout << delimiter;
	Fraction B;		//Default constructor
	cout << delimiter;
	B = Fraction(8);
	cout << delimiter;
	cout << B << endl;
	//Fraction C = 12;	// explicit constructor невозможно вызвать оператором присваивания
	//Fraction C(12);		// explicit constructor можно вызвать только так (есть ещё один способ)
	Fraction C{ 12 };	//или так)
#endif;
#ifdef CONVERSIONS_FROM_CLASS_TO_OTHER
	Fraction A(2, 3, 4);
	cout << A << endl;
	int a = (int)A;
	cout << a <<endl;
	double b = (double)A;
	cout << b << endl;
#endif;
	//Fraction A = 3.334;
	//cout << A << endl;

}