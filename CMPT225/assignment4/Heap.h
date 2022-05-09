#pragma once
#include <stdexcept>
#include <vector>

template <class T>
class Heap {
public:
	Heap(int size);
	Heap(const Heap& h);
	~Heap();
	Heap& operator=(const Heap& h);
	void insert(T a);
	T remove();
	T peek() const;
	Heap merge(const Heap& h) const;
	int size() const;

private:
	int maxSize;
	int currentSize;
	T* arr;

	void bubbleUp(int ind);
	void bubbleDown(int ind);
	void heapify();
	void swapVal(int a, int b);
};
//PART 2 function
//PRE: m is a positive integer
//POST: returns either size n or m (whichever smallest size) vector of sorted smallest elements
//PARAM: unsorted vector of basic data type
template <class T>
std::vector<T> smallestm(std::vector<T> vec, int m)
{
	if (m == 0 || vec.size() == 0) {
		std::vector<T> emptyVec;
		return emptyVec;
	}
	else {
		//if m is less than size of n
		Heap<T> temp(m);
		int n = vec.size();
		if (n > m) {
			int i = 0;
			//fill heap with first few values
			while (temp.size() < m) {
				temp.insert(vec[i]);
				i++;
			}
			//heap is now full
			while (i < n) {
				//take out root and put in vec[i] if vec[i] is smaller
				if (vec[i] < temp.peek()) {
					temp.remove();
					temp.insert(vec[i]);
				}
				i++;
			}
		}
		//if n is smaller than or equal to m, we just go to heapsort directly
		else {
			for (int i = 0; i < n; i++) {
				temp.insert(vec[i]);
			}
		}
		//now heap contains the min(n,m) smallest elements
		//if n is the smaller, then removal takes nlogn, so the total time would've been nlogn * 2
		//if m is the smaller, then removal takes mlogm, so total time wouldve been nlogm (since nlogm > mlogm)
		std::vector<T> ans(temp.size());
		for (int i = temp.size() - 1; i >= 0; i--) {
			ans[i] = temp.remove();
		}
		return ans;
	}
}

//PART 1 implementations
//PRE: size is greater than 0 
//POST: created a heap object
//PARAM: size is a positive integer
template <class T>
Heap<T>::Heap(int size) : currentSize(0), maxSize(size), arr(nullptr)
{
	arr = new T[size];
}
//PRE: h is a valid heap
//POST: creates an identical but independent copy object of h
//PARAM: h is a heap object that is valid
template <class T>
Heap<T>::Heap(const Heap<T>& h) : currentSize(h.currentSize), maxSize(h.maxSize), arr(nullptr)
{
	arr = new T[h.maxSize];
	for (int i = 0; i < h.currentSize; i++) {
		arr[i] = h.arr[i];
	}
}
//POST: deallocates any dynamic memory used by heap object
template <class T>
Heap<T>::~Heap()
{
	delete[] arr;
}
//PRE: h is valid heap object
//POST: calling object is now an independent copy of h
//PARAM: h is a heap data type
template <class T>
Heap<T>& Heap<T>::operator=(const Heap<T>& h)
{
	if (&h == this) {
		return *this;
	}
	//deallocate old array
	delete[] arr;
	currentSize = h.currentSize;
	maxSize = h.maxSize;
	arr = new T[h.maxSize];
	for (int i = 0; i < h.currentSize; i++) {
		arr[i] = h.arr[i];
	}
	return *this;
}
//PRE: heap is not currently full
//POST: inserts d into heap while maintaining heap properties
//PARAM: d is template type T (matching calling object data type)
template <class T>
void Heap<T>::insert(T d)
{
	currentSize++;
	//heap is already full
	if (currentSize > maxSize) {
		throw std::runtime_error("Heap is already full");
	}
	arr[currentSize - 1] = d;
	//bubbleUp is called with correct currentSize
	bubbleUp(currentSize - 1);
}
//PRE: heap is not empty
//POST: removes and returns root while maintaining heap properties
template <class T>
T Heap<T>::remove()
{
	if (currentSize == 0) {
		throw std::runtime_error("Heap is empty; nothing to remove");
	}
	T temp = arr[0];
	//swap root with rightmost leaf
	swapVal(0, currentSize - 1);
	currentSize--;
	//swap new root until it's in the right place
	//bubbleDown is called with new currentSize
	bubbleDown(0);
	return temp;
}
//PRE: calling and parameter objects have size greater than 0
//POST: returns heap object of combined calling and parameter heap elements 
//      heap properties are maintained in new heap
//PARAM: h is heap object
template <class T>
Heap<T> Heap<T>::merge(const Heap<T>& h) const
{
	int combined = currentSize + h.currentSize;
	Heap<T> r(combined);
	r.currentSize = combined;
	//copy first array into r's array
	for (int i = 0; i < currentSize; i++) {
		r.arr[i] = arr[i];
	}
	//copy second array into the remainder of r's array
	for (int j = 0; j < h.currentSize; j++) {
		r.arr[j + currentSize] = (h.arr[j]);
	}
	//heapifying is an O(n) operation
	r.heapify();
	return r;
}
//PRE: calling object is not empty
//POST: returns root without changing calling object
template <class T>
T Heap<T>::peek() const
{
	if (currentSize == 0) {
		throw std::runtime_error("Heap is empty; nothing to return");
	}
	else {
		return arr[0];
	}
}
//POST: returns current size of calling object
template <class T>
int Heap<T>::size() const 
{
	return currentSize;
}
//PRE: ind is valid index
//POST: rearranges necessary array elements so that element at ind is in correct \
//      position following heap properties
//PARAM: ind is valid index of calling object's array
template <class T>
void Heap<T>::bubbleUp(int ind)
{
	int parent = (ind - 1) / 2;
	//when comparing level 1 with level 0
	if (parent == 0 && ind != 0) {
		if (arr[ind] > arr[parent]) {
			swapVal(ind, parent);
			//no recursion since the final parent (root) was compared
		}
	}
	else if (parent > 0) { //parent > 0 isn't really needed since proper indexing should avoid any other cases
		if (arr[ind] > arr[parent]) {
			//parent is smaller than child
			swapVal(ind, parent);
			//after swap, check if the grandparent is smaller with the new parent
			bubbleUp(parent);
		}
	}
}
//PRE: ind is valid index
//POST: rearranges necessary array elements so that element at ind is in correct 
//      position following heap properties
//PARAM: ind is valid index of calling object's array
template <class T>
void Heap<T>::bubbleDown(int ind)
{
	int lChild = (2 * ind) + 1;
	int rChild = (2 * ind) + 2;
	//if rChild is in array then lChild is also in array
	if (rChild < currentSize) {
		if (arr[lChild] > arr[rChild]) {
			if (arr[ind] < arr[lChild]) {
				swapVal(ind, lChild);
				bubbleDown(lChild);
			}
		}
		else { // arr[rChild] > arr[lChild]
			if (arr[ind] < arr[rChild]) {
				swapVal(ind, rChild);
				bubbleDown(rChild);
			}
		}
	}
	//if lChild isn't then do nothing as ind is fully bubbled down
	else if (lChild < currentSize) { 
		if (arr[ind] < arr[lChild]) {
			swapVal(ind, lChild);
			//no more recursion as lChild would have been rightmost leaf
		}
	}
}
//PRE: currentSize accurately reflects calling object's actual size
//POST: rearranges elements to make valid heap
template <class T>
void Heap<T>::heapify()
{
	for (int i = (currentSize - 2) / 2; i >= 0; i--) {
		bubbleDown(i);
	}
}
//PRE: a and b are valid indices
//POST: swaps element at index a with element at b
//PARAM: a and b are integers
template <class T>
void Heap<T>::swapVal(int a, int b)
{
	int temp = arr[b];
	arr[b] = arr[a];
	arr[a] = temp;
}
