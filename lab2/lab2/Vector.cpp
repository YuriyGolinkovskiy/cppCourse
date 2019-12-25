#include "Vector.h"
#include "Matrix.h"

using namespace std;
Vector::Vector()//����������� �� ���������, �������������� ������ �� 10 ���������
{
	arr = new double[10];
	n = 10;
}

Vector::Vector(int _n) :n(_n)//����������� � ����������, ������� ������ �� n ���������
{
	arr = new double[n];
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = i;
	}
}

Vector::Vector(double * vec, int len) :n(len)
{
	arr = new double[n];
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = i;
	}
}

double ** Vector::convertToMatrix(int colums)
{
	int rows = n / colums;
	rows += n%colums;
	double** matrix = new double*[rows];
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new double[colums];
	}
	int index = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			matrix[i][j] = arr[index];
			index++;
		}
	}
	return matrix;
}

std::ostream& operator<< (std::ostream &out, const Vector &vec)
{
	for (size_t i = 0; i < vec.n; i++)
	{
		std::cout.width(3);
		out << vec.arr[i];
	}

	return out;
}

void Vector::Print()//����� �������
{
	for (size_t i = 0; i < n; i++)
	{
		std::cout.width(3);
		std::cout << arr[i];
	}
}

int Vector::getN() const//�������� ��������� ������ �������
{
	return n;
}

Vector::~Vector()//����������, ������� ������
{
	std::cout << "yes";
	delete[] arr;
}

double & Vector::operator[](const int index)
{
	return arr[index];
}

void Vector::operator++()
{
	for (size_t i = 0; i < n; i++)
	{
		arr[i]++;
	}
}

void Vector::operator++(int)
{
	for (size_t i = 0; i < n; i++)
	{
		++arr[i];
	}
}

void Vector::operator--()
{
	for (size_t i = 0; i < n; i++)
	{
		arr[i]--;
	}
}

void Vector::operator--(int)
{
	for (size_t i = 0; i < n; i++)
	{
		--arr[i];
	}
}
Matrix* Vector::VectorToMatrix(int colums)//����������� ������ ������� � ��������� ������� � ���������� ������ matrix
{	
	Matrix* matrix = new Matrix(n/colums, colums);

	for (int i = 0; i < n / colums; ++i)
	{
		for (int j = 0; j < colums; ++j)
		{
			matrix->setAt(i, j, *(arr + i * colums + j));
		}
	}
	return matrix;
}
