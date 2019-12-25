#include "CustomExpressionEvaluator.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <random>

CustomExpressionEvaluator::CustomExpressionEvaluator()
{
}


CustomExpressionEvaluator::~CustomExpressionEvaluator()
{
}

double CustomExpressionEvaluator::calculate()
{
	double* tmp_pArray = getpArray();
	int tmp_operandlenght = getoperandsLenght();
	double answer = *tmp_pArray;

	for (int i = 1; i < tmp_operandlenght; i++)
	{
		answer += (i + 1) * tmp_pArray[i];
	}

	return answer;
}

void CustomExpressionEvaluator::logToScreen()
{
	int tmp_operandlenght = getoperandsLenght();
	double* tmp_pArray = getpArray();
	if (tmp_operandlenght == 1)
	{
		std::cout << tmp_operandlenght << " operand :" << std::endl;
	}
	else
	{
		std::cout << tmp_operandlenght << " operands :" << std::endl;
	}

	for (int i = 0; i < tmp_operandlenght; i++)
	{
		if (tmp_pArray[i] < 0)
		{
			if (i == 0)
			{
				std::cout << tmp_pArray[i] << "";
			}
			else
			{
				std::cout << i + 1 << "*(" << tmp_pArray[i] << ")";
			}
		}
		else
		{
			if (i == 0)
			{
				std::cout << tmp_pArray[i] << "";
			}
			else
			{
				std::cout << i + 1 << "*" << tmp_pArray[i];
			}
		}
		if (i + 1 != tmp_operandlenght)
		{
			std::cout << " + ";
		}
	}
}

void CustomExpressionEvaluator::logToFile(const std::string& filename)
{
	int tmp_operandlenght = getoperandsLenght();
	double* tmp_pArray = getpArray();
	std::fstream fout(filename, std::ios::app);
	fout << std::endl;
	if (tmp_operandlenght == 1)
	{
		fout << tmp_operandlenght << " operand :" << std::endl;
	}
	else
	{
		fout << tmp_operandlenght << " operands :" << std::endl;
	}

	for (int i = 0; i < tmp_operandlenght; i++)
	{
		if (tmp_pArray[i] < 0)
		{
			if (i == 0)
			{
				fout << tmp_pArray[i] << "";
			}
			else
			{
				fout << i + 1 << "*(" << tmp_pArray[i] << ")";
			}
		}
		else
		{
			if (i == 0)
			{
				fout << tmp_pArray[i] << "";
			}
			else
			{
				fout << i + 1 << "*" << tmp_pArray[i];
			}
		}
		if (i + 1 != tmp_operandlenght)
		{
			fout << " + ";
		}
	}
	fout << std::endl;
	fout.close();
}

void CustomExpressionEvaluator::shuffle()
{
	int olen = getoperandsLenght();
	double* pArray = getpArray();
	for (int k = 0; k < olen - 1; k++)
	{
		for (int j = k + 1; j < olen; j++)
		{
			if (*(pArray + k) < *(pArray + j))
				std::swap(*(pArray + k), *(pArray + j));
		}
	}
}

void CustomExpressionEvaluator::shuffle(size_t i, size_t j)
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