#include <iostream>
#include <random>
#include <cstdio>

using namespace std;

void printArray(int arr[], int buff[], size_t n)//вывод на экран массивов
{
	printf_s("[");
	for (size_t i = 0; i < n; ++i)// входной массив
	{
		printf_s("%d ",arr[i]);
	}
	printf("]\n");
	printf_s("[");
	for (size_t i = 0; i < n; i++)// выходной массив
	{
		if (buff[i] != 0)
			printf_s("%d ", buff[i]);
	}
	printf_s("]\n");
}

int processArray(int arr[],int counts[], int buff[], size_t n)
{
	int elem = 0;
	int count = 0;
	for (size_t i = 0; i < n; ++i)// генерация чисел от 1 до 10
	{
		arr[i] = rand() % 10 + 1;
	}
	for (size_t i = 0; i < n; i++)// заполняем массив с количеством повторений каждой цифры
	{
		elem = arr[i];
		for (size_t j = 0; j < n; j++)	
		{
			if (arr[j] == elem)
				count++;
		}
		counts[i] = count;
		count = 0;
	}
	int popularElem = arr[0];
	int popularElemCount = counts[0];
	for (size_t i = 0; i < n; i++)// находим минимальный элемент, который повторяется больше всего
	{
		if(counts[i] > popularElemCount)
		{
			popularElemCount = counts[i];
			popularElem = arr[i];
		}
		else if (counts[i] == popularElemCount && arr[i] < popularElem)
		{
			popularElemCount = counts[i];
			popularElem = arr[i];
		}
	}
	bool status = false;
	for (size_t i = 0; i < n; i++)// генерация массива с числами, которые встречаются минимум дважды.
	{
		for (size_t j = 0; j < n; j++)
		{
			if (arr[i] == buff[j])
				status = true;
		}
		if (counts[i] >= 2 && status == false)
		{
			buff[i] = arr[i];
		}
		status = false;
	}
	return popularElem;
}
int main()
{
	const size_t N = 20;
	int a[N] = { 0 };
	int counts[N] = { 0 };
	int buff[N] = { 0 };
	srand(0);
	int result = processArray(a, counts, buff, N);
	printArray(a, buff, N);
	printf_s("MostPopularElement = %d\n", result);
	system("pause");
	return 0;
}