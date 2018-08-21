#include <iostream>
#include <cstdlib>
#include <string>

#include "stack.hpp"

using std::cin;
using std::cout;
using std::string;
using std::endl;

void Stack::make()								//palindrome creator
{
	stack.push('a');
	stack.push('b');
	stack.push('c');
	stack.push('d');
	stack.push('e');
	stack.push('f');
	stack.push('e');
	stack.push('d');
	stack.push('c');
	stack.push('b');
	stack.push('a');
}

void Stack::test()
{
	string temp;

	while (!stack.empty())
	{
		temp += stack.top();
		stack.pop();
	}

	if (temp == string(temp.rbegin(), temp.rend()))
	{
		cout << " " << temp << " is a palindrome." << endl;
	}
	else
	{
		cout << temp << " is not a palindrome." << endl;
	}
}