#include "queue.hpp"

#include <iostream>

#include <ctime>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

Queue::Queue()
{
	number = 0;
	avg = 0;
	count = 0;
}

int Queue::random()													//random number generator
{
	int number;

	srand(time(NULL));

	number = rand() % 100 + 1;

	cout << "Random number is: " << number << endl;
	return number;
}

void Queue::add(int p)										//add to queue
{
	int test = 0;
	test = random();
	cout << test << endl;

	if (test <= p)
	{
		queue.push(number);
		cout << "Random number was added to the queue." << endl;
	}
	else
	{
		cout << "Random number was not added to queue." << endl;
	}
	count++;

	avg += queue.size();
	display();
}

void Queue::remove(int p)										//remove from queue
{
	if (!queue.empty()) 
	{
		int removeTest = 0;

		removeTest = random();

		if (removeTest <= p)
		{
			cout << "Number removed was " << queue.front() << endl;
			queue.pop();

		}
		else
		{
			cout << "Sorry the number wasn't removed from the queue" << endl;
		}
	}
	else
	{
		cout << "The queue is empty " << endl;
	}
	
	count++;
	avg += queue.size();

	display();
}

void Queue::display()											//display queue
{
	cout << "The average queue length is: " << avg / (double)count;
}