#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <queue>
#include <cstdlib>

using namespace std;
using std::queue;

class Queue 
{
	public:
		Queue();
		int random();

		void add(int);
		void remove(int);
	private:
		std::queue<int> queue;

		int number;
		int avg;
		int count;

		void display();
};
#endif