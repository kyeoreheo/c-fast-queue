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
		myQueue.info();
	}

	myQueue.dequeue();
	myQueue.dequeue();
	myQueue.enqueue(999);
	myQueue.enqueue(777);
	myQueue.enqueue(1010);

	int aa = 10;
	cout<<"AT: "<<myQueue.at(aa)<<endl;
 	myQueue.info();
 	myQueue.shrink_to_fit();
 	cout<<myQueue.tail()<<endl;
 	myQueue.info();

	return 0;
}