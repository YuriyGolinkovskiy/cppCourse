#pragma once
#include<iostream>
#include <string>
using namespace std;
class MobileDevice
{
public:
	MobileDevice();
	MobileDevice(string _firm, double _weight, string _color, double _price, int _charge);
	~MobileDevice();
	string getFirm() const;
	void setFirm(string _firm);
	double getWeight() const;
	void setWeight(double _weihgt);
	string getColor() const;
	void setColor(string _color);
	double getPrice() const;
	void setPrice(double _price);
	int getCharge() const;
	void setCharge(int _charge);
private:
	string firm;
	double weight;
	string color;
	double price;
	int charge;
};

