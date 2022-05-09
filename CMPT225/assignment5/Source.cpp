#include "RedBlackTree.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void simpleTest()
{
	// Int Tree Tests	
	RedBlackTree<int, char> rb1;
	if (rb1.insert(6, 'f')) cout << "inserted 42" << endl;
	rb1.insert(10, 'j');
	rb1.insert(2, 'b');
	RedBlackTree<int, char> rb2(rb1);

	if (rb1.remove(2)) cout << "removed 2" << endl;
	if (rb1.search(6)) cout << "found 6" << endl;

	vector<char> v1 = rb1.search(8, 21); //should contain j
	vector<char> v2 = rb1.values(); //should contain {f, j}
	vector<int> v3 = rb1.keys(); //should contain {6, 10}

	cout << "size = " << rb1.size() << endl; //should be 2
	NodeT<int, char>* pRoot = rb1.getRoot(); //BAD design - for our testing only
	cout << "-----------------------V1-----------------" << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << endl;
	}
	cout << "-----------------------V2-----------------" << endl;
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << endl;
	}
	cout << "-----------------------V3-----------------" << endl;
	for (int i = 0; i < v3.size(); i++) {
		cout << v3[i] << endl;
	}

}




int main()
{
	RedBlackTree<string, int> b1;
	b1.insert("asd", 14);
	b1.insert("ds", 14);
	b1.insert("aaf", 14);
	b1.insert("assaf", 14);

	b1.insert("asd", 14);
	b1.remove("asd");
	b1.remove("asd");
	simpleTest();
	/*
	cout << "====================================TESTING FOR REDBLACKTREE<int, int>===================================" << endl;
	RedBlackTree<int, int> b1;
	cout << boolalpha;
	cout <<b1.insert(35, 0) << endl;
	cout << b1.size() << endl;
	cout << b1.insert(8, 0) << endl;
	cout << b1.insert(14, 0) << endl;
	cout << b1.insert(36, 0) << endl;
	cout << b1.insert(12, 0) << endl;
	cout << b1.insert(3, 0) << endl;
	cout << "should be false: " << b1.insert(36, 0) << endl;
	b1.ptree();
	cout << "size should be 6: " << b1.size() << endl;
	RedBlackTree<int, int> b2(b1);
	cout << "REMOVING BEGINS HERE:" << endl;
	cout << "should be false: " << b1.remove(100) << endl;
	cout << "should be true: " << b1.remove(3) << endl;
	//b1.ptree(); //correct here
	cout << "should be true: " << b1.remove(36) << endl;
	//b1.ptree(); //correct here
	b1.remove(14);
	//b1.ptree();
	RedBlackTree<int, int> b3;
	b3 = b1;
	b3.insert(11, 0);
	b3.insert(10, 0);
	//b3.ptree();
	b3.insert(200, 0);
	b3.insert(13, 0);
	//b3.ptree();
	b3.insert(7, 0);
	//b1.ptree(); //correct here
	b1.remove(35);
	//b1.ptree();// good up to here
	b3.insert(20, 0);
	b3.insert(5, 0);
	b3.insert(10, 0);
	//b3.ptree(); good up to here
	
	//b1.ptree(); // correct here
	cout << "should be 2: " << b1.size() << endl;
	b1.remove(8);
	//b1.ptree();
	b1.remove(12);
	cout << "should be 0: " << b1.size() << endl;
	//b1.ptree();
	b1.insert(8, 0);
	//b1.ptree();
	cout << "should be 1: " << b1.size() << endl;
	b1.insert(5, 0);
	b1.insert(2, 0);
	b1.insert(0, 0);
	b1.insert(25, 0);
	b1.insert(7, 0);
	b1.insert(6, 0);
	//b1.ptree(); //good
	b1.remove(8);
	//b1.ptree(); // good

	cout << "-----------------------BEGINNING ANOTHER RB INSERTION TEST-----------------" << endl;
	RedBlackTree<int, int> b0;
	b0.insert(2,0);
	b0.insert(1,0);
	b0.insert(4,0);
	b0.insert(5, 0);
	b0.insert(9, 0);
	b0.insert(3, 0);
	b0.insert(6, 0);
	b0.insert(7, 0);
	b0.ptree();
	cout << "---------------------BEGNINNING REMOVALS OF b3---------------------" << endl;
	b3.remove(200);
	b3.remove(7);
	//removing 8 is good

	//for different test case
	RedBlackTree<int, int> b4;
	b4 = b3;

	b3.remove(5);
	b3.remove(11);
	b3.remove(13);
	b3.remove(8);
	b3.remove(35);
	
	RedBlackTree<int, int> b5(b3);

	b3.remove(12);
	b3.ptree();
	cout << "----------------------REMOVALS FOR b5---------------------" << endl;
	b5.remove(20);
	b5.remove(12);
	b5.remove(10);
	cout << "---------nothing should be printed--------" << endl;
	b5.ptree();

	cout << "----------------INSERTIONS FOR b6-----------------" << endl;
	RedBlackTree<int, int> b6;
	b6.insert(50,0);
	b6.insert(49, 0);
	b6.insert(40, 0);
	b6.insert(35, 0);
	b6.insert(30, 0);
	b6.insert(25, 0);
	b6.insert(20, 0);
	b6.insert(15, 0);
	b6.insert(10, 0);
	b6.insert(9, 0);
	b6.insert(8, 0);
	b6.insert(7, 0);
	b6.insert(6, 0);
	b6.insert(5, 0);
	b6.insert(4, 0);
	b6.insert(3, 0);
	b6.insert(2, 0);
	b6.insert(1, 0);
	//b6.ptree(); // all correct here
	b6.remove(15);
	b6.remove(20);
	b6.insert(20,0);
	b6.ptree(); //all correct here



	cout << "-----------------------REMOVALS FOR b6-------------------" << endl;
	b6.remove(5);
	b6.remove(9);
	b6.remove(49);
	b6.remove(6);
	b6.insert(37, 0);
	b6.insert(38, 0);
	b6.insert(39, 0);
	b6.insert(36, 0);
	b6.insert(90, 0);
	b6.insert(80,0);
	b6.insert(45, 0);
	b6.insert(95, 0);
	b6.insert(100, 0);
	b6.insert(65, 0);
	b6.remove(39);
	b6.remove(7);
	b6.remove(10);
	//b6.ptree(); //good
	b6.remove(4);
	//b6.ptree(); //good
	b6.remove(3);
	b6.remove(2);
	b6.remove(80);
	//b6.ptree();//  good here
	b6.remove(65);
	b6.remove(8);
	b6.remove(37);
	b6.remove(38);
	b6.ptree();
	//cout << b6.size() << endl;

	cout << "---------------b7 to be searched-----------------------" << endl;
	RedBlackTree<int, int> b7;
	b7 = b7;
	b7.insert(61, 1);
	b7.insert(52, 2);
	b7.insert(85, 3);
	b7.insert(76, 4);
	b7.insert(93, 5);
	b7.insert(16, 6);
	b7.insert(20, 7);
	b7.insert(55, 8);
	b7.insert(71, 9);
	b7.insert(81, 10);
	b7.insert(90, 11);
	b7.insert(101, 12);
	b7.insert(65, 13);
	b7.insert(1000, 14);
	b7.insert(0, 15);
	//b7.ptree(); //good
	cout << "-----------------testing search on b7------------------------" << endl;
	cout << b7.search(1000) << " : should be true" << endl;
	cout << b7.search(90) << " : should be true" << endl;
	cout << b7.search(81) << " : should be true" << endl;
	cout << b7.search(0) << " : should be true" << endl;
	cout << b7.search(61) << " : should be true" << endl;
	cout << b7.search(52) << " : should be true" << endl;
	cout << b7.search(71) << " : should be true" << endl;

	cout << b7.search(1001) << " : should be false" << endl;
	cout << b7.search(100) << " : should be false" << endl;
	cout << b7.search(97) << " : should be false" << endl;
	cout << b7.search(-1) << " : should be false" << endl;
	cout << b7.search(63) << " : should be false" << endl;
	cout << b7.search(60) << " : should be false" << endl;
	cout << b7.search(51) << " : should be false" << endl;
	cout << b7.search(19) << " : should be false" << endl;

	cout << b7.getRoot()->value << " : should be 1" << endl;

	cout << "----------------testing search on b7----full---------------" << endl;
	vector<int> vec;
	vec = b7.search(-100, 2000);
	cout << "should print 1 to 15 below" << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}

	cout << "----------------testing search on b7----partial---------------" << endl;
	vec = b7.search(62, 77);
	cout << "should print 13, 9, 4" << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}

	cout << "----------------testing search on b7----partial---------------" << endl;
	vec = b7.search(76, 93);
	cout << "should print 4, 5, 3" << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
	cout << "----------------testing search on b7----partial---------------" << endl;
	vec = b7.search(61, 61);
	cout << "should print 1" << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
	cout << "----------------testing search on b7----partial---------------" << endl;
	vec = b7.search(20, 20);
	cout << "should print 7" << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
	cout << "----------------testing search on b7----partial---------------" << endl;
	vec = b7.search(69, 70);
	cout << "should not print anything" << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}

	cout << "---------------testing values on b7--------------" << endl;
	vector<int> vec2;
	vec2 = b7.values();
	for (int i = 0; i < vec2.size(); i++) {
		cout << vec2[i] << endl;
	}
	cout << "---------------testing keys on b7---------------" << endl;
	vector<int> vec3;
	vec3 = b7.values();
	for (int i = 0; i < vec3.size(); i++) {
		cout << vec3[i] << endl;
	}
	cout << "---------------testing empty RedBlackTree b8-----------------------" << endl;
	RedBlackTree<int, int> b8;
	cout << "size should be 0 : " << b8.size() << endl;
	cout << "search should be 0 : " << b8.search(-1000, 1000).size() << endl;
	cout << "values should be 0 : " << b8.values().size() << endl;
	cout << "keys should be 0 : " << b8.keys().size() << endl;
	b8.insert(100, 0);
	b8.insert(0, 0);
	b8.remove(0);
	b8.remove(99);
	b8.remove(100);
	cout << "size should be 0 : " << b8.size() << endl;
	cout << "search should be 0 : " << b8.search(-1000, 1000).size() << endl;
	cout << "values should be 0 : " << b8.values().size() << endl;
	cout << "keys should be 0 : " << b8.keys().size() << endl;


	cout << "-----------------------TESTING <char, string> tree a1---------------" << endl;

	RedBlackTree<char, string> a1;
	a1 = a1;
	RedBlackTree<char, string> a2(a1);
	a1.insert('j', "j key");
	a1.insert('g', "g key");
	a1.remove('j');
	a1.remove('g');
	a1.insert('j', "j key");
	a1.insert('g', "g key");
	a1.insert('f', "f key");
	a1.insert('p', "p key");
	a1.insert('z', "z key");
	a1.insert('x', "x key");
	a1.insert('b', "b key");
	a1.insert('a', "a key");
	a1.insert('u', "u key");
	a1.insert('e', "e key");
	a1.insert('i', "i key");
	a1.insert('t', "t key");
	a1.insert('d', "d key");
	a1.insert('h', "h key");
	a1.insert('l', "l key");
	a1.insert('[', "[ key");
	//a1.ptree(); //all good
	cout << "should be 16: " << a1.size() << endl;
	a1.remove('b');
	a1.remove('l');
	a1.remove('x');
	a1.remove('j');
	a1.insert('b', "b key");
	a1.insert('l', "l key");
	a1.insert('x', "x key");
	a1.insert('j', "j key");
	//a1.ptree(); // all good
	a2 = a1;
	a2 = a2;

	cout << "should be true : " << a1.search('g') << endl;
	cout << "should be true : " << a1.search('u') << endl;
	cout << "should be true : " << a1.search('z') << endl;
	cout << "should be true : " << a1.search('x') << endl;
	cout << "should be true : " << a1.search('t') << endl;
	cout << "should be true : " << a1.search('l') << endl;
	cout << "should be true : " << a1.search('j') << endl;
	cout << "should be true : " << a1.search('e') << endl;
	cout << "should be true : " << a1.search('f') << endl;
	cout << "should be true : " << a1.search('[') << endl;
	cout << "should be true : " << a1.search('b') << endl;
	cout << "should be false : " << a1.search(']') << endl;
	cout << "should be false : " << a1.search('v') << endl;
	cout << "should be false : " << a1.search('Z') << endl;
	cout << "should be false : " << a1.search('A') << endl;
	cout << "should be false : " << a1.search('G') << endl;
	cout << "should be false : " << a1.search('q') << endl;
	cout << "should be false : " << a1.search('w') << endl;
	cout << "should be false : " << a1.search('y') << endl;
	cout << "should be false : " << a1.search('m') << endl;
	cout << "should be false : " << a1.search('n') << endl;
	cout << "should be false : " << a1.search('o') << endl;
	cout << "should be false : " << a1.search('2') << endl;

	cout << "values should be: [,a,b,d,e,f,g,h,i,j,l,p,t,u,x,z" << endl;
	vector<string> vec4 = a1.values();
	for (int i = 0; i < vec4.size(); i++) {
		cout << vec4[i] << endl;
	}

	vector<char> vec5 = a1.keys();
	for (int i = 0; i < vec5.size(); i++) {
		cout << vec5[i] << endl;
	}

	*/


	return 0;
}

//problems
/*


*/