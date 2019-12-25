#pragma once
#include "Matrix.h"
#include <iostream>
class Matrix;
class Vector
{
	
public:
	Vector();//����������� ��� ����������
	Vector(double *vec, int len);
	Vector(int n);//����������� � ���������� n - ���������� ��������� � �������
	void Print();//����� �������
	int getN() const;//������ ��� ������ �������
	~Vector();//����������
	double& operator[] (const int index);//���������� ��� ��������� �������� �� �������
	//���������� ����������
	void operator++ ();
	void operator++ (int);
	void operator-- ();
	void operator-- (int);
	friend std::ostream& operator<< (std::ostream &out, const Vector &vec);
	double** convertToMatrix(int colums);
	Matrix* Vector::VectorToMatrix(int colums);//�������������� ������� � �������
private:
	int n;
	double *arr;
};


