#pragma once
#include "Matrix.h"
#include <iostream>
class Matrix;
class Vector
{
	
public:
	Vector();//конструктор без параметров
	Vector(double *vec, int len);
	Vector(int n);//конструктор с параметром n - количество элементов в массиве
	void Print();//вывод массива
	int getN() const;//геттер для длинны массива
	~Vector();//деструктор
	double& operator[] (const int index);//перегрузка для получения элемента по индексу
	//перегрузки операторов
	void operator++ ();
	void operator++ (int);
	void operator-- ();
	void operator-- (int);
	friend std::ostream& operator<< (std::ostream &out, const Vector &vec);
	double** convertToMatrix(int colums);
	Matrix* Vector::VectorToMatrix(int colums);//преобразование вектора в матрицу
private:
	int n;
	double *arr;
};


