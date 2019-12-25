#pragma once
#include "Vector.h"
#include <iostream>

class Matrix
{
public:
	Matrix();//����������� ��� ����������
	Matrix(double** arr, int rows, int colums);
	Matrix(int rows, int kol);//����������� � �����������
	void Print();//����� �������
	double at(int i, int j) const;//��������� �������� �������
	void setAt(int i, int j, double num);//���������� ������� ������� 
	//���������� ����������
	void operator++ ();
	void operator++ (int);
	void operator-- ();
	void operator-- (int);
	int getRows() const;//������ ��� ��������� ���������� ����� ������� 
	double** getArray() const;//���������� �������
	friend std::ostream& operator<< (std::ostream &out, const Matrix &mat);
	double* convertToVector();
	int getKol() const;//������ ��� ��������� ���������� �������� ������� 
	~Matrix();//����������
private:
	double **arr;
	int rows, kol;
};

