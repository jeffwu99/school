#include "DequeT.h"
#include "QueueT.h"
#include <string>
using std::string;

int main() {
	//all changes
	DequeT<int> fully1;
	fully1.insertBack(1);
	cout << fully1.removeFront() << " - 1" << endl;
	cout << fully1.empty() << " - 1" << endl;
	fully1.insertFront(2);
	cout << fully1.empty() << " - 0" << endl;
	fully1.insertBack(3);
	fully1.insertBack(4);
	fully1.insertFront(1);
	cout << "below should be 1 2 3 4" << endl;
	fully1.printD();

	cout << fully1.removeFront() << " - 1" << endl;
	cout << fully1.removeBack() << " - 4" << endl;
	cout << "below should be 2 3" << endl;
	fully1.printD();
	cout << fully1.size() << " - 2" << endl;
	fully1.insertBack(4);
	fully1.insertFront(1);
	fully1.insertBack(5);
	cout << fully1.peekBack() << " - 5" << endl;
	cout << fully1.peekFront() << " - 1" << endl;
	cout << fully1.empty() << " - 0" << endl;

	//copy constructor testing
	DequeT<int> fully2(fully1);
	cout << fully2.removeBack() << " - 5" << endl;
	cout << fully2.removeFront() << " - 1" << endl;
	cout << "below should be 2 3 4" << endl;
	fully2.printD();
	cout << "below should be 1 2 3 4 5" << endl;
	fully1.printD();
	fully1.insertFront(0);
	fully1.insertFront(-1);
	
	//assignment operator =
	DequeT<int> fully3(fully1);
	fully3 = fully3;
	cout << "below should be -1 0 1 2 3 4 5" << endl;
	fully3.printD();
	fully3 = fully2;
	cout << "below should be 2 3 4" << endl;
	fully3.printD();
	cout << "below should be -1 0 1 2 3 4 5" << endl;
	fully1.printD();
	cout << fully3.removeBack() << " - 4" << endl;
	cout << fully3.peekBack() << " - 3" << endl;
	fully3.insertFront(1);
	cout << fully3.peekFront() << " - 1" << endl;
	fully1.insertBack(44);
	fully1.insertBack(45);
	fully1.insertBack(46);
	fully1.insertBack(47);
	fully1.insertBack(48);
	fully1.insertBack(49);
	fully1.insertBack(50);
	fully1.insertBack(51);
	fully1.insertBack(52);
	fully1.insertBack(53);
	fully1.insertBack(54);
	fully1.insertBack(55);
	fully1.insertBack(56);
	fully1.insertBack(44);
	fully1.insertBack(45);
	fully1.insertBack(46);
	fully1.insertBack(47);
	fully1.insertBack(48);
	fully1.insertBack(49);
	fully1.insertBack(50);
	fully1.insertBack(51);
	fully1.insertBack(52);
	fully1.insertBack(53);
	fully1.insertBack(54);
	fully1.insertBack(55);
	fully1.insertBack(56);	
	fully1.insertBack(44);
	fully1.insertBack(45);
	fully1.insertBack(46);
	fully1.insertBack(47);
	fully1.insertBack(48);
	fully1.insertBack(49);
	fully1.insertBack(50);
	fully1.insertBack(51);
	fully1.insertBack(52);
	fully1.insertBack(53);
	fully1.insertBack(54);
	fully1.insertBack(55);
	fully1.insertBack(56);
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	fully1.removeFront();
	cout << "Below should be 50 51 52 53 54 55 56" << endl;
	fully1.printD();
	fully1.removeBack();
	fully1.removeBack();
	fully1.removeBack();
	fully1.removeBack();
	fully1.removeBack();
	fully1.removeBack();
	fully1.removeBack();
	cout << "Below should say amazon" << endl;
	fully1.printD();
	cout << "amazon" << endl;
	cout << fully1.empty() << " - 1" << endl;
	cout << fully1.size() << " - 0" << endl;

	//leave fully3 as is, to make sure assignment operator works (testing on valgrind)
	fully3 = fully1;
	fully2 = fully1;
	fully1 = fully2;
	try {
		cout << fully2.peekBack() << endl;
	}
	catch (std::runtime_error) {
		cout << "error caught" << endl;
	}

	fully2.insertFront(0);
	cout << fully2.peekFront() << " - 0" << endl;
	cout << fully2.removeBack() << " - 0" << endl;
	try {
		cout << fully2.peekFront() << endl;
	}
	catch (std::runtime_error) {
		cout << "error caught" << endl;
	} 


	cout << "Below is test code from canvas" << endl;
	DequeT<int> dq1;
	cout << dq1.empty() << " - 1" << endl;
	dq1.insertFront(42);
	dq1.insertBack(216);
	cout << dq1.peekFront() << " - 42" << endl;
	cout << dq1.peekBack() << " - 216" << endl;
	cout << dq1.size() << " - 2" << endl;

	DequeT<int> dq2(dq1);
	DequeT<int> dq3;
	dq3 = dq1;

	cout << dq1.removeFront() << " - 42" << endl;
	cout << dq1.removeBack() << " - 216" << endl;

	cout << dq2.peekFront() << " - 42" << endl;
	cout << dq2.peekBack() << " - 216" << endl;
	cout << dq3.peekFront() << " - 42" << endl;
	cout << dq3.peekBack() << " - 216" << endl;


	cout << "Now working with QueueT BELOW" << endl;

	QueueT<float> qfloat1;
	cout << qfloat1.size() << " - 0" << endl;
	cout << qfloat1.empty() << " - 1" << endl;
	qfloat1.enqueue(1);
	qfloat1.enqueue(2);
	qfloat1.enqueue(3);
	qfloat1.enqueue(4);
	qfloat1.enqueue(5);
	cout << qfloat1.dequeue() << " - 1" << endl;
	cout << qfloat1.dequeue() << " - 2" << endl;
	cout << qfloat1.dequeue() << " - 3" << endl;
	cout << qfloat1.dequeue() << " - 4" << endl;
	qfloat1.enqueue(6);
	qfloat1.enqueue(7);
	cout << qfloat1.dequeue() << " - 5" << endl;
	cout << qfloat1.empty() << " - 0" << endl;
	cout << qfloat1.size() << " - 2" << endl;
 	cout << qfloat1.dequeue() << " - 6" << endl;
	cout << qfloat1.dequeue() << " - 7" << endl;

	cout << qfloat1.empty() << " - 1" << endl;
	cout << qfloat1.size() << " - 0 " << endl;

	try {
		qfloat1.dequeue();
	}
	catch (std::runtime_error) {
		cout << "error caught" << endl;
	}


	//leave this to test destructor
	QueueT<int> leave2;
	leave2.enqueue(56);
	leave2.enqueue(5054);
	leave2.enqueue(123);



	//default constructor
	DequeT<int> empty1;


	//destructor testing
	DequeT<string> leave1;
	leave1.insertBack("do not leave");
	leave1.insertBack("I mean do not remove so that this");
	leave1.insertFront("will be handled by the destructor");




	return 0;
}