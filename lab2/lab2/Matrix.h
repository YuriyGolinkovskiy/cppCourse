#pragma once
#include "Vector.h"
#include <iostream>

class Matrix
{
public:
	Matrix();//конструктор без параметров
	Matrix(double** arr, int rows, int colums);
	Matrix(int rows, int kol);//конструктор с параметрами
	void Print();//вывод матрицы
	double at(int i, int j) const;//получение элемента матрицы
	void setAt(int i, int j, double num);//установить элемент матрицы 
	//перегрузки операторов
	void operator++ ();
	void operator++ (int);
	void operator-- ();
	void operator-- (int);
	int getRows() const;//геттер дл€ получени€ количества линий матрицы 
	double** getArray() const;//возвращает матрицу
	friend std::ostream& operator<< (std::ostream &out, const Matrix &mat);
	double* convertToVector();
	int getKol() const;//геттер дл€ получени€ количества столбцов матрицы 
	~Matrix();//деструктор
private:
	double **arr;
	int rows, kol;
};

