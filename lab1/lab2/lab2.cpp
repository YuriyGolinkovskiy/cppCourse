#include <iostream>
#include <iomanip>

using namespace std;

void initializeArray(double** arr, int n, int m) // заполняем двумерный массив
{
	for (int i = 0; i < n; i++) // создаем и определяем столбцы двумерного массива
	{
		*(arr+i) = new double[m];
	}
	for (size_t i = 0; i < n; i++)// заполняем двумерный массив элементами( по заданию)
	{
		for (size_t j = 0; j < m; j++)
		{
			*(*(arr + i) + j) = sin(i-j) + cos(i+j);
		}
	}
}

double* makeArray1D(double** arr2D, int rows, int cols)
{
	int k = 0;// индекс одномерного массива
	double *arr1D = new double[rows*cols];// определяем одномерный массив такой же длинны как и двумерный
	for (int i = rows-1; i >= 0; i--)// заполняем его элементами, начиная перебор с левого нижнего - вправо
	{
		for (int j = 0; j < cols; j++)
		{
			*(arr1D+k) = *(*(arr2D + i) + j);
			k++;
		}
	}
	return arr1D;
}

void printArray1D(double* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "  ";
	}
	cout << endl;
}

void printArray2D(double** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(14) << *(*(arr + i) + j);
		}
		cout << endl;
	}
}

void freeArray1D(double* arr)
{
	delete[] arr;
}

void freeArray2D(double** arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] * (arr + i);
	}
	delete[] arr;
}
int main()
{
	const int N = 5;
	const int M = 3;
	double** arr2D = new double*[N];
	initializeArray(arr2D, N , M);
	double* arr1D = makeArray1D(arr2D, N, M);
	printArray2D(arr2D, N, M);
	printArray1D(arr1D, N*M);
	freeArray1D(arr1D);
	freeArray2D(arr2D, N);
	system("pause");
	return 0;
}

