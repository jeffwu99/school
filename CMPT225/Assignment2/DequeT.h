#pragma once
#include <stdexcept>
//#include <iostream>
//using std::cout;
//using std::endl;


template <class T>
class Node {
public:

	//1 arg constructor
	Node(T dat) : data(dat), next(nullptr), prev(nullptr) {}
	//3 arg constructor
	Node(T dat, Node* nextNode, Node* prevNode) : data(dat), next(nextNode), prev(prevNode) {}

	Node<T>* next;
	Node<T>* prev;
	T data;
};

template <class T>
class DequeT {
public:
	//default constructor
	DequeT();
	//copy constructor
	DequeT(const DequeT& dq);
	//destructor
	~DequeT();

	//overloaded assignment operator
	DequeT& operator=(const DequeT& dq);

	void insertFront(T dat);
	void insertBack(T dat);

	T removeFront(); 
	T removeBack(); 

	T peekFront() const; 
	T peekBack() const; 

	bool empty() const;

	int size() const;

	//void printD();


private:
	Node<T>* head;
	Node<T>* tail;
	int currentSize;

	void copyDeque(const DequeT& dq);
	void deleteDeque();

};

template <class T>
DequeT<T>::DequeT() : head(nullptr), tail(nullptr), currentSize(0) {}

//PRE: DequeT object dq
//POST: constructed object is same data type as dq
//PARAM: dq is type DequeT<T> where T could be any type
template <class T> // ******************************************************may need to add <T> to const ref
DequeT<T>::DequeT(const DequeT& dq) : head(nullptr), tail(nullptr), currentSize(dq.currentSize)
{
	//!!! if dq is empty, has 1 element, 2, 3, or >3
	this->copyDeque(dq);
}

//POST: all memory returned and calling object is detroyed
template <class T>
DequeT<T>::~DequeT()
{
	this->deleteDeque();
}
//PRE: DequeT object dq
//POST: calling object deep copies (set of new nodes) dq
//PARAM: dq is type DequeT<T> where T could be any type
template <class T>
DequeT<T>& DequeT<T>::operator=(const DequeT& dq)
{
	// self assignment
	if (this == &dq) {
		cout << "self Assign" << endl; //COMPILATION ERROR
		return *this;
	}

	//first delete calling object deque 
	this->deleteDeque();

	currentSize = dq.currentSize;
	copyDeque(dq);
	return *this;
}
//PRE: dat is data type T which matches calling object's data type
//POST: dat is inserted at the front of the linked list and is the new head
//PARAM: dat is template type T
template <class T>
void DequeT<T>::insertFront(T dat)
{
	if (currentSize == 0) {
		head = new Node<T>(dat);
		tail = head;
	}
	else {
		Node<T>* newNode = new Node<T>(dat);
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	currentSize++;
}
//PRE: dat is data type T which matches calling object's data type
//POST: dat is inserted at the back of the linked list and is the new tail
//PARAM: dat is template type T
template <class T>
void DequeT<T>::insertBack(T dat)
{
	if (currentSize == 0) {
		head = new Node<T>(dat);
		tail = head;
	}
	else {
		Node<T>* newNode = new Node<T>(dat);
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	currentSize++;
}
//PRE: deque has atleast 1 element
//POST: removes first element from deque and returns its data
template <class T>
T DequeT<T>::removeFront()
{
	if (currentSize == 0) {
		throw std::runtime_error("Datastructure empty already");
	}
	else if (currentSize == 1) {
		T removed = head->data;
		delete head;
		head = nullptr;
		tail = nullptr;
		currentSize = 0;
		return removed;
	}
	else {
		T removed = head->data;
		Node<T>* deleteNode = head;
		head = head->next;
		delete deleteNode;
		head->prev = nullptr;
		currentSize--;
		return removed;
	}
}
//PRE: deque has atleast 1 element
//POST: removes last element from deque and returns its data
template <class T>
T DequeT<T>::removeBack()
{
	if (currentSize == 0) {
		throw std::runtime_error("Datastructure empty already");
	}
	else if (currentSize == 1) {
		T removed = head->data;
		delete head;
		head = nullptr;
		tail = nullptr;
		currentSize = 0;
		return removed;
	}
	else {
		T removed = tail->data;
		Node<T>* deleteNode = tail;
		tail = tail->prev;
		delete deleteNode;
		tail->next = nullptr;
		currentSize--;
		return removed;
	}
}
//PRE: deque has atleat 1 element
//POST: returns data of first element in deque
template <class T>
T DequeT<T>::peekFront() const
{
	if (currentSize == 0) {
		throw std::runtime_error("Datastructure empty already");
	}
	else {
		return head->data;
	}
}
//PRE: deque has atleat 1 element
//POST: returns data of last element in deque
template <class T>
T DequeT<T>::peekBack() const
{
	if (currentSize == 0) {
		throw std::runtime_error("Datastructure empty already");
	}
	else {
		return tail->data;
	}
}
//POST: returns size of deque
template <class T>
int DequeT<T>::size() const {
	return this->currentSize;
}
//POST: returns true (1) if size is 0, otherwise false (0) 
template <class T>
bool DequeT<T>::empty() const {
	if (this->size()) {
		return false;
	}
	else {
		return true;
	}
}
//PRE: dq is same datatype as calling object. assumes currentSize has been copied already
//POST: calling object is same as dq, with its own separate nodes that were deep copied
//PARAM: dq is template class DequeT
template <class T>
void DequeT<T>::copyDeque(const DequeT& dq)
{
	int iter = dq.currentSize;
	if (iter == 0) {
		return;
	}
	else if (iter == 1) {
		head = new Node<T>(dq.head->data);
		tail = head;
	}
	else {
		head = new Node<T>(dq.head->data); //1st node
		Node<T>* original = dq.head->next; // 2nd node in queue
		Node<T>* copy = new Node<T>(original->data);
		head->next = copy;
		copy->prev = head;
		Node<T>* prevNode = copy;
		original = original->next;
		tail = prevNode;
		while (original != nullptr) {
			copy = new Node<T>(original->data);
			prevNode->next = copy;
			copy->prev = prevNode;
			prevNode = copy;
			tail = prevNode;
			original = original->next;
		}

	}
}

//PRE: DequeT of any size
//POST: all nodes that belong to calling object are deleted
//NOTE: will not alter currentSize value
template <class T>
void DequeT<T>::deleteDeque()
{
	tail = nullptr;
	Node<T>* temp = head;
	while (head != nullptr) {
		head = head->next;
		delete temp;
		temp = head;
	}
}

//template <class T>
//void DequeT<T>::printD()
//{
//	Node<T>* iter = head;
//	while (iter != nullptr) {
//
//		cout << iter->data << endl;
//		iter = iter->next;
//	}
//}