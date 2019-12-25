#include "ExpressionEvaluator.h"

#include "Summator.h"
#include "Multiplier.h"
#include "CustomExpressionEvaluator.h"
#include "ILoggable.h"
#include "IShuffle.h"

#include <iostream>
#include "Phone.h"
#include "MobileDevice.h"
#include "Tablet.h"

//������� 1//
//��� ��������� CustomExpression : result = x1 + 2 * x2 + 3 * x3 + 4 * x4 + ...
//������� �������� � ������������� �������� ���������� :
//CustomExpressionEvaluator: 4 ��������, ��������� ����������� 50, 40, -10, -2. 
//Multiplier : 4 ��������, ��������� ������� - 0.5, -8, 1.5, 16. 
//Summator : 6 ���������, ��������� �������  2.6, -8.1, 13.2, 1.5, 3.4, -4.
//����� shuffle() � ������������� ��� �������� � ������� ��������.
//����� shuffle(size_t i, size_t j) � ������������� ��� �������� ����� i - �� � j - ��.
//������ ������ : 
//4 operands : 
//50 + 2 * 40 + 3 * (-10) + (-2) 
//-> 98

//������� 2//
//����� ������� + ������ ��������� ����������, �������.
//����������� ����� ������������ ������� � ��������� ������������ �� ������� ������ :
//����� - �������������, ������, ����� ��������, ��������� ��������� �����, ������� �� �����, ���, ����, ����, ������� ������.
//��������� ����������� ������  ICallable � ������� void call(const std::string& recepient) � ��������� �� ������ recepient.
//���������� ������ � ������ �������� :
//�������� ������������ ������ ��������(�������� ������ �����), ������ ����� �� ����� � ������������ 3 % ������.
//���������� ������ � ������ �������� : ������������� 10 % ������(������ ���� �� ������).
//� main() ������� 2 �������� � 2 ��������, ������������������ ����������� call().

int main()
{
	ExpressionEvaluator* evaluators[3];//�������������� ������,������� ����� ������� 3 ������� ������ ������

	evaluators[0] = new CustomExpressionEvaluator();//�������� ������� ������ ����������������� ���������
	//������������ ���������� ���������
	evaluators[0]->setOperand(0, 50);
	evaluators[0]->setOperand(1, 40);
	evaluators[0]->setOperand(2, -10);
	evaluators[0]->setOperand(3, -2);

	evaluators[1] = new Multiplier();// �������� ������� ������ ���������
	double multiplier_operands[] = { -0.5, -8, 1.5, 16 }; //������ �������� �����
	evaluators[1]->setOperands(multiplier_operands, 4); // ���������� ������� �������� � ������ ���������

	evaluators[2] = new Summator();
	double summator_operands[] = { 2.6,-8.1, 13.2, 1.5, 3.4, -4 }; //������ �������� �����
	evaluators[2]->setOperands(summator_operands, 6); // ���������� ������� �������� � ������ ��������

	for (int i = 0; i < 3; i++)// ���� �� ������� ��������
	{
		evaluators[i]->logToFile("lab3++.log");//������ � ����
		evaluators[i]->logToScreen();//����� �� �����
		std::cout << "\n-> " << evaluators[i]->calculate() << std::endl << std::endl;//������� � �����
	}

	for (int i = 0; i < 3; i++)
	{
		IShuffle* loga = dynamic_cast<IShuffle*>(evaluators[i]);// ��������� ��������� �� ������ evaluators[i] ��������� IShuffle

		if (loga)//���� ���������
		{
			loga->shuffle();//���������� ��������� �������	
			evaluators[i]->logToScreen();
			std::cout << "\n-> " << evaluators[i]->calculate() << std::endl << std::endl;
		}
	}
	Phone* ph1 = new Phone("redmik-8a", "380996202092", "380993254212", 200, "redmi", 80, "red", 8600, 100);//������� ������ �������� ����� ����������� � �����������,������� ����� ���������� ���� �������� ������ MobileDevice
	Phone* ph2 = new Phone("m6t", "380996202092", "380993254212", 100);//������� ������ ������ ��������, ���� �������� ������ ������������ ������������� �� ���������
	ph1->call("380214124223");//��������� ������ �� ���������� ����� ��������
	ph2->call("385233522fe3");//��������� ������ �� �� ���������� ����� ��������
	ph1->info();//����� ���������� � ������ ��������
	Tablet* tb1 = new Tablet();//������� ������ �������� ������������� �� ���������
	Tablet* tb2 = new Tablet("samsung", 154.34, "gold", 12500.00, 70);//������� ������ �������� ������������� � �����������
	//��������� 2 ������ �� ��������
	tb1->call("3982341232222");
	tb2->call("3982341233333");
	//�������� ����������� ���������� ������
	delete ph1;
	delete tb1;
	delete ph2;
	delete tb2;
	delete evaluators[0];
	delete evaluators[1];
	delete evaluators[2];

	system("pause");
}