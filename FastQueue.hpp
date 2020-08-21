//Kyeore Heo
#ifndef FastQueue_hpp
#define FastQueue_hpp
#include <iostream>
#include <vector>
#include <stdexcept>      // std::out_of_range


template <typename T>
class Fast_queue
{
	public:
		Fast_queue();
		void enqueue(const T& inputT);
		void dequeue();//remove the first
		T& head();//return reference of the first Throws out_of_range if the container is empty
		T& tail();//return the last
		T& at(const int& inputIndex);//Throw_out_of_range if the container size is less than index
		int size(); 
		int capacity();
		void shrink_to_fit();
		void info();//debug perpuse.
		
	private:
		std::vector<T> myVector_;
		std::vector<T> tempVector_;
		void resizeVector();
		typename std::vector<T>::iterator first;
		typename std::vector<T>::iterator last;
		int itemCount;
};

#include "FastQueue.cpp"
#endif