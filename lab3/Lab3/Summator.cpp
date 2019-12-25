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

double Summator::calculate()//������� �����������
{
	double* tmp_pArray = getpArray();//������� ��������� ������ � ��������� ��� ����������, ������� ����� ����������
	int tmp_operandlenght = getoperandsLenght();//������� ��������� ���������� � ����������� �� ���������� ���������, ������� ����� ����������
	double answer = *tmp_pArray;//���������� ������,����� ����������� �� ������ ������� �������
	for (int i = 1; i < tmp_operandlenght; i++)
	{
		answer += *(tmp_pArray + i);//��������� � ������ ��� �������� �� �������
	}

	return answer;//���������� �����
}

void Summator::logToScreen()//������� ������ �� �������
{
	//�������� ��������� ����������
	int tmp_operandlenght = getoperandsLenght();
	double* tmp_pArray = getpArray();

	std::cout << tmp_operandlenght << " operands :" << std::endl;//������ ������(������� ���������� ���������)

	for (int i = 0; i < tmp_operandlenght; i++)
	{
		if (tmp_pArray[i] < 0)//���� ������� ������� �������������,����� ������������� ����� ��� � ��������
		{
			std::cout << "(";
			if ((i + 1) == tmp_operandlenght)//���� ��� ��������� ������� ������ � ������ ��������� ���,�� ������� ������� ��� "+"
			{
				std::cout << *(tmp_pArray + i) << ")";
			}
			else//���� ��� ���� ��������,�� ������� ������� � ������ "+"
			{
				std::cout << *(tmp_pArray + i) << ") + ";
			}
		}
		else//���� �����, ��� � ����,������ ���� ����� �������������, � � ����� ������ ������� ��� ��������
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

void Summator::logToFile(const std::string& filename)//����� ������ � ����(���������� �� ��,��� � ������� �� �������).�������� ����� ���������� ������ � �������
{
	std::fstream fout(filename, std::ios::app);//��������� ����� ������ � ����,� ������� �������� �������� ������������ �����.
	//������ ������ �� ��,��� � � ������ �� ������� 
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
	fout.close();//��������� ����� ������
}

void Summator::shuffle()//���������� �� ��������
{
	int olen = getoperandsLenght();
	double* pArray = getpArray();
	for (int k = 0; k < olen - 1; k++)//������ ����
	{
		for (int j = k + 1; j < olen; j++)//���������� ����, ������� �������� �� ���� ��������� �� ������� �����
		{
			if (*(pArray + k) < *(pArray + j))//���� �� ���������� ����� �������� ������ ��� � ������
				std::swap(*(pArray + k), *(pArray + j));//�� �� ������ ��� �������� �������
		}
	}
}

void Summator::shuffle(size_t i, size_t j)//����� �� ����������,������ �� ����� �������,� ��������� �� i-�� �� j-�� ��������
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