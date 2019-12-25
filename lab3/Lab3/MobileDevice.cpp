#include "MobileDevice.h"

MobileDevice::MobileDevice()//конструктор по умолчанию
{
	firm = "standart";
	weight = 100;
	color = "black";
	price = 7000;
	charge = 100;
}

MobileDevice::MobileDevice(string _firm, double _weight, string _color, double _price, int _charge)//конструктор с параметрами
{
	firm = _firm;
	weight = _weight;
	color = _color;
	price = _price;
	charge = _charge;
}

MobileDevice::~MobileDevice()
{
}

//геттеры и сеттеры 
string MobileDevice::getFirm() const
{
	return firm;
}

void MobileDevice::setFirm(string _firm)
{
	firm = _firm;
}

double MobileDevice::getWeight() const
{
	return weight;
}

void MobileDevice::setWeight(double _weight)
{
	weight = _weight;
}

string MobileDevice::getColor() const
{
	return color;
}

void MobileDevice::setColor(string _color)
{
	color = _color;
}

double MobileDevice::getPrice() const
{
	return price;
}

void MobileDevice::setPrice(double _price)
{
	price = _price;
}

int MobileDevice::getCharge() const
{
	return charge;
}

void MobileDevice::setCharge(int _charge)
{
	charge = _charge;
}

