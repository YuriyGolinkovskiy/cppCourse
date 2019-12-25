#pragma once
#include<string>
class ICallable
{
public:
	virtual void call(const std::string& recepient) = 0;
};