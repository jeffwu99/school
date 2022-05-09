//#include "QueueT.h"
//
///*
//
//enqueue method
//dequeue method
//
//empty
//size
//
//empty deque
//size 1
//size 2
//size 3
//size 7
//
//
//
//
//
//*/
//
//
//int main() {
//	try {
//		QueueT<int> q1;
//		cout << "now printing size 0" << endl;
//		q1.print();
//		cout << "0 size: " << q1.size() << endl;
//		cout << "empty: " << q1.empty() << endl;
//
//		QueueT<int> q2;
//		cout << "now printing size 1" << endl;
//		q2.enqueue(0);
//		q2.print();
//		cout << "1 size: " << q2.size() << endl;
//		cout << "empty: " << q2.empty() << endl;
//
//		QueueT<int> q3;
//		q3.enqueue(43);
//		q3.enqueue(242);
//		cout << "Now printing size 2" << endl;
//		q3.print();
//		cout << "2 size: " << q3.size() << endl;
//		cout << "empty: " << q3.empty() << endl;
//
//		QueueT<int> q4;
//		q4.enqueue(434);
//		q4.enqueue(4);
//		q4.enqueue(5);
//		cout << "Now printing size 3" << endl;
//		q4.print();
//		cout << "3 size: " << q4.size() << endl;
//		cout << "empty: " << q4.empty() << endl;
//
//		QueueT<int> q5;
//		q5.enqueue(43);
//		q5.enqueue(242);
//		q5.enqueue(2);
//		q5.enqueue(3);
//		q5.enqueue(4);
//		q5.enqueue(5);
//		q5.enqueue(6);
//		cout << "Now printing size x" << endl;
//		q5.print();
//		cout << "x size: " << q5.size() << endl;
//		cout << "empty: " << q5.empty() << endl;
//
//		cout << "removing items from q5" << endl;
//		q5.dequeue();
//		q5.dequeue();
//		q5.dequeue();
//		q5.dequeue();
//		q5.dequeue();
//		q5.dequeue();
//		q5.dequeue();
//		//cout << q5.dequeue() << endl; //error caught
//		q5.enqueue(4);
//		q5.enqueue(5);
//		q5.enqueue(6);
//		cout << q5.dequeue() << endl;
//		cout << q5.dequeue() << endl;
//		cout << q5.dequeue() << endl;
//		q5.enqueue(5);
//		q5.enqueue(6);
//		cout << q5.dequeue() << endl;
//		q5.enqueue(4);
//		cout << "x size: " << q5.size() << endl;
//		cout << "empty: " << q5.empty() << endl;
//		cout << q5.dequeue() << endl;
//		cout << q5.dequeue() << endl;
//		cout << "x size: " << q5.size() << endl;
//		cout << "empty: " << q5.empty() << endl;
//
//		DequeT<int> test1;
//		test1.insertFront(99);
//		cout << test1.removeFront() << endl;
//		test1.insertFront(99);
//		cout << test1.removeFront() << endl;
//		test1.insertFront(99);
//		cout << test1.removeFront() << endl;
//		test1.insertFront(99);
//		cout << test1.removeBack() << endl;
//		test1.insertFront(99);
//		cout << test1.removeBack() << endl;
//		test1.insertFront(99);
//		cout << test1.removeFront() << endl;
//		test1.insertFront(99);
//		cout << test1.removeBack() << endl;
//		cout << test1.removeFront() << endl;
//
//	}
//	catch (std::runtime_error) {
//		cout << "error caught" << endl;
//	}
//
//
//	return 0;
//}