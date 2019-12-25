#include <iostream>
#include "Fraction.h"
#include <cmath>
using namespace std;

int ymnayaPeremennaya = 1000000;//для корректного сокращения

int Fraction::nCount = 0;

Fraction::Fraction(){}
Fraction::Fraction(const Fraction& f) 
{
	x = f.x, y = f.y;
	nCount++;
}
Fraction::Fraction(int inputF)
{
	x = inputF, y = 1;
	nCount++;
}
Fraction::Fraction(double inputF)
{
	x = inputF	;
	y = 1;
	reduce();
	nCount++;
}
Fraction::Fraction(int i, int j)//конструктор с параметрами, создает дробь и сокращает ее и увеличивает счетчик созданных объектов
{
	if (j == 0)
		cout << "Exeption!" << endl;
	else
		x = i, y = j;
	reduce();
	nCount++;
}
//перегрузки операторов сложения, вычитания, умножения,деления
Fraction Fraction::operator+(const Fraction& inputF) {
	Fraction f(x*inputF.y + inputF.x*y, y*inputF.y);
	return f;
}
Fraction Fraction::operator-(const Fraction& inputF) {
	Fraction f(x*inputF.y - inputF.x*y, y*inputF.y);
	return f;
}
Fraction Fraction::operator*(const Fraction& inputF) {
	Fraction f(x*inputF.x, y*inputF.y);
	return f;
}
Fraction Fraction::operator/(const Fraction& inputF) {
	Fraction f(x*inputF.y, y*inputF.x);
	return f;
}

void Fraction::reduce()//метод для сокращения дроби
{
	if (y != 0) {
		int temp = gsd(abs(x), abs(y));
		x /= temp, y /= temp;
	}
}
int Fraction::getCount()//геттер возвращаюший количестов созданных объектов
{
	return nCount;
}
void Fraction::print() //вывод дроби
{
	cout << x << "/" << y << endl;
}

int Fraction::gsd(int n1, int n2) //нахождение наибольшего общего делителя чисел
{ 
	if (n2 == 0) {
		return n1;
	}
	else {
		return gsd(n2, n1 % n2);
	}
}
void Fraction::printAsFraction(double dec_fraction) {//перегрузка вывода десятичной дроби в виде обыкновенной из параметра числа с палвающей точкой
	int temp = gsd(abs(dec_fraction * ymnayaPeremennaya), ymnayaPeremennaya);
	int x = (dec_fraction * ymnayaPeremennaya)/temp;
	int y = ymnayaPeremennaya / temp;
	cout << dec_fraction << " = " << x << "/" << y << endl;
}
void Fraction::printAsFraction(char* dec_fraction) //перегрузка вывода десятичной дроби в виде обыкновенной из параметра строки
{
	double x = atof(dec_fraction);
	int temp = gsd(abs(x * ymnayaPeremennaya), ymnayaPeremennaya);
	x = (x * ymnayaPeremennaya) / temp;
	int y = ymnayaPeremennaya / temp;
	cout << dec_fraction << " = " << x << "/" << y << endl;
}
Fraction::~Fraction()//деструктор,уменьшает счетчик созданных объектов в данный момент
{
	nCount--;
}