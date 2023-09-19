#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------------------------------------------------\n"

class String
{
	int size;	//Размер строки лучше указывать в байтах
	char* str;	//Адрес строки в динамической памяти
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	//			Constructors
	explicit String(int size = 80) :size(size), str(new char[size] {})	//Default constructor
	{
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char* str) :String(strlen(str) + 1)					//Single-argument constructor
	{
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other):String(other.str)
	{
		//Deep copy(побитовое копирование)
		cout << "CopyConstructor:" << this << endl;
	}
	String(String&& other):size(other.size),str(other.str)
	{
		//Shallow copy
		other.size = 0;
		other.str = 0;
		cout << "MoveConstructor:" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destructor:\t" << this << endl;
	}

	// operators
	String& operator=(const String& other)
	{
		if (this == &other) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment: " << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		if (this == &other) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}
	char operator[](int i)const
	{
		return this->str[i];
	}
	char& operator[](int i)
	{
		return this->str[i];
	}
	//			Methods
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}

	//

};

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
String operator+(const String& left, const String& right)
{
	String cat(left.get_size()+right.get_size()-1);
	for (int i = 0; i<left.get_size(); i++)
		cat[i] = left[i];
		//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i+left.get_size()-1] = right[i];
	return cat;
}

#define BASECHECK
//#define CALLING_CONSTRUCTOR

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASECHECK
	cout << sizeof("Hello") << endl;
	String str;
	str.print();

	String str1 = "Hello";
	str1 = str1;
	cout << str1 << endl;
	String str2 = "World";
	cout << str2 << endl;
	cout << delimiter;
	String str3 = str1 + str2;
	cout << str3 << endl;
	cout << delimiter;
	String str4;
	str4 = str1 + str2;
	cout << str4 << endl;
	String str5 = str4;
	cout << str5 << endl;
#endif // BASECHECK
#ifdef CALLING_CONSTRUCTOR
	String str1;				//Default constructor;
	str1.print();

	String str2(5);				//Expliciet constructor
	str2.print();

	String str3 = "Hello";		//Single-argument constructor
	str3.print();

	String str4();				//Таким образом, явно не вызывается конструктор по умолчанию,и следовательно объект тоже не создаётся
								//Таким образом объявляется функция str4(), которая ничего не принимает и 
								//возвращает значение типа 'String'
	//str4.print();
	//Если нужно явно вызвать конструктор по умолчанию, то это можно сделать так:
	String str5{};				//Явный вызов конструктора по умолчанию
	str5.print();
#endif // CALLING_CONSTRUCTOR

}