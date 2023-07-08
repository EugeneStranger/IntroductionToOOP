#include<iostream>
using namespace std;
#define delimiter "\n---------------------------------------------------\n"

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//Constructors
	/*Point()
	{
		x = y = double(); //type() - это значение по умолчанию для заданного типа
						  //Таким образом мы якобы вызываем конструктор по умолчанию для заданного типа
		cout << "Default Constructor:\t\t" << this << endl;

	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "Singl-argument constructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Double-arguments constructor:\t" << this << endl;
	}
	//Deep Copy - побитовое копирование
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "Copy-constructor:\t\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t\t" << this << endl;

	}

	//Operators^
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t\t" << this << endl;
		return *this;
	}
	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		cout << "CopyAssignment:\t\t\t" << this << endl;
		return *this;
	}
	Point& operator-=(const Point& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		cout << "CopyAssignment:\t\t\t" << this << endl;
		return *this;
	}
	Point& operator*=(const Point& other)
	{
		this->x *= other.x;
		this->y *= other.y;
		cout << "CopyAssignment:\t\t\t" << this << endl;
		return *this;
	}
	Point& operator++() //Prefix increment
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int) //Postfix increment
	{
		Point old = *this; //сохраняем исходное значение объекта
		x++;
		y++;
		return old;
	}
	Point& operator--() //Prefix decrement
	{
		x--;
		y--;
		return *this;
	}
	Point operator--(int) //Postfix decrement
	{
		Point old = *this; //сохраняем исходное значение объекта
		x--;
		y--;
		return old;
	}

	//Methods
	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
		//cout << "X = " << &x << "\tY = " << &y << endl;

	}
};
double distance(const Point& A, const  Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
}
Point operator+(const Point& left, const Point& right)
{
	/*Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	Point result
	(
		left.get_x() + right.get_x(),
		left.get_y() + right.get_y()
	);*/
	return Point
	(
		left.get_x() + right.get_x(),
		left.get_y() + right.get_y()
	);
}
Point operator-(const Point& left, const Point& right)
{
	return Point
	(
		left.get_x() - right.get_x(),
		left.get_y() - right.get_y()
	);
}
Point operator*(const Point& left, const Point& right)
{
	return Point
	(
		left.get_x() * right.get_x(),
		left.get_y() * right.get_y()
	);
}
Point operator/(const Point& left, const Point& right)
{
	return Point
	(
		left.get_x() / right.get_x(),
		left.get_y() / right.get_y()
	);
}
bool operator==(const Point& left, const Point& right)
{
	return ((left.get_x() == right.get_x()) & (left.get_y() == right.get_y()));
}
bool operator!=(const Point& left, const Point& right)
{
	return ((left.get_x() != right.get_x()) || (left.get_y() != right.get_y()));
}

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTOR_CHECK
//#define ASSIGNEMENT_CHECK
//#define INCREMEMENT_CHECK
//define DECREAMENT_CHECK
//define ARITHMETICAL_CHECK
//define COMPARING_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	int a;
	*A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl; */

#endif;
#ifdef DISTANCE_CHECK
		Point A;
	Point B;
	A.set_x(2);
	A.set_y(3);
	B.set_x(7);
	B.set_y(8);
	cout << "A: " << A.get_x() << "\t" << A.get_y() << endl;
	cout << "B: " << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'А' до точки 'B':\t" << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'А' до точки 'B':\t" << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'B' до точки 'A':\t" << distance(B, A) << endl;
	cout << delimiter << endl;
#endif;
#ifdef CONSTRUCTOR_CHECK
	Point A;
	A.print();
	cout << delimiter << endl;
	Point B = 5; //Single-argument constructor
	B.print();
	cout << delimiter << endl;
	Point C(2, 3); //Double-arguments constructor
	C.print();
	cout << delimiter << endl;
	Point D = C;	//Copy-constructor
	D.print();
	cout << delimiter << endl;
	Point E;
	E = D;			//CopyAssignment
	E.print();
	cout << delimiter << endl;
#endif;
#ifdef ASSIGNEMENT_CHECK
	/*int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;
	Point A, B, C;
	A = B = C = Point(2, 3);
	A.print();
	B.print();
	C.print();*/
	Point A(6, 4);
	Point B(2, 2);
	A.print();
	B.print();
	A += B;
	A.print();
	A -= B;
	A.print();
	A *= B;
	A.print();

#endif; 
#ifdef INCREMEMENT_CHECK
	/*int a = 2;
		int b = 3;
		int c = a + b;
		cout << c << endl;*/

	Point A(2, 3);
	A.print();
	Point B(7, 8);
	B.print();
	Point C = A + B;
	C.print();
	Point D = A - B;
	D.print();
	Point E = A * B;
	E.print();
	A = B++;
	A.print();
	B.print();
#endif;
#ifdef ARITHMETICAL_CHECK
	Point A(4, 5);
	A.print();
	Point B(2, 3);
	B.print();
	Point C = A + B;
	C.print();
	C = A - B;
	C.print();
	C = A * B;
	C.print();
	C = A / B;
	C.print();
#endif;
	Point A(3, 3), B(3, 4);
	A.print();
	B.print();
	if (A == B)cout << "A равно B" << endl;
	else { cout << "A не равно B" << endl; }
	if (A != B)cout << "A не равно B" << endl;
	else { cout << "A равно B" << endl; }
}