#include "Summator.h"

#include <iostream>
#include <fstream>
#include <ctime>
#include <random>


Summator::Summator()
{
}

Summator::~Summator()
{
}

double Summator::calculate()//функция сумирования
{
	double* tmp_pArray = getpArray();//создаем временный массив и заполняем его операндами, которые будем складывать
	int tmp_operandlenght = getoperandsLenght();//создаем временную переменную и присваиваем ей количество операндов, которые будем складывать
	double answer = *tmp_pArray;//переменная ответа,сразу присваиваем ей первый элемент массива
	for (int i = 1; i < tmp_operandlenght; i++)
	{
		answer += *(tmp_pArray + i);//добавляем к ответу все операнды из массива
	}

	return answer;//возвращаем ответ
}

void Summator::logToScreen()//функция вывода на консоль
{
	//создание временных переменных
	int tmp_operandlenght = getoperandsLenght();
	double* tmp_pArray = getpArray();

	std::cout << tmp_operandlenght << " operands :" << std::endl;//первая строка(выводим количество операндов)

	for (int i = 0; i < tmp_operandlenght; i++)
	{
		if (tmp_pArray[i] < 0)//если элемент массива отрицательный,тогда дополнительно берем его в скобочки
		{
			std::cout << "(";
			if ((i + 1) == tmp_operandlenght)//если это последний элемент строки и дальше элементов нет,то выводим элемент без "+"
			{
				std::cout << *(tmp_pArray + i) << ")";
			}
			else//елси еще есть операнды,то выводим операнд и ставим "+"
			{
				std::cout << *(tmp_pArray + i) << ") + ";
			}
		}
		else//тоже самое, что и выше,только если число положительное, и в таком случае выводим без скобочек
		{
			if ((i + 1) == tmp_operandlenght)
			{
				std::cout << *(tmp_pArray + i);
			}
			else
			{
				std::cout << *(tmp_pArray + i) << " + ";
			}
		}
	}
}

void Summator::logToFile(const std::string& filename)//метод записи в файл(записываем то же,что и выводим на консоль).Работает почти аналогично выводу в консоль
{
	std::fstream fout(filename, std::ios::app);//открываем поток записи в файл,в который передаем название создаваемого файла.
	//дальше делаем то же,что и в выводе на консоль 
	int tmp_operandlenght = getoperandsLenght();
	double* tmp_pArray = getpArray();

	fout << tmp_operandlenght << " operands :" << std::endl;

	for (int i = 0; i < tmp_operandlenght; i++)
	{
		if (tmp_pArray[i] < 0)
		{
			fout << "(";
			if ((i + 1) == tmp_operandlenght)
			{
				fout << *(tmp_pArray + i) << ")";
			}
			else
			{
				fout << *(tmp_pArray + i) << ") + ";
			}
		}
		else
		{
			if ((i + 1) == tmp_operandlenght)
			{
				fout << *(tmp_pArray + i);
			}
			else
			{
				fout << *(tmp_pArray + i) << " + ";
			}
		}
	}
	fout << std::endl;
	fout.close();//закрываем поток записи
}

void Summator::shuffle()//сортировка по убыванию
{
	int olen = getoperandsLenght();
	double* pArray = getpArray();
	for (int k = 0; k < olen - 1; k++)//первый цикл
	{
		for (int j = k + 1; j < olen; j++)//внутренний цикл, который движется по всем элементам от первого цикла
		{
			if (*(pArray + k) < *(pArray + j))//если во внутреннем цикле значение больше чем в первом
				std::swap(*(pArray + k), *(pArray + j));//то мы меняем эти жлементы местами
		}
	}
}

void Summator::shuffle(size_t i, size_t j)//такая же сортировка,только не всего массива,а диапазона от i-го до j-го элемента
{
	int olen = getoperandsLenght();
	double* pArray = getpArray();
	for (int k = i; k < j; k++)
	{
		for (int p = k + 1; p < olen; p++)
		{
			if (*(pArray + k) < *(pArray + p))
				std::swap(*(pArray + k), *(pArray + p));
		}
	}
}