#include "Phone.h"
#include <iostream>

Phone::Phone()//конструктор по умолчанию без параметров
{
	model = "standart";
	myNumber = "380991111111";
	lastNumber = "38099222222";
	balance = 0.0;
}



Phone::Phone(string _model, string _myNumber, string _lastNumber, double _balance)// конструктор с параметрами
{
	model = _model;
	myNumber = _myNumber;
	lastNumber = _lastNumber;
	balance = _balance;
}

// конструктор с параметрами,который также определяет переменные базового класса MobileDevice
Phone::Phone(string _model, string _myNumber, string _lastNumber, double _balance, string _firm, double _weight, string _color, double _price, int _charge) :MobileDevice(_firm, _weight, _color, _price, _charge)
{
	model = _model;
	myNumber = _myNumber;
	lastNumber = _lastNumber;
	balance = _balance;
}

Phone::~Phone()
{
}

void Phone::serialize()//сериализация данных объекта в файл phone.txt
{
	ofstream fout("Phone.txt", ios_base::trunc);
	fout << model << endl << myNumber << endl << lastNumber << endl << balance << endl;
	fout.close();
}

void Phone::deserialize()//десериализация данных из файла phone.txt
{
	ifstream fin("Phone.txt", ios_base::in);
	fin >> model >> myNumber >> lastNumber >> balance;
	fin.close();
}

void Phone::serialize(const string& filename) // сериализация данных объекта в файл переданный в параметр filename
{
	ofstream fout(filename + ".txt", ios_base::trunc);
	fout << model << endl << myNumber << endl << lastNumber << endl << balance << endl;
	fout.close();
}

void Phone::deserialize(const string& filename)// десериализация данных из файла переданного в параметр filename
{
	ifstream fin(filename + ".txt", ios_base::in);
	fin >> model >> myNumber >> lastNumber >> balance;
	fin.close();
}

void Phone::info() const//вывод данных по объекту телефона
{
	cout << "model: " << model << endl;
	cout << "myNumber: " << myNumber << endl;
	cout << "lastNumber: " << lastNumber << endl;
	cout << "balance: " << balance << endl;
}

std::ostream& operator<< (std::ostream& out, const Phone& phone)//перегрузка оператора вывода
{
	std::cout.width(3);
	out << "model: " << phone.model << endl << "myNumber: " << phone.myNumber << endl << "lastNumber: " << phone.lastNumber << endl << "balance: "
		<< phone.balance << endl;
	return out;
}

void Phone::callTo(string number, double minutes)//функция звонка, звонит на номер и списывает деньги с баланса
{
	lastNumber = number;
	balance -= minutes * 0.5;
	cout << myNumber << "  call to  " << number << "  time(minutes): " << minutes << "  cost(rub): " << minutes * 0.5 << endl;
}

void Phone::call(const std::string& recepient)//определение функции из интерфейса ICallable, звонок
{
	for (int i = 0; i < recepient.length(); i++)//цикл по кажому символу номера телефона,нужен для проверки корректности номера телефона
	{
		if (recepient[i] < 48 || recepient[i]>57)//проверка по аски коду на то, является ли символ не цифрой.Если это не цифра,то
		{
			cout << "Number not corrected, the call failed " << endl;//выводим сообщение о некорректном номере
			break;//и выходим из цикла
		}
		if (i == recepient.length() - 1)//если проверили всю строку и там были только цифры то
		{
			cout << "Number is corrected" << endl;//выводим сообщение о корректности номера
			lastNumber = recepient;//переприсваиваем последний набранный номер
			balance -= 5;//с баланса списываем деньги
			setCharge(getCharge() - 3);//разряжаем телефон на 3 процента
			cout << myNumber << "  call to  " << recepient << endl;//выводим сообщение о звонке
		}
	}
}

//геттеры и сеттеры
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
