#include <iostream>
#include "Heap - Copy.h"
using namespace std;

int main() {
	try {
		Heap<int> a(20);
		a.insert(98);
		a.insert(86);
		a.insert(41);
		a.insert(13);
		a.insert(65);
		a.insert(32);
		a.insert(29);
		a.insert(9);
		a.insert(10);
		a.insert(44);
		a.insert(23);
		a.insert(21);
		a.insert(17);
		//a.console();
		//cout << "a current size: " << a.size() << endl;

		Heap<int> b(20);
		//now in random order
		b.insert(41);
		b.insert(32);
		b.insert(86);
		b.insert(9);
		b.insert(10);
		b.insert(44);
		b.insert(98);
		b.insert(13);
		b.insert(29);
		b.insert(23);
		b.insert(65);
		b.insert(17);
		b.insert(21);
		//b.console();
		//cout << "b current size: " << b.size() << endl;

		Heap<int> c(3);
		c.insert(19);
		c.insert(29);
		c.insert(39);
		//c.console();
		//c.insert(2); //test size error

		Heap<int> d(c);
		//d.console();
		//cout << "d current size: " << d.size() << endl;
		//d.insert(2);

		Heap<int> e(6);
		Heap<int> f(e);
		f.insert(88);
		f.insert(5);
		f.insert(100);
		//f.console();
		//cout << "e current size: " << e.size() << endl;
		e = f;
		e.insert(2);
		e.insert(24);
		//cout << "e current size: " << e.size() << endl;
		//e.console();
		//f.console();

		b.remove();
		//b.console();
		cout << "should be 86: " << b.remove() << endl;
		//b.console();
		cout << "should be 65: " << b.remove() << endl;
		//b.console();
		cout << b.peek() << " should be 44" << endl;
		cout << a.peek() << " should be 98" << endl;
		cout << d.peek() << " should be 39" << endl;
		cout << f.peek() << " should be 100" << endl;

		Heap<int> g(11);
		g.insert(96);
		g.insert(28);
		g.insert(43);
		g.insert(31);
		g.insert(40);
		g.insert(9);
		g.insert(30);
		g.insert(0);
		g.insert(16);
		g.insert(24);
		g.insert(8);
		//g.console();
		Heap<int> h(g);
		//11 removals to be empty
		cout << "should be 96: " << h.remove() << endl;
		cout << "should be 43: " << h.remove() << endl;
		cout << "should be 40: " << h.remove() << endl;
		cout << "should be 31: " << h.remove() << endl;
		cout << "should be 30: " << h.remove() << endl;
		cout << "should be 28: " << h.remove() << endl;
		cout << "should be 24: " << h.remove() << endl;
		cout << "should be 16: " << h.remove() << endl;
		cout << "should be 9: " << h.remove() << endl;
		cout << "should be 8: " << h.remove() << endl;
		cout << "should be 0: " << h.remove() << endl;
		h.console();
		cout << h.size() << " SHould be 0" << endl;
		h.insert(3);
		h.insert(100);
		h.insert(2);
		h.insert(58);
		h.insert(60);
		h.insert(80);
		h.insert(5);
		//h.console();
		Heap<int> i = h.merge(g);
		cout << i.size() << " should be 18" << endl;
		//i.console();
		i.remove();
		i.remove();
		i.insert(120);
		i.insert(100);
		Heap<int> j(i.size() + 10);
		j = i;
		//j.console();
		//cout << b.size() << endl;
		Heap<int> k = j.merge(i.merge(h.merge(b)));
		//cout << "should be 53: " << k.size() << endl;
		//k.console(); //its good

		i = i;
		cout << "this should not error????: " << i.remove() << endl;

		cout << k.peek() << " should be 120" << endl;
		cout << k.remove() << " should be 120" << endl;
		cout << k.peek() << " should be 120" << endl;
		cout << k.remove() << " should be 120" << endl;
		cout << k.peek() << " should be 100" << endl;
		cout << k.remove() << " should be 100" << endl;
		cout << k.peek() << " should be 100" << endl;
		cout << k.remove() << " should be 100" << endl;
		cout << k.peek() << " should be 100" << endl;
		cout << k.remove() << " should be 100" << endl;
		cout << k.peek() << " should be 80" << endl;
		cout << k.remove() << " should be 80" << endl;
		cout << k.peek() << " should be 80" << endl;
		cout << k.remove() << " should be 80" << endl;
		cout << k.peek() << " should be 80" << endl;
		cout << k.remove() << " should be 80" << endl;
		cout << k.peek() << " should be 60" << endl;
		cout << k.remove() << " should be 60" << endl;
		cout << k.remove() << " should be 60" << endl;
		cout << k.remove() << " should be 60" << endl;
		cout << k.remove() << " should be 58" << endl;
		cout << k.remove() << " should be 58" << endl;
		cout << k.remove() << " should be 58" << endl;
		cout << k.size() << " should be 39" << endl;

		vector<int> l{ 13, 65, 32, 29, 86, 41, 9, 10, 44, 23, 21, 17, 98 };
		vector<int> m = smallestm(l, 14);
		for (int i = 0; i < m.size(); i++) {
			cout << m[i] << endl;
		}
		vector<char> n(500);
		for (int i = 0; i < 500; i++) {
			int placeholder2 = rand() % 26;
			n[i] = 'A' + placeholder2;
		}
		vector<char> o = smallestm(n, 0);
		for (int i = 0; i < o.size(); i++) {
			cout << o[i] << endl;
		}

	}
	catch (std::runtime_error) {
		cout << "runtime error" << endl;
	}

	vector<int> aa{ 1, 6, 234, 123 ,125, 120 ,1, 20 ,150 ,12 ,12, 1 };
	vector<int> bb = smallestm(aa, 3);
	for (int i = 0; i < bb.size(); i++) {
		cout << bb[i] << endl;
	}


	return 0;
}