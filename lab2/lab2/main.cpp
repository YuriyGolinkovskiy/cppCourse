#include <iostream>
#include "Vector.h"
#include "Matrix.h"

using namespace std;

int main()
{
	cout << "vector" << endl;
	Vector vec(25);
	Matrix c(5, 3);
	cout << c << endl;
	const int rows = 5;
	Matrix mat1(vec.convertToMatrix(rows), vec.getN() / rows + vec.getN() % rows, rows);
	cout << mat1 << endl;
	cout << vec << endl;
	vec.Print();
	cout << "\nvectorToMatrix" << endl;
	Matrix *mat = vec.VectorToMatrix(5);
	Vector vec1(mat->convertToVector(), (mat->getKol()) * (mat->getRows()));
	cout << *mat << endl;
	(*mat).Print();
	cout << "\nvector++" << endl;
	vec++;
	vec.Print();
	cout << "\nvector--" << endl;
	vec--;
	vec.Print();
	cout << "\nmatrix--" << endl;
	(*mat)--;
	(*mat).Print();
	cout << "\n++matrix" << endl;
	++(*mat);
	(*mat).Print();
	system("pause");
	return 0;
}