#pragma once
#include "ILoggable.h"

class ExpressionEvaluator : public ILoggable
{
private:
	int lenght;
	int operandslenght;
	double* pArray;

	void calculateoperandslenght();
public:
	ExpressionEvaluator();
	ExpressionEvaluator(int lenght);
	virtual ~ExpressionEvaluator();

	void setOperand(size_t pos, double value);
	void setOperands(double ops[], size_t lenght);


	int getoperandsLenght();
	int getLenght();
	double* getpArray();

	virtual double calculate() = 0;
};