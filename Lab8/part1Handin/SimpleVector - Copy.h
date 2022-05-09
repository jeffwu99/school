#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <typename T>
class SimpleVector
{
private:
    T* aptr;          // To point to the allocated array
    int arraySize;    // Number of elements in the array
//    void memError();  // Handles memory allocation errors
//   void subError();  // Handles subscripts out of range

public:
    // Default constructor
    SimpleVector() : aptr(nullptr), arraySize(0)
    {}

    // Constructor declaration
    SimpleVector(int);

    // Copy constructor declaration
    SimpleVector(const SimpleVector&);

    // Destructor declaration
    ~SimpleVector();

    // Accessor to return the array size
    int size() const
    {
        return arraySize;
    }

    // Accessor to return a specific element
    T getElementAt(int position);

    // Overloaded [] operator declaration
    T& operator[](const int&);

    //exception classes
    class MemoryAllocationException {
    private: 
        const char* e;
    public:
        MemoryAllocationException(const char* err) : e(err) {}

        const char* getErrorMessage() {
            return this->e;
        }

        void memError() {
            cout << this->getErrorMessage() << endl;
            exit(EXIT_FAILURE);
        }
    };

    class BoundsException {
    private:
        const char* e;
    public:
        BoundsException(const char* err) :e(err) {}

        const char* getErrorMessage() {
            return this->e;
        }

        void subError() {
            cout << this->getErrorMessage() << endl;
            exit(EXIT_FAILURE);
        }
    };

};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <typename T>
SimpleVector<T>::SimpleVector(int s) : arraySize(s)
{
    // Allocate memory for the array.
    try
    {
        aptr = new T[s];
    }
    catch (bad_alloc)
    {
        MemoryAllocationException err("ERROR:Cannot allocate memory.");
        err.memError();
    }

    // Initialize the array.
    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <typename T>
SimpleVector<T>::SimpleVector(const SimpleVector& obj) : arraySize(obj.arraySize)
{

    // Allocate memory for the array.
    aptr = new T[arraySize];
    if (aptr == 0) {
        MemoryAllocationException err("ERROR:Cannot allocate memory.");
        err.memError();
    }

    // Copy the elements of obj's array.
    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <typename T>
SimpleVector<T>::~SimpleVector()
{
    if (arraySize > 0)
        delete[] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************
/*
template <typename T>
void SimpleVector<T>::memError()
{
    cout << "ERROR:Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}
*/
//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************
/*
template <typename T>
void SimpleVector<T>::subError()
{
    cout << "ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
}
*/
//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <typename T>
T SimpleVector<T>::getElementAt(int sub)
{
    if (sub < 0 || sub >= arraySize) {
        BoundsException err("ERROR: Subscript out of range.");
        err.subError();
    }
    return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <typename T>
T& SimpleVector<T>::operator[](const int& sub)
{
    if (sub < 0 || sub >= arraySize) {
        BoundsException err("ERROR: Subscript out of range.");
        err.subError();
    }
    return aptr[sub];
}
#endif 