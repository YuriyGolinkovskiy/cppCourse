#include "Matrix.h"
#include <cmath>

Matrix::Matrix()//����������� ��� ����������, ������� ������� 5 �� 5 �� ���������
{
	rows = 5, kol = 5;
	arr = new double*[rows];
	for (int i = 0; i < rows; ++i)
	{
		*(arr + i) = new double[kol];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			arr[i][j] = j;
		}
	}
}

Matrix::Matrix(double ** _arr, int _rows, int _colums)
{
	arr = _arr;
	rows = _rows;
	kol = _colums;
}

Matrix::Matrix(int _rows, int _kol) :rows(_rows), kol(_kol)//����������� � �����������, ������� ������� �������� rows �� kol
{
	arr = new double*[rows];
	for (int i = 0; i < rows; ++i)
	{
		*(arr + i) = new double[kol];
	}
	for (int i = rows - 1; i >= 0; i--)
	{
		for (int j = 0; j < kol; j++)
		{
			arr[i][j] = std::sin(i - j) + std::cos(i + j);
		}
	}
}

void Matrix::Print()//����� ������� � �������
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			std::cout.width(10);
			std::cout << arr[i][j];
			
		}
		std::cout << std::endl;
	}
}

double Matrix::at(int i, int j) const// �������� ������� �������
{
	if (i < rows && i >= 0 && j < rows && j >= 0)
	{
		return arr[i][j];
	}
	else
	{
		return NULL;
	}
}

void Matrix::setAt(int i, int j, double num)// ���������� ������� �������
{
	if (i < rows && i >= 0 && j < rows && j >= 0)
	{
		arr[i][j] = num;
	}
	else
	{
		std::cout << "index error";
	}
}

void Matrix::operator++()//���������� ��������� ++, ����� ��������
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			arr[i][j]++;
		}
	}
}

void Matrix::operator++(int)//���������� ��������� ++, ����� �������
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			++arr[i][j];
		}
	}
}

void Matrix::operator--()//���������� ��������� --, ����� ��������
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			arr[i][j]--;
		}
	}
}

void Matrix::operator--(int)//���������� ��������� --, ����� �������
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			--arr[i][j];
		}
	}
}

std::ostream& operator<< (std::ostream &out, const Matrix &mat)
{
	for (int i = 0; i < mat.getRows(); i++)
	{
		for (int j = 0; j < mat.getKol(); j++)
		{
			std::cout.width(10);
			out << mat.arr[i][j];
		}
		out << std::endl;
	}

	return out;
}

double * Matrix::convertToVector()
{
	int k = 0;
	double *vec = new double[this->kol * this->rows];
	for (size_t i = this->rows - 1; i >= 1; i--)
	{
		for (size_t j = 0; j < this->kol; j++)
		{
			vec[k] = this->arr[i][j];
			k++;
		}
	}
	return vec;
}

int Matrix::getRows() const//������� ��������� ���� ������� �������
{
	return rows;
}

double ** Matrix::getArray() const//���������� ������� 
{
	return arr;
}

int Matrix::getKol() const//������� ��������� ���� �������� �������
{
	return kol;
}

Matrix::~Matrix()// ����������, ������� ������
{
	for (int i = 0; i < rows; i++)
	{
		delete[] * (arr + i);
	}
	delete[] arr;
}