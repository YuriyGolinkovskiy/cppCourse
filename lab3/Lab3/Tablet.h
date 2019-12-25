#pragma once
#include "MobileDevice.h"

class Tablet : public MobileDevice
{
public:
	Tablet();
	Tablet(string _firm, double _weight, string _color, double _price, int _charge);
	void call(const std::string& recepient);
};

