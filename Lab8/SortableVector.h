#pragma once
#include "SimpleVector.h"

template <typename T>
class SortableVector : public SimpleVector<T> {


public:
	SortableVector(int s);// Constructor
	SortableVector(SortableVector&); // Copy constructor
	SortableVector(SimpleVector<T>& Obj);
	void sort();

	virtual ~SortableVector() {}
};

template <typename T>
SortableVector<T>::SortableVector(int s) : SimpleVector<T>(s) {

}

template <typename T>
SortableVector<T>::SortableVector(SortableVector& sv) : SimpleVector<T>(sv.size()) {
	for (int i = 0; i < this->size(); i++) {
		this->push_back(sv.getElementAt(i));
	}
}

template <typename T>
SortableVector<T>::SortableVector(SimpleVector<T>& obj) : SimpleVector<T>(obj) {
	for (int i = 0; i < this->size(); i++) {
		this->push_back(obj.getElementAt(i));
	}
}

template <typename T>
void SortableVector<T>::sort() {
	int size = this->size();
	T* modifiable = new T[size];
	T* sortedArr = new T[size];
	T tempVal;
	int smallInd;

	//copying aptr to be modified 
	for (int w = 0; w < size; w++) {
		modifiable[w] = this->getElementAt(w);
	}
	//selection sorting
	for (int i = 0; i < size; i++) {
		smallInd = i;
		tempVal = modifiable[i];
		for (int j = i; j < size; j++) {
			if (tempVal > modifiable[j]) {
				tempVal = modifiable[j];
				smallInd = j;
			}
		}
		swap(modifiable[i], modifiable[smallInd]);
		sortedArr[i] = modifiable[i];
	}
	//modifying aptr using pops and pushes
	for (int i = 0; i < size; i++) {
		this->pop_back();
	}
	for (int i = 0; i < size; i++) {
		this->push_back(sortedArr[i]);
	}

	delete[] modifiable;
	modifiable = nullptr;
	delete[] sortedArr;
	sortedArr = nullptr;

}