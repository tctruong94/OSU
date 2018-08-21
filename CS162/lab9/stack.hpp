#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <cstdlib>
#include <stack>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::stack;

class Stack 
{
	public:
		void test();
		void make();
	private:
		std::stack<char> stack;
};
#endif