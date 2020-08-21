//Kyeore Heo
#include <iostream>
#include "FastQueue.hpp"
#include <stdexcept>      // std::out_of_range

using namespace std;
int main()
{
	Fast_queue<int> myQueue;
	int a = 10;
	int b = 20;

	for(int i = 0; i < 10; i++)
	{
		myQueue.enqueue(10+i*10);
	}

	cout << "dequeue()" << endl;
	myQueue.dequeue();
	myQueue.info();

	cout << "dequeue()" << endl;
	myQueue.dequeue();
	myQueue.info();

	cout << "enqueue(111)" << endl;
	myQueue.enqueue(111);
	myQueue.info();

	cout << "enqueue(222)" << endl;
	myQueue.enqueue(222);
	myQueue.info();

	myQueue.dequeue();
	cout << "dequeue()" << endl;
	myQueue.dequeue();
	myQueue.info();

	cout << "enqueue(333)" << endl;
	myQueue.enqueue(333);
	myQueue.info();

	return 0;
}