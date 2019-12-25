#include "Tablet.h"

Tablet::Tablet() :MobileDevice()
{

}

Tablet::Tablet(string _firm, double _weight, string _color, double _price, int _charge) : MobileDevice(_firm, _weight, _color, _price, _charge)
{

}

void Tablet::call(const std::string& recepient)//����������� ������� �� ���������� ICallable, ������
{
	cout << "We called on Skype on a number : " << recepient << endl;//��������� � ������
	setCharge(getCharge() - 10);//��������� ������� �� 10 ���������
	cout << "10% charge used. Left: " << getCharge() << endl;//��������� � ���,��� ������� ���������� � ����������� ����� ������� ��������
}
