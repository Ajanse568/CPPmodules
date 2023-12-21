#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
#include <climits>

void	checkString(std::string& rpn) {
	if (rpn.empty())
		throw std::invalid_argument("Error: empty string");
	size_t onlywhite = rpn.find_first_not_of(" \t");
	size_t valid = rpn.find_first_not_of("0123456789+-*/ \t");
	if (onlywhite == std::string::npos || valid != std::string::npos)
		throw std::invalid_argument("Error: invalid string");
}

bool	isOperand(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

int	calculateRpn(std::string rpn) {
	std::stack<int> 	stack;
	std::istringstream	ss(rpn);
	std::string			token;
	long				result;
	int					a;
	int					b;

	while (ss >> token) {
		if (token.length() > 1)
			throw std::invalid_argument("Error: invalid string");
		if (isdigit(token[0]))
			stack.push(token[0] - '0');
		if (isOperand(token[0])) {
			if (stack.size() < 2)
				throw std::invalid_argument("Error: invalid string");
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();
			switch (token[0])
			{
				case '+':
					result = b + a;
					break;
				case '-':
					result = b - a;
					break;
				case '*':
					result = b * a;
					break;
				case '/':
					if (a == 0)
						throw std::invalid_argument("Error: division by zero");
					result = b / a;
					break;
			}
			if (result > INT_MAX || result < INT_MIN)
				throw std::invalid_argument("Error: result out of range");
			stack.push(static_cast<int>(result));
		}
	}
	if (stack.size() != 1)
		throw std::invalid_argument("Error: invalid string");
	return(static_cast< int>(result));
}

int main(int argc, char **argv) {
	std::string		rpn;
	int	result;
	if (argc != 2) {
		std::cout << "Error: wrong number of arguments" << std::endl;
		return 1;
	}

	rpn = argv[1];

	try
	{
		checkString(rpn);
		result = calculateRpn(rpn);
		std::cout << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}