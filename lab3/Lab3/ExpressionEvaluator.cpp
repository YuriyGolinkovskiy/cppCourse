#include "ExpressionEvaluator.h"


ExpressionEvaluator::ExpressionEvaluator()//конструктор
{
	lenght = 20;
	pArray = new double[lenght];//создаем массив из 20 элементов

	for (int i = 0; i < lenght; i++)//заполняем все элементы 0-ми
	{
		*(pArray + i) = 0;
	}
}

ExpressionEvaluator::ExpressionEvaluator(int lenght) : lenght(lenght)//конструктор с параметром, задаем количетво элементов,которые будем инициализировать
{
	pArray = new double[lenght];

	for (int i = 0; i < lenght; i++)
	{
		*(pArray + i) = 0;
	}
}

int ExpressionEvaluator::getoperandsLenght()//просто возвращает количество операндов
{
	return operandslenght;
}

int ExpressionEvaluator::getLenght()//просто возвращает количество выделенных элементов под массив
{
	return lenght;
}

void ExpressionEvaluator::setOperand(size_t pos, double value)//передаем какому элементу и какое значение установить
{
	*(pArray + pos) = value;//устанавливает i-тому элементу массива значение

	calculateoperandslenght();//высчитвает количество операндов в нашем массиве
}

void ExpressionEvaluator::setOperands(double ops[], size_t lenght)//то же, что и предыдущая функция,только в эту мы передаем массив значений и число этих значений в массиве
{
	for (int i = 0; i < lenght; i++)
	{
		*(pArray + i) = ops[i];
	}

	calculateoperandslenght();
}

void ExpressionEvaluator::calculateoperandslenght()//высчитывает сколько операндов у нас в массиве
{
	for (int i = 0; i < lenght; i++)//проходимся по всему массиву 
	{
		if (*(pArray + i) != 0)//если элемент массива не равен 0
		{
			operandslenght = i + 1;//то увеличиваем переменную,отвечающую за количество операндов
		}
	}
}

double* ExpressionEvaluator::getpArray()
{
	return pArray;
}

ExpressionEvaluator::~ExpressionEvaluator()//деструктор, очищает выделенную динамическую память под массив
{
	delete[] pArray;
}