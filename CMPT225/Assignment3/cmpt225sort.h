#pragma once
//helper function declarations
template <typename T>
void quicksortRecursion(T arr[], int low, int high, int& barometer);
template <typename T>
int partition(T arr[], int low, int high, int& barometer);
template <typename T>
void swapVal(T arr[], int a, int b);
template <typename T>
void merge(T arr[], int low, int mid, int high, int& barometer);

//PRE: size is the number of elements in arr
//PARAM: type T arr pointer, type int size of array 
//POST: sorts array from low to high while also returning barometer function count
template <typename T>
int insertionsort(T arr[], int size)
{
	int barometer = 0;
	T temp;
	int pos;
	for (int i = 1; i < size; i++) {
		temp = arr[i];
		pos = i;
		while (pos > 0 && temp < arr[pos - 1]) {
			//barometer is counting inner loop's comparisons
			barometer++; 
			arr[pos] = arr[pos - 1];
			pos--;
		}
		arr[pos] = temp;
		//terminating comparison of inner loop
		barometer++;
	}
	return barometer;
}
//PRE: size is the number of elements in arr
//PARAM: type T arr pointer, type int size of array 
//POST: sorts array from low to high while also returning barometer function count
template <typename T>
int quicksort(T arr[], int size)
{
	int barometer = 0;
	//use helper function to make it recursive
	quicksortRecursion<T>(arr, 0, size - 1, barometer);
	return barometer;
}
//PRE: size is the number of elements in arr
//PARAM: type T arr pointer, type int size of array 
//POST: sorts array from low to high while also returning barometer function count
template <typename T>
int mergesort(T arr[], int size)
{
	int barometer = 0;
	//array size 1 is already sorted
	if (size == 1) {
		return barometer;
	}
	for (int compSize = 1; compSize <= size - 1; compSize *= 2) {

		for (int i = 0; i < size - 1; i += 2 * compSize) {
			
			//barometer operations go here
			if (size - 1 < i + compSize - 1) { //when midpoint is out of array bounds
				merge<T>(arr, i, size - 1, size - 1, barometer);
			}
			else if (size - 1 < i + 2 * compSize - 1) { //when endpoint (end index) is out of array bounds
				merge<T>(arr, i, i + compSize - 1, size - 1, barometer);
			}
			else { //merge a multiple of 2 
				merge<T>(arr, i, i + compSize - 1, i + 2 * compSize - 1, barometer);
			}
		}
	}
	return barometer;
}
//citations: https://www.geeksforgeeks.org/shellsort/,
//           https://www.tutorialspoint.com/data_structures_algorithms/shell_sort_algorithm.htm and
//           https://www.youtube.com/watch?v=ddeLSDsYVp8&t=228s
//PRE: size is the number of elements in arr
//PARAM: type T arr pointer, type int size of array 
//POST: sorts array from low to high while also returning barometer function count
template <typename T>
int shellsort(T arr[], int size)
{
	int barometer = 0;
	//h or gap is the number of elements skipped (so h = 1 is skip every other element)
	//h step size specified in assignment 3 instructions
	for (int h = size / 2; h > 1; h /= 2) {
		for (int i = 0; i + h < size; i++) {
			if (arr[i] > arr[i + h]) {
				swapVal<T>(arr, i, i + h);
			}
		}
	}
	//when for loop exits, gap will have reduced to 1
	//barometer is still inside insertion sort
	barometer += insertionsort<T>(arr, size);
	return barometer;
}

//this is the correct implementation of shellsort
//template <class T>
//int shellsort(T arr[], int n) {
//	int count = 0;
//	// Gap starts at n/2 and halves each iteration
//	// Note - not optimal
//	for (int gap = n / 2; gap > 0; gap = gap / 2) {
//		// Insertion sub-arrays whose elements are
//		// 0 ... gap ... n
//		for (int i = gap; i < n; i++) {
//			T temp = arr[i];
//			int pos = i;
//			count++;
//			while (pos >= gap && arr[pos - gap] > temp) {
//				count++;
//				arr[pos] = arr[pos - gap];
//				pos = pos - gap;
//			}
//
//			arr[pos] = temp;
//		}
//	}
//	return count;
//}





//helper function for quicksort
//PRE: low nad high are indices within bounds of arr, and barometer has been initialized
//POST: array from index low to index high will be sorted
//PARAM: low, high are integer indices, barometer is an integer reference. arr is a template array
template <typename T>
void quicksortRecursion(T arr[], int low, int high, int& barometer)
{
	// will not sort if array size is already 1
	if (high - low >= 1) {
		//pivot helper function
		int pivot = partition(arr, low, high, barometer);
		//recursive calls
		quicksortRecursion<T>(arr, low, pivot - 1, barometer);
		quicksortRecursion<T>(arr, pivot + 1, high, barometer);
	}
}
//helper function for quicksort
//PRE: low nad high are indices within bounds of arr, and barometer has been initialized
//POST: returns the index of the pivot, and elements before pivot smaller, and elements after larger
//PARAM: low, high are integer indices, barometer is an integer reference. arr is a template array
template <typename T>
int partition(T arr[], int low, int high, int& barometer)
{
	int pivotIndex = high;
	T pivotVal = arr[high];
	int frontIndex = low;
	int backIndex = high - 1;
	while (frontIndex < backIndex) {
		//barometer is number of loop comparisons
		barometer++;
		if (pivotVal <= arr[frontIndex] && pivotVal > arr[backIndex]) {
			swapVal<T>(arr, frontIndex, backIndex);
			//both indices evaulated, inc/dec both
			frontIndex++;
			backIndex--;
		}
		else if (pivotVal > arr[frontIndex] && pivotVal <= arr[backIndex]) {
			//both indices in right places, no need to swap
			//both indices evaulated, inc/dec both
			frontIndex++;
			backIndex--;
		}
		else if (pivotVal <= arr[frontIndex] && pivotVal <= arr[backIndex]) {
			//frontIndex still needs to be swapped but the backIndex value is in right spot 
			backIndex--;
		}
		else { //when front and back indice values are less than pivot
			//backIndex still needs to be swapped but the frontIndex value is in right spot
			frontIndex++;
		}
	}
	//loop terminating comparison
	barometer++;
	int count = 0;
	for (int i = low; i < high; i++) {
		if (arr[i] < pivotVal) {
			count++;
		}
	}
	swapVal<T>(arr, low + count, pivotIndex);
	pivotIndex = low + count;
	return pivotIndex;
}
//helper function for to swap elements in an array
//PRE: a and b are valid indices of arr
//POST: elements at a and b have swapped
//PARAM: a and b are int, representing array indices, arr is template type T array
template <typename T>
void swapVal(T arr[], int a, int b)
{
	T temp = arr[b];
	arr[b] = arr[a];
	arr[a] = temp;
}
//helper function for mergsort
//PRE: low <= mid <= high
//POST: 2 subarrays from low to mid and mid + 1 to high are combined into a single subarray
//PARAM: arr is template T array, low, mid, and high are integers representing indices of arr
template <typename T>
void merge(T arr[], int low, int mid, int high, int& barometer) 
{
	//do not need to merge size 1 array
	if (low == high) {
		return;
	}
	int startIndexA = low;
	int endIndexA = mid;
	int startIndexB = mid + 1;
	int endIndexB = high;
	T* temp = new T[high - low + 1];
	int tempIter = 0;
	while (startIndexA <= endIndexA && startIndexB <= endIndexB) {
		if (arr[startIndexA] <= arr[startIndexB]) { 
			temp[tempIter] = arr[startIndexA];
			tempIter++;
			startIndexA++;
		}
		else { //arr[B] < arr[A]
			temp[tempIter] = arr[startIndexB];
			tempIter++;
			startIndexB++;
		}
	}
	//either sub_array A or sub_array B will be empty
	while (startIndexA <= endIndexA) {
		temp[tempIter] = arr[startIndexA];
		tempIter++;
		startIndexA++;
	}
	while (startIndexB <= endIndexB) {
		temp[tempIter] = arr[startIndexB];
		tempIter++;
		startIndexB++;
	}
	//copy temp into original array
	for (int i = 0; i < high - low + 1; i++) {
		//barometer loop comparison
		barometer++;
		arr[i + low] = temp[i];
	}
	//loop terminating comparison
	barometer++;
	delete[] temp;
}

