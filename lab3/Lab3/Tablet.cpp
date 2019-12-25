#include "Tablet.h"

Tablet::Tablet() :MobileDevice()
{

}

Tablet::Tablet(string _firm, double _weight, string _color, double _price, int _charge) : MobileDevice(_firm, _weight, _color, _price, _charge)
{

}

void Tablet::call(const std::string& recepient)//определение функции из интерфейса ICallable, звонок
{
	cout << "We called on Skype on a number : " << recepient << endl;//сообщение о звонке
	setCharge(getCharge() - 10);//разряжаем планшет на 10 процентов
	cout << "10% charge used. Left: " << getCharge() << endl;//сообщение о том,что телефон разрядился и обновленный заряд батареи планшета
}
