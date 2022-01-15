
// @ description :Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//                Valid operators are + , -, *, / .Each operand may be an integer or another expression.
//Some examples :
//["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

#pragma once
#include "string"
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class slution
{
public:

	//使用递归的方式实现
	int evalRPN(vector<string> &tokens);

	//使用迭代的方式实现
	int evalRPNByIteration(vector<string> &tokens);

private:
	bool is_operator(const string &op) {
		return op.size() == 1 && string("+-*/").find(op) != string::npos;
	}
};

int slution::evalRPN(vector<string> &tokens)
{
	int x, y;
	auto token = tokens.back();
	tokens.pop_back();

	if (is_operator(token))
	{
		x = evalRPN(tokens);
		y = evalRPN(tokens);

		switch (token[0])
		{
		case '+' :
			x += y;
			break;
		case '-':
			x += y;
			break;
		case '*':
			x *= y;
			break;
		default:
			x /= y;
			break;
		}
	}
	else
	{
		size_t i;
		x = stoi(token,&i);
	}

	return x;
}

int slution::evalRPNByIteration(vector<string> &tokens)
{
	stack<string> s;

	for (auto item : tokens)
	{
		if (!is_operator(item))
		{
			s.emplace(item);
		}
		else
		{
			int y = stoi( s.top());
			s.pop();
			int x = stoi(s.top());
			s.pop();
			
			if (item[0] == '+')     x += y;
			else if(item[0] == '-') x -= y;
			else if(item[0] == '*') x *= y;
			else                    x /= y;

			s.push(to_string(x));
		}
	}

	return stoi(s.top());
}