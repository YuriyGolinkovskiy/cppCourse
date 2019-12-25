#pragma once

#include "ExpressionEvaluator.h"
#include "IShuffle.h"

class CustomExpressionEvaluator : public ExpressionEvaluator, public IShuffle
{
public:
	CustomExpressionEvaluator();
	~CustomExpressionEvaluator();

	double calculate();
	void logToScreen();
	void logToFile(const std::string& filename);

	void shuffle();
	void shuffle(size_t i, size_t j);
};
