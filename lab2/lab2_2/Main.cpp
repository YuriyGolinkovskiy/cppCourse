#include <iostream>
#include "Fraction.h"
using namespace std;


void main() {
	//создание объектов при помощи конструктора с параметрами
	Fraction f1(-5);
	Fraction f2(2, 18);
	Fraction f3(3.14);
	//создание объектов при помощи перегруженных операторов
	Fraction f4 = f2 + f2;
	Fraction f5 = f4 - f2;
	Fraction f6 = f4 * f2;
	Fraction f7 = f4 / f6;

	cout <<"count objects:"  << f1.getCount() << endl;
	cout << "f1 = -5 = ";
	f1.print();
	cout << "f2 = 2/18 = ";
	f2.print();
	cout << "f3 = 3.14 = ";
	f3.print();
	cout << "f4 = 1/9 + 1/9 = ";
	f4.print();
	cout << "f5 = 2/9 - 1/9 = ";
	f5.print();
	cout << "f6 = 2/9 * 1/9 = ";
	f6.print();
	cout << "f7 = 2/9 / 2/81 = ";
	f7.print();

	cout << "max obshiy delitel 18 i 12: " << Fraction::gsd(18, 12) << endl;//нахождение общего делителя 18 и 12
	//преобразования в десятичную дробь
	Fraction::printAsFraction(0.25);
	Fraction::printAsFraction("0,43");

	system("pause");
}