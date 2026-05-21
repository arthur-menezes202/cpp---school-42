#include "RPN.hpp"

RPN::RPN(): _mathematicalExpression(""), _mathematicalExpressionCopy(""),
_ExpressionCorrect(false), _result(0)
{}

RPN::RPN(std::string arg): _result(0)
{
	setMathematicalExpression(arg);
}

RPN::~RPN() {}

RPN::RPN(RPN const &other) {*this = other; }

RPN & RPN::operator=(RPN const &other)
{
	if (this != &other)
	{
		*this = other;
	}
	return *this;
}

void RPN::addNumber(int number)
{
	_numbers.push(number);
}

int RPN::sizeList()
{
	return _numbers.size();
}

int RPN::getResult()
{
	if(!_ExpressionCorrect)
	{
		throw std::out_of_range("Error: expression incorrect");
	}
	return _result;
}

void RPN::setMathematicalExpression(std::string newExpression)
{
    std::stringstream ss(newExpression);
    std::string token;

    while (ss >> token) {
		if (std::isdigit(token[0])) {
			int intNumber = std::atoi(token.c_str());
			if (intNumber > 10) {
				_ExpressionCorrect = false;
			}
		}
	}
	_mathematicalExpression = newExpression;
	_mathematicalExpressionCopy = newExpression;
	_ExpressionCorrect = true;

}

std::string RPN::getMathematicalExpressionCopy()
{
	return _mathematicalExpressionCopy;
}

std::string RPN::getMathematicalExpression()
{
	return _mathematicalExpression;
}

void RPN::calculate()
{
	if(!_ExpressionCorrect)
		return;
	std::string str = _mathematicalExpressionCopy;
	std::string errorStr;
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
	if(str.size() < 3)
	{
		throw std::out_of_range("Error: have small 3 caracters");
		_ExpressionCorrect = false;
	}
	int valueCalt = 0;
	int penultimate;
	int last;

	for(size_t i = 0; i < str.length(); i ++)
	{
		if(str[i] == '-' || str[i] == '+' || str[i] == '*' || str[i] == '/')
		{
			if(_numbers.size() < 2)
			{
				_ExpressionCorrect = false;
				errorStr = std::string("Error: Mathematical Expression invalit token: ") + str[i];
				throw  std::out_of_range(errorStr.c_str());

			}
			last = _numbers.top();
			_numbers.pop();
			penultimate = _numbers.top();
			_numbers.pop();
			switch (str[i]) {
				case '-':
					valueCalt = penultimate - last;
					break;
				case '+':
					valueCalt = penultimate + last;
					break;
				case '*':
					valueCalt = penultimate * last;
					break;
				case '/':
					valueCalt = penultimate / last;
					break;
				default:
					std::cout << "Unknown option." << std::endl;
					break;
			}
			_numbers.push(valueCalt);
			_result = valueCalt;
			continue;
		}
		else if (isdigit(str[i])) {
			int intNumber = str[i] - '0';
			_numbers.push(intNumber);
		} else {
			errorStr = std::string("Error: bad input => ") + str[i];
			_ExpressionCorrect = false;
			throw  std::out_of_range(errorStr.c_str());
		}
	}
	if(_numbers.size() != 1)
	{
		throw  std::out_of_range("error size expression");
		_ExpressionCorrect = false;
	}
	_result = _numbers.top();
}