//#include "DequeT.h"


//to test:
// copydeque method
// copy constructor                             done
// insertfront                                  done
// insertback                                   done
// removefront (include exceptions)             done
// removeback  (include exceptions)             done
// peekfront   (include exceptions)             done
// peekback    (include exceptions)             done
// 
// assignment operator                          done
// size                                         done
// empty                                        done
// 
// add malloc at the end


// empty deque
// deq size 1
// deq size 2
// deq size 3
// deq size 7





//int main() {
//    try {
//        //test copy constructor
//        //size 0
//        DequeT<int> copy01;
//        DequeT<int> copy02(copy01);
//        copy01.printD();
//        copy02.printD();
//        //size 1
//        copy01.insertFront(9);
//        DequeT<int> copy03(copy01);
//        //copy03.printD();
//        copy03.insertBack(55);
//        copy03.insertFront(0);
//        //copy03.printD();
//        //size 2
//        copy01.insertBack(99);
//        DequeT<int> copy04(copy01);
//        copy04.insertFront(8);
//        copy04.insertBack(1);
//        // copy04.printD();
//        //cout << "original copy" << endl;
//        //copy01.printD();
//
//        //size x
//        DequeT<int> copy1;
//        copy1.insertFront(1234);
//        copy1.insertFront(4321);
//        copy1.insertFront(11);
//        copy1.insertFront(20);
//        copy1.insertFront(99);
//        copy1.insertBack(5);
//        DequeT<int> copy2(copy1);
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
//        DequeT<int> as1;
//        DequeT<int> selfAssign; //self assign all good
//
//        selfAssign = selfAssign; //check empty
//        //selfAssign.printD();
//        selfAssign.insertFront(1);
//        selfAssign = selfAssign; //now size 1
//        //selfAssign.printD();
//        selfAssign.insertFront(2);
//        selfAssign = selfAssign; //now size 2
//        //selfAssign.printD();
//        selfAssign.insertBack(3);
//        selfAssign.insertBack(6);
//        selfAssign.insertBack(8);
//        selfAssign = selfAssign; // now size 5
//        //selfAssign.printD();
//
//        DequeT<int> as2;
//
//        as2 = as1;
//        as2.printD();
//        as2.insertFront(401);
//        //as2 = as1;
//        //as2.printD();
//        as2.insertFront(5);
//        as2.insertFront(9);
//        as2.insertFront(40);
//        as2 = as1;                             //all empty assignments work
//        //cout<< as2.size() << endl;
//
//        as1.insertBack(1);
//        as2 = as1;
//        //as2.printD();
//        as1.insertFront(3);
//        as1.insertFront(5);
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
//        DequeT<int> d0;
//        DequeT<int> d1;
//        DequeT<int> d2;
//        DequeT<int> d3;
//        DequeT<int> d4;
//        DequeT<int> d5;
//        DequeT<int> d6;
//        DequeT<int> d7;
//        DequeT<int> d8;
//
//        d1.insertFront(1);
//
//        d2.insertFront(22);
//        d2.insertFront(32);
//
//        d3.insertFront(2);
//        d3.insertFront(3);
//        d3.insertFront(4);
//
//        d4.insertFront(90);
//        d4.insertFront(20);
//        d4.insertFront(30);
//        d4.insertFront(45);
//        d4.insertFront(50);
//        d4.insertFront(212);
//        d4.insertFront(201);
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
//        d5.insertBack(1);
//
//        d6.insertBack(22);
//        d6.insertBack(32);
//
//        d7.insertBack(2);
//        d7.insertBack(3);
//        d7.insertBack(4);
//
//        d8.insertBack(90);
//        d8.insertBack(20);
//        d8.insertBack(30);
//        d8.insertBack(50);
//        d8.insertBack(212);
//        d8.insertBack(201);
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
//        DequeT<int> c1;
//
//        c1.insertFront(4);
//        c1.insertBack(5);
//        c1.insertBack(6);
//        c1.insertBack(0);
//        c1.insertFront(90);
//        c1.insertBack(909);
//        c1.insertFront(80);
//        c1.insertFront(4321);
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
//        c1.insertFront(77);
//        c1.insertBack(99);
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