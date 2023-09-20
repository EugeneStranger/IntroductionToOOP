#include "String.h"
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