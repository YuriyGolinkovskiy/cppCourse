#pragma once

#include "ExpressionEvaluator.h"
#include "IShuffle.h"

class Summator : public ExpressionEvaluator, public IShuffle
{
public:
	Summator();
	~Summator();

	double calculate();
	void logToScreen();
	void logToFile(const std::string& filename);

	void shuffle();
	void shuffle(size_t i, size_t j);
};
