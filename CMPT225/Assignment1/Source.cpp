#include "StringList.h"
#include <iostream>
using std::cout;
using std::endl;
////void basicTest()
////{
////	StringList slist1;
////	slist1.insert("cat", 0);
////	slist1.insert("bat", 1);
////	slist1.insert("rat", 2);
////
////	StringList slist2(slist1);
////
////	slist1.swap(0, 1);
////	string animal1 = slist1.retrieve(1);
////	string animal2 = slist1.remove(2);
////	cout << "slist1 size = " << slist1.size();
////
////	StringList slist3 = slist1.concatenate(slist2);
////	slist1 = slist2;
////
////	cout << endl << "end basic test" << endl;
////}
//
//
////function declarations
//void reverse(StringList& sl);
//StringList readFile(string name);
//StringList merge(const StringList& slA, const StringList& slB);
//
//
//int main() {
//
//	StringList s1;
//
//	try {
//		//s1.insert("abc", 0);
//		//s1.insert("bcd", 1);
//		//s1.insert("def", 2);
//		//s1.insert("ggg", 3);
//		//s1.insert("bruh", 4);
//		//s1.deets();
//
//		//s1.remove(4);
//		//s1.deets();
//
//		//StringList s2;
//		//s2 = s1;
//
//		//s1.swap(3, 2);
//		//s1.deets();
//		cout << "basic test begins" << endl;
//		StringList slist1;
//		slist1.insert("cat", 0);
//		slist1.insert("bat", 1);
//		slist1.insert("rat", 2);
//		//slist1.deets();
//
//		StringList slist2(slist1);
//		//slist2.deets();
//		
//		slist1.swap(0, 1);
//		//slist1.deets();
//		string animal1 = slist1.retrieve(1);
//		string animal2 = slist1.remove(2);
//
//		cout << animal1 << "   " << animal2 << endl;
//		//slist1.deets();
//		cout << "slist1 size = " << slist1.size() << endl;
//
//		StringList s5;
//		s5.insert("A", 0);
//		s5.insert("B", 1);
//		s5.insert("C", 2);
//		//s5.insert("D", 3);
//
//		StringList s4;
//		s4.insert("1", 0);
//		s4.insert("2", 1);
//		s4.insert("3", 2);
//		s4.insert("4", 3);
//		s4.insert("5", 4);
//		s4.insert("6", 5);
//
//
//
//		//StringList slist3 = slist1.concatenate(s5);
//		//slist1.deets();
//		//s5.deets();
//		//slist3.insert("G", 6);
//		//slist3.deets();
//		//reverse(slist3);
//		//slist3.deets();
//		
//
//		StringList sl2;
//		sl2 = merge(s5, s4);
//
//
//		sl2.deets();
//
//
//		reverse(sl2);
//		sl2.deets();
//
//
//		sl2.concatenate(sl2);
//		sl2.swap(3, 3);
//		sl2.deets();
//
//		//slist1 = slist2;
//		// slist2.deets();
//		//slist1.deets();
//		//cout << endl << "end basic test" << endl;
//	}
//	catch(std::out_of_range err) {
//		cout << err.what() << endl;
//	}
//
//
//
//	return 0;
//}
//

StringList readFile(string name);


int main() {
	try {
		StringList s2;
		cout << s2.size() << endl;
		s2.insert("helo", 0);
		s2.insert("good", 1);
		StringList s3;
		cout << s2.remove(1) << endl;
		cout << s2.remove(0) << endl;

		cout << "NOW COMMENCING READ FILE" << endl;

		StringList s1 = readFile("check.txt");
		cout << s1.remove(6) << endl;
		cout << s1.remove(0) << endl;
		cout << s1.remove(0) << endl;
		cout << s1.remove(0) << endl;
		cout << s1.remove(0) << endl;
		cout << s1.remove(0) << endl;
		cout << s1.remove(0) << endl;
		cout << s1.size() << endl;



	}
	catch (std::out_of_range) {
		cout << "bruh" << endl;
	}
	return 0;
}