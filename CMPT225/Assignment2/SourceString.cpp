//#include "DequeT.h"
//#include <string>
//using std::string;
//
//int main() {
//    try {
//        //test copy constructor
//        //size 0
//        DequeT<string> copy01;
//        DequeT<string> copy02(copy01);
//        copy01.printD();
//        copy02.printD();
//        //size 1
//        copy01.insertFront("one");
//        DequeT<string> copy03(copy01);
//        //copy03.printD();
//        copy03.insertBack("two");
//        copy03.insertFront("eight");
//        copy03.printD();
//        //size 2
//        copy01.insertBack("juan");
//        DequeT<string> copy04(copy01);
//        copy04.insertFront("tuno");
//        copy04.insertBack("tuna");
//        // copy04.printD();
//        //cout << "original copy" << endl;
//        //copy01.printD();
//
//        //size x
//        DequeT<string> copy1;
//        copy1.insertFront("yeet");
//        copy1.insertFront("yeey");
//        copy1.insertFront("eleven");
//        copy1.insertFront("pop");
//        copy1.insertFront("pass");
//        copy1.insertBack("word");
//        DequeT<string> copy2(copy1);
//        copy1.removeFront();
//        copy2.removeBack();
//        copy2.removeBack();
//        copy2.removeBack();
//        copy2.removeBack();
//
//        cout << "copy1: " << endl;
//        //copy1.printD();
//        cout << "copy2: " << endl;
//        //copy2.printD();
//
//        //assignment operator
//        DequeT<string> as1;
//        DequeT<string> selfAssign; //self assign all good
//
//        selfAssign = selfAssign; //check empty
//        //selfAssign.printD();
//        selfAssign.insertFront("juan");
//        selfAssign = selfAssign; //now size 1
//        //selfAssign.printD();
//        selfAssign.insertFront("juwon");
//        selfAssign = selfAssign; //now size 2
//        //selfAssign.printD();
//        selfAssign.insertBack("ja");
//        selfAssign.insertBack("12345");
//        selfAssign.insertBack("8");
//        selfAssign = selfAssign; // now size 5
//        //selfAssign.printD();
//
//        DequeT<string> as2;
//
//        as2 = as1;
//        as2.printD();
//        as2.insertFront("newyork");
//        //as2 = as1;
//        //as2.printD();
//        as2.insertFront("area");
//        as2.insertFront("Asf");
//        as2.insertFront("124129");
//        as2 = as1;                             //all empty assignments work
//        //cout<< as2.size() << endl;
//
//        as1.insertBack("001");
//        as2 = as1;
//        //as2.printD();
//        as1.insertFront("007");
//        as1.insertFront("weqrfa");
//        as2 = as1;
//        //as2.printD();
//        //cout << as2.size() << endl;         //all 2 and 3 length assignments work
//
//        as1.removeBack();
//        as1.removeBack();
//        as2 = as1;
//        //cout << as2.size() << endl;
//        //as2.printD();                         //assignment to another smaller deque works
//
//
//
//        DequeT<string> d0;
//        DequeT<string> d1;
//        DequeT<string> d2;
//        DequeT<string> d3;
//        DequeT<string> d4;
//        DequeT<string> d5;
//        DequeT<string> d6;
//        DequeT<string> d7;
//        DequeT<string> d8;
//
//        d1.insertFront(":1");
//
//        d2.insertFront("asf");
//        d2.insertFront("yes");
//
//        d3.insertFront("two");
//        d3.insertFront("three");
//        d3.insertFront("dboule");
//
//        d4.insertFront("pop");
//        d4.insertFront("push");
//        d4.insertFront("stack");
//        d4.insertFront("merc");
//        d4.insertFront("keep");
//        d4.insertFront("going");
//        d4.insertFront("yet");
//
//        cout << "printing D0" << endl;
//        d0.printD();
//
//        cout << "printing D1" << endl;
//        d1.printD();
//
//        cout << "printing D2" << endl;
//        d2.printD();
//
//        cout << "printing D3" << endl;
//        d3.printD();
//
//        cout << "printing D4" << endl;
//        d4.printD();
//
//        d5.insertBack("1");
//
//        d6.insertBack("22");
//        d6.insertBack("32");
//
//        d7.insertBack("2");
//        d7.insertBack("3");
//        d7.insertBack("4");
//
//        d8.insertBack("24");
//        d8.insertBack("235");
//        d8.insertBack("320");
//        d8.insertBack("yes");
//        d8.insertBack("another");
//        d8.insertBack("strting");
//
//        cout << "printing D5" << endl;
//        d5.printD();
//
//        cout << "printing D6" << endl;
//        d6.printD();
//
//        cout << "printing D7" << endl;
//        d7.printD();
//
//        cout << "printing D8" << endl;
//        d8.printD();
//
//        DequeT<string> c1;
//
//        c1.insertFront("y4");
//        c1.insertBack("yes5");
//        c1.insertBack("str6");
//        c1.insertBack("0");
//        c1.insertFront("90");
//        c1.insertBack("909");
//        c1.insertFront("80");
//        c1.insertFront("4321");
//
//        cout << "printing c1" << endl;
//        c1.printD();
//
//        cout << "c1 peekFront: " << c1.peekFront() << endl;
//        cout << "c1 peekBack: " << c1.peekBack() << endl;
//
//        cout << "c1 removed some" << endl;
//        c1.removeFront();
//        c1.removeFront();
//        c1.removeBack();
//        c1.removeBack();
//        c1.removeBack();
//        c1.removeBack();
//        c1.insertFront("77");
//        c1.insertBack("99");
//        c1.printD();
//
//        //d0.peekBack(); //caught
//        //d0.peekFront(); //caught
//        //d0.removeBack(); //caught
//        //d0.removeFront(); //caught
//
//        cout << "D0 emty: " << d0.empty() << endl;
//        cout << "D1 emty: " << d1.empty() << endl;
//        cout << "D2 emty: " << d2.empty() << endl;
//        cout << "D3 emty: " << d3.empty() << endl;
//
//        cout << "D0 size: " << d0.size() << endl;
//        cout << "D1 size: " << d1.size() << endl;
//        cout << "D2 size: " << d2.size() << endl;
//        cout << "D3 size: " << d3.size() << endl;
//
//        c1 = c1;
//        c1.printD();
//
//
//
//
//    }
//    catch (std::runtime_error) {
//        cout << "error caught" << endl;
//    }
//
//    return 0;
//}