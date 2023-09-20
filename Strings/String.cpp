#include "String.h"
////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////			Определение класса - Class defenition				////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
	//:: - Scope operator (Оператор разрешения видимости)
	//scope::name
	//namespace::name...(переменная, константа, функция, метод и т.д.)
int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
//			Constructors
// Ключевое слово 'expliciet' можно использовать только внутри класса
//Параметры по умолчанию пишутся в прототипах функций
String::String(int size /*=80*/) :size(size), str(new char[size] {})	//Default constructor
{
	cout << "DefConstructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)					//Single-argument constructor
{
	for (int i = 0; str[i]; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	//Deep copy(побитовое копирование)
	cout << "CopyConstructor:" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	//Shallow copy
	other.size = 0;
	other.str = 0;
	cout << "MoveConstructor:" << this << endl;
}
String::~String()
{
	delete[] str;
	cout << "Destructor:\t" << this << endl;
}

// operators
String& String::operator=(const String& other)
{
	if (this == &other) return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment: " << this << endl;
	return *this;
}
String& String::operator=(String&& other)
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
char String::operator[](int i)const
{
	return this->str[i];
}
char& String::operator[](int i)
{
	return this->str[i];
}
//			Methods
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

//

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	return cat;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////			Определение класса - Class defenition finished		////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////