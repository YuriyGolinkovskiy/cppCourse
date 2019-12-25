#include <iostream>
#include "Phone.h"

using namespace std;

int main()
{
	//�������� 3 �������� � ����
	Phone *phone1 = new Phone();
	Phone *phone2 = new Phone("meizu", "380716553123", "38071763312", 131.22);
	Phone *phone3 = new Phone();
	//������������ ���������� �������� ��� ������ ��������
	phone1->setModel("samsung");
	phone1->setMyNumber("380996201021");
	phone1->setLastNumber("380992343123");
	phone1->setBalance(50.34);

	phone1->info();//����� ������
	phone1->serialize();//������������
	cout << "///////////////////////////" << endl;
	
	for (size_t i = 0; i < 10; i++)//�������� 10 ������� �� 3 ������ ������
	{
		if(i<3)  phone1->call("380716231259", 1.0);
		else if (i >= 3 && i < 7)phone1->call("380992312232", 2.5);
		else phone1->call(phone2->getMyNumber(), 2.0);
	}
	
	phone3->deserialize();
	phone1->info();
	cout << *phone1 << endl<<*phone3<<endl;
	cout << "////////////////////////////" << endl;
	phone2->info();
	cout << "////////////////////////////" << endl;
	phone3->info();
	system("pause");
	return 0;
}