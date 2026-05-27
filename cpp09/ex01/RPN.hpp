#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <sstream> 

#ifndef RPN_HPP
#define RPN_HPP

class RPN
{
	private:
		std::stack<int> _numbers;
		std::string _mathematicalExpression;
		std::string _mathematicalExpressionCopy;
		bool _ExpressionCorrect;
		int _result;
	public:
		RPN();
		RPN(std::string arg);
		~RPN();
		RPN(RPN const &other);
		RPN & operator=(RPN const &other);
		void calculate();
		void addNumber(int number);
		void setMathematicalExpression(std::string newExpression);
		int sizeList();
		int getResult();
		std::string getMathematicalExpressionCopy();
		std::string getMathematicalExpression();
};

#endif