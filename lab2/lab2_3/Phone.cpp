#include "Phone.h"
#include <iostream>

Phone::Phone()//����������� �� ��������� ��� ����������
{
	model = "standart";
	myNumber = 380991111111;
	lastNumber = 38099222222;
	balance = 0.0;
}

Phone::Phone(string _model, string _myNumber, string _lastNumber, double _balance)// ����������� � �����������
{
	model = _model;
	myNumber = _myNumber;
	lastNumber = _lastNumber;
	balance = _balance;
}

Phone::~Phone()
{
}

void Phone::serialize()//������������ ������ ������� � ���� phone.txt
{
	ofstream fout("Phone.txt", ios_base::trunc);
	fout << model << endl << myNumber << endl << lastNumber << endl << balance << endl; 
	fout.close(); 
}

void Phone::deserialize()//�������������� ������ �� ����� phone.txt
{
	ifstream fin("Phone.txt", ios_base::in);
	fin >> model >> myNumber >> lastNumber >> balance;
	fin.close();
}

void Phone::serialize(const string & filename) // ������������ ������ ������� � ���� ���������� � �������� filename
{
	ofstream fout(filename + ".txt", ios_base::trunc);
	fout << model << endl << myNumber << endl << lastNumber << endl << balance << endl;
	fout.close();
}

void Phone::deserialize(const string & filename)// �������������� ������ �� ����� ����������� � �������� filename
{
	ifstream fin(filename + ".txt", ios_base::in);
	fin >> model >> myNumber >> lastNumber >> balance;
	fin.close();
}

void Phone::info() const//����� ������ �� ������� ��������
{
	cout << "model: " <<model << endl;
	cout << "myNumber: " << myNumber << endl;
	cout << "lastNumber: " << lastNumber << endl;
	cout << "balance: " << balance <<endl;
}

std::ostream& operator<< (std::ostream &out, const Phone &phone)
{
	std::cout.width(3);
	out << "model: " << phone.model << endl <<"myNumber: " << phone.myNumber << endl <<  "lastNumber: " << phone.lastNumber << endl << "balance: "
		<< phone.balance << endl;
	return out;
}

void Phone::call(string number, double minutes)//������� ������, ������ �� ����� � ��������� ������ � �������
{
	lastNumber = number;
	balance -= minutes*0.5;
	cout << myNumber << "  call to  " << number << "  time(minutes): " << minutes << "  cost(rub): " << minutes*0.5 << endl;
}

//������� � �������
string Phone::getModel() const
{
	return model;
}

void Phone::setMyNumber(string _myNumber)
{
	myNumber = _myNumber;
}

string Phone::getLastNumber() const
{
	return lastNumber;
}

void Phone::setLastNumber(string _lastNumber)
{
	lastNumber = _lastNumber;
}

double Phone::getBalance() const
{
	return balance;
}

void Phone::setBalance(double _balance)
{
	balance = _balance;
}

void Phone::setModel(string _model)
{
	model = _model;
}

string Phone::getMyNumber() const
{
	return myNumber;
}
