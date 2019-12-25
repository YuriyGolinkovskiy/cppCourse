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

//Задание 1//
//Вид выражения CustomExpression : result = x1 + 2 * x2 + 3 * x3 + 4 * x4 + ...
//Порядок создания и инициализации объектов подклассов :
//CustomExpressionEvaluator: 4 операнда, присвоить поэлементно 50, 40, -10, -2. 
//Multiplier : 4 операнда, присвоить группой - 0.5, -8, 1.5, 16. 
//Summator : 6 операндов, присвоить группой  2.6, -8.1, 13.2, 1.5, 3.4, -4.
//Метод shuffle() – отсортировать все операнды в порядке убывания.
//Метод shuffle(size_t i, size_t j) – отсортировать все операнды между i - ым и j - ым.
//Формат вывода : 
//4 operands : 
//50 + 2 * 40 + 3 * (-10) + (-2) 
//-> 98

//Задание 2//
//Класс ТЕЛЕФОН + классы МОБИЛЬНОЕ УСТРОЙСТВО, ПЛАНШЕТ.
//Реализовать схему наследования классов и корректно распределить по классам данные :
//фирма - производитель, модель, номер телефона, последний набранный номер, остаток на счету, вес, цвет, цена, уровень заряда.
//Интерфейс возможности звонка  ICallable с методом void call(const std::string& recepient) – позвонить по номеру recepient.
//Реализация метода в классе телефона :
//проверка корректности номера телефона(содержит только цифры), снятие суммы со счета и расходование 3 % заряда.
//Реализация метода в классе планшета : израсходовать 10 % заряда(звонок идет по скайпу).
//В main() создать 2 телефона и 2 планшета, продемонстрировать полиморфизм call().

int main()
{
	ExpressionEvaluator* evaluators[3];//инициализируем массив,который будет хранить 3 объекта нашего класса

	evaluators[0] = new CustomExpressionEvaluator();//создание объекта класса пользовательского выражения
	//поэлементное присвоение операндов
	evaluators[0]->setOperand(0, 50);
	evaluators[0]->setOperand(1, 40);
	evaluators[0]->setOperand(2, -10);
	evaluators[0]->setOperand(3, -2);

	evaluators[1] = new Multiplier();// создание объекта класса умножения
	double multiplier_operands[] = { -0.5, -8, 1.5, 16 }; //массив значений чисел
	evaluators[1]->setOperands(multiplier_operands, 4); // присвоение массива значений к обекту умножения

	evaluators[2] = new Summator();
	double summator_operands[] = { 2.6,-8.1, 13.2, 1.5, 3.4, -4 }; //массив значений чисел
	evaluators[2]->setOperands(summator_operands, 6); // присвоение массива значений к обекту сложения

	for (int i = 0; i < 3; i++)// цикл по массиву объектов
	{
		evaluators[i]->logToFile("lab3++.log");//запись в файл
		evaluators[i]->logToScreen();//вывод на экран
		std::cout << "\n-> " << evaluators[i]->calculate() << std::endl << std::endl;//подсчет и вывод
	}

	for (int i = 0; i < 3; i++)
	{
		IShuffle* loga = dynamic_cast<IShuffle*>(evaluators[i]);// проверяет наследует ли объект evaluators[i] интерфейс IShuffle

		if (loga)//если наследует
		{
			loga->shuffle();//сортировка элементов объекта	
			evaluators[i]->logToScreen();
			std::cout << "\n-> " << evaluators[i]->calculate() << std::endl << std::endl;
		}
	}
	Phone* ph1 = new Phone("redmik-8a", "380996202092", "380993254212", 200, "redmi", 80, "red", 8600, 100);//создаем объект телефона через констректор с параметрами,который также определяет поля базового класса MobileDevice
	Phone* ph2 = new Phone("m6t", "380996202092", "380993254212", 100);//создаем второй объект телефона, поля базового класса определяются конструктором по умолчанию
	ph1->call("380214124223");//совершаем звонок на корректный номер телефона
	ph2->call("385233522fe3");//совершаем звонок на не корректный номер телефона
	ph1->info();//вывод информации о первом телефоне
	Tablet* tb1 = new Tablet();//создаем объект планшета конструктором по умолчанию
	Tablet* tb2 = new Tablet("samsung", 154.34, "gold", 12500.00, 70);//создаем объект планшета конструктором с параметрами
	//совершаем 2 звонка на планшеты
	tb1->call("3982341232222");
	tb2->call("3982341233333");
	//очишение денамически выделенной памяти
	delete ph1;
	delete tb1;
	delete ph2;
	delete tb2;
	delete evaluators[0];
	delete evaluators[1];
	delete evaluators[2];

	system("pause");
}