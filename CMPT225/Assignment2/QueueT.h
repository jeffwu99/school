#pragma once
#include "DequeT.h"

template <class T>
class QueueT {
public:
	QueueT<T>();

	void enqueue(T dat);
	T dequeue();

	bool empty() const;
	int size() const;

	//void print();


private:
	DequeT<T> dq;
};

template <class T>
QueueT<T>::QueueT() 
{
	DequeT<T> dq;
}
//POST: dat is added to back of the queue
//PARAM: dat is template type T 
template <class T>
void QueueT<T>::enqueue(T dat)
{
	dq.insertBack(dat);
}
//PRE: queue has atleast one item in it
//POST: first item in list is removed and returned and currentSize decrements
template <class T>
T QueueT<T>::dequeue()
{
	return dq.removeFront();
}
//POST: returns true (1) if queue has no elements, otherwise false (0)
template <class T>
bool QueueT<T>::empty() const
{
	return dq.empty();
}
//POST: returns how many elements are inside queue
template <class T>
int QueueT<T>::size() const
{
	return dq.size();
}



//template <class T>
//void QueueT<T>::print()
//{
//	dq.printD();
//}