#include "FastQueue.hpp"

template<typename T>
Fast_queue<T>::Fast_queue()
{
	itemCount=0;
}

template<typename T>
void Fast_queue<T>::info()
{
	for(int i = 0; i < myVector_.size(); i ++)
	{
		std::cout<<"myVector_["<<i<<"]: "<<myVector_[i]<<", "<<&myVector_[i]<<std::endl;
	}
	std::cout<<"itemCount: "<<itemCount<<", vectorSize: "<<myVector_.size()<<std::endl;
	std::cout<<"first: "<<&(*first)<<", last: "<<&(*last)<<std::endl;
}

template<typename T>
void Fast_queue<T>::enqueue(const T& inputT)
{
	if(itemCount==0)//first input
	{
		myVector_.resize(10);
		first = myVector_.begin();
		last = myVector_.begin();
		*first = inputT;
		last++;
		itemCount++;
	}
	else if (itemCount == myVector_.size()) //when we try to add when it is full
	{
		resizeVector();
		*last = inputT;
		last++;
		itemCount++;
	}
	else if(itemCount < myVector_.size() && (last == myVector_.end()))
	{
		last = myVector_.begin();
		*last = inputT;
		last++;
		itemCount++;
	}
	else  //regular add
	{
		*last = inputT;
		last++;
		itemCount++;
	}
}

template<typename T>
void Fast_queue<T>::resizeVector()
{
	tempVector_.resize(myVector_.size());
	typename std::vector<T>::iterator itrFirst;
	typename std::vector<T>::iterator itrBegin;
	itrFirst = first;
	itrBegin = myVector_.begin();
	for(int i = 0; i < tempVector_.size(); i ++)
	{
		if(itrFirst != myVector_.end())
		{
			tempVector_[i] = *itrFirst;
			itrFirst++;
		}
		else if(itrBegin != myVector_.end() &&  itrBegin !=last)
		{
			tempVector_[i] = *itrBegin;
			itrBegin++;
		}
	}
	
	myVector_.resize(myVector_.size()*2);
	for(int i = 0; i < tempVector_.size(); i ++)
	{
		myVector_[i] = tempVector_[i];
	}
	tempVector_.clear();
	first = myVector_.begin();
	last = myVector_.begin()+itemCount;
}

template<typename T>
void Fast_queue<T>::dequeue()
{
	if(itemCount>0)
	{
		*first = 0; //make the origianl first default (0)
		first++; //change the first
		itemCount--;
	}
}

template<typename T>
T& Fast_queue<T>::head()
{
	if(itemCount==0)
	{
		throw std::out_of_range("out_of_range");		
	}
	return *(first);
}

template<typename T>
T& Fast_queue<T>::tail()
{
	if(itemCount==0)
	{
		throw std::out_of_range("out_of_range");		
	}
	return *(--last);
}

template<typename T>
T& Fast_queue<T>::at(const int& inputIndex)
{
	int distance = 0;
	typename std::vector<T>::iterator itr;
	for(itr = myVector_.begin(); itr!= first; itr++)
		distance++;
	
	if(inputIndex >= myVector_.size()-distance)
		distance -= myVector_.size();

	if(itemCount==0 || inputIndex>=itemCount)
		throw std::out_of_range("out_of_range");		

	return myVector_[inputIndex + distance];
}

template<typename T>
int Fast_queue<T>::size()
{
	return itemCount;
}

template<typename T>
int Fast_queue<T>::capacity()
{
	return myVector_.size();
}

template<typename T>
void Fast_queue<T>::shrink_to_fit()
{
	myVector_.resize(itemCount);
}

