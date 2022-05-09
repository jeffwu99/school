///*

#include <iostream>
#include "cmpt225sort.h"
using std::endl;
using std::cout;

//string generation:
#include "helper.h"
using std::string;


int main() {
	const int TESTSIZE = 1;
	const int TESTSIZE2 = 2;
	const int TESTSIZE3 = 3;
	const int TESTSIZE4 = 4;
	const int TESTSIZE5 = 5;
	const int TESTSIZE6 = 10;
	const int TESTSIZE7 = 32;
	const int TESTSIZE8 = 256;
	const int TESTSIZE9 = 500;
	const int TESTSIZE10 = 10000;
	//----------------------------------------------
	int arr[TESTSIZE];
	for (int i = 0; i < TESTSIZE; i++) {
		arr[i] = rand() & 1000;
	}

	float arr2[TESTSIZE];
	for (int i = 0; i < TESTSIZE; i++) {
		arr2[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000.0));
	}

	int placeholder = 0;
	char arr3[TESTSIZE];
	for (int i = 0; i < TESTSIZE; i++) {
		placeholder = rand() % 26;
		arr3[i] = 'A' + placeholder;
	}
	//----------------------------------------------
	int arr4[TESTSIZE2];
	for (int i = 0; i < TESTSIZE2; i++) {
		arr4[i] = rand() & 1000;
	}

	float arr5[TESTSIZE2];
	for (int i = 0; i < TESTSIZE2; i++) {
		arr5[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000.0));
	}

	int placeholder2 = 0;
	char arr6[TESTSIZE2];
	for (int i = 0; i < TESTSIZE2; i++) {
		placeholder2 = rand() % 26;
		arr6[i] = 'A' + placeholder2;
	}
	//------------------------------------------------------
	int arr7[TESTSIZE3];
	for (int i = 0; i < TESTSIZE3; i++) {
		arr7[i] = rand() & 1000;
	}

	float arr8[TESTSIZE3];
	for (int i = 0; i < TESTSIZE3; i++) {
		arr8[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000.0));
	}

	int placeholder3 = 0;
	char arr9[TESTSIZE3];
	for (int i = 0; i < TESTSIZE3; i++) {
		placeholder3 = rand() % 26;
		arr9[i] = 'A' + placeholder3;
	}
	//--------------------------------------------------------
	int arr10[TESTSIZE4];
	for (int i = 0; i < TESTSIZE4; i++) {
		arr10[i] = rand() & 1000;
	}

	float arr11[TESTSIZE4];
	for (int i = 0; i < TESTSIZE4; i++) {
		arr11[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000.0));
	}

	int placeholder4 = 0;
	char arr12[TESTSIZE4];
	for (int i = 0; i < TESTSIZE4; i++) {
		placeholder4 = rand() % 26;
		arr12[i] = 'A' + placeholder4;
	}
	//--------------------------------------------------------
	int arr13[TESTSIZE5];
	for (int i = 0; i < TESTSIZE5; i++) {
		arr13[i] = rand() & 1000;
	}

	float arr14[TESTSIZE5];
	for (int i = 0; i < TESTSIZE5; i++) {
		arr14[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000.0));
	}

	int placeholder5 = 0;
	char arr15[TESTSIZE5];
	for (int i = 0; i < TESTSIZE5; i++) {
		placeholder5 = rand() % 26;
		arr15[i] = 'A' + placeholder5;
	}
	//----------------------------------------------------------
	int arr16[TESTSIZE6];
	for (int i = 0; i < TESTSIZE6; i++) {
		arr16[i] = rand() & 1000;
	}

	float arr17[TESTSIZE6];
	for (int i = 0; i < TESTSIZE6; i++) {
		arr17[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000.0));
	}

	int placeholder6 = 0;
	char arr18[TESTSIZE6];
	for (int i = 0; i < TESTSIZE6; i++) {
		placeholder6 = rand() % 26;
		arr18[i] = 'A' + placeholder6;
	}
	//-------------------------------------------------------------
	int arr19[TESTSIZE7];
	for (int i = 0; i < TESTSIZE7; i++) {
		arr19[i] = rand() & 1000;
	}

	float arr20[TESTSIZE7];
	for (int i = 0; i < TESTSIZE7; i++) {
		arr20[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000.0));
	}

	int placeholder7 = 0;
	char arr21[TESTSIZE7];
	for (int i = 0; i < TESTSIZE7; i++) {
		placeholder7 = rand() % 26;
		arr21[i] = 'A' + placeholder7;
	}
	//-------------------------------------------------------------------
	int arr22[TESTSIZE8];
	for (int i = 0; i < TESTSIZE8; i++) {
		arr22[i] = rand() & 1000;
	}

	float arr23[TESTSIZE8];
	for (int i = 0; i < TESTSIZE8; i++) {
		arr23[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000.0));
	}

	int placeholder8 = 0;
	char arr24[TESTSIZE8];
	for (int i = 0; i < TESTSIZE8; i++) {
		placeholder8 = rand() % 26;
		arr24[i] = 'A' + placeholder8;
	}
	//--------------------------------------------------------------------
	int arr25[TESTSIZE9];
	for (int i = 0; i < TESTSIZE9; i++) {
		arr25[i] = rand() & 1000;
	}

	float arr26[TESTSIZE9];
	for (int i = 0; i < TESTSIZE9; i++) {
		arr26[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000.0));
	}

	int placeholder9 = 0;
	char arr27[TESTSIZE9];
	for (int i = 0; i < TESTSIZE9; i++) {
		placeholder9 = rand() % 26;
		arr27[i] = 'A' + placeholder9;
	}
	//---------------------------------------------------------------------
	int arr28[TESTSIZE10];
	for (int i = 0; i < TESTSIZE10; i++) {
		arr28[i] = rand() & 1000;
	}

	float arr29[TESTSIZE10];
	for (int i = 0; i < TESTSIZE10; i++) {
		arr29[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000.0));
	}

	int placeholder10 = 0;
	char arr30[TESTSIZE10];
	for (int i = 0; i < TESTSIZE10; i++) {
		placeholder10 = rand() % 26;
		arr30[i] = 'A' + placeholder10;
	}
	//--------------------------------------------------------------------
	//string arrays

	const int TESTSIZE91 = 1;
	const int TESTSIZE92 = 2;
	const int TESTSIZE93 = 3;
	const int TESTSIZE94 = 4;
	const int TESTSIZE95 = 10;
	const int TESTSIZE96 = 256;
	const int TESTSIZE97 = 1000;

	string arr91[TESTSIZE91];
	for (int i = 0; i < TESTSIZE91; i++) {
		arr91[i] = random_string();
	}
	string arr92[TESTSIZE92];
	for (int i = 0; i < TESTSIZE92; i++) {
		arr92[i] = random_string();
	}
	string arr93[TESTSIZE93];
	for (int i = 0; i < TESTSIZE93; i++) {
		arr93[i] = random_string();
	}
	string arr94[TESTSIZE94];
	for (int i = 0; i < TESTSIZE94; i++) {
		arr94[i] = random_string();
	}
	string arr95[TESTSIZE95];
	for (int i = 0; i < TESTSIZE95; i++) {
		arr95[i] = random_string();
	}
	string arr96[TESTSIZE96];
	for (int i = 0; i < TESTSIZE96; i++) {
		arr96[i] = random_string();
	}
	string arr97[TESTSIZE97];
	for (int i = 0; i < TESTSIZE97; i++) {
		arr97[i] = random_string();
	}


	//testing shellsort here
	cout << "arr1: " << shellsort(arr, TESTSIZE) << endl;
	cout << "arr2: " << shellsort(arr2, TESTSIZE) << endl;
	cout << "arr3: " << shellsort(arr3, TESTSIZE) << endl;
	cout << "arr4: " << shellsort(arr4, TESTSIZE2) << endl;
	cout << "arr5: " << shellsort(arr5, TESTSIZE2) << endl;
	cout << "arr6: " << shellsort(arr6, TESTSIZE2) << endl;
	cout << "arr7: " << shellsort(arr7, TESTSIZE3) << endl;
	cout << "arr8: " << shellsort(arr8, TESTSIZE3) << endl;
	cout << "arr9: " << shellsort(arr9, TESTSIZE3) << endl;
	cout << "arr10: " << shellsort(arr10, TESTSIZE4) << endl;
	cout << "arr11: " << shellsort(arr11, TESTSIZE4) << endl;
	cout << "arr12: " << shellsort(arr12, TESTSIZE4) << endl;
	cout << "arr13: " << shellsort(arr13, TESTSIZE5) << endl;
	cout << "arr14: " << shellsort(arr14, TESTSIZE5) << endl;
	cout << "arr15: " << shellsort(arr15, TESTSIZE5) << endl;
	cout << "arr16: " << shellsort(arr16, TESTSIZE6) << endl;
	cout << "arr17: " << shellsort(arr17, TESTSIZE6) << endl;
	cout << "arr18: " << shellsort(arr18, TESTSIZE6) << endl;
	cout << "arr19: " << shellsort(arr19, TESTSIZE7) << endl;
	cout << "arr20: " << shellsort(arr20, TESTSIZE7) << endl;
	cout << "arr21: " << shellsort(arr21, TESTSIZE7) << endl;
	cout << "arr22: " << shellsort(arr22, TESTSIZE8) << endl;
	cout << "arr23: " << shellsort(arr23, TESTSIZE8) << endl;
	cout << "arr24: " << shellsort(arr24, TESTSIZE8) << endl;
	cout << "arr25: " << shellsort(arr25, TESTSIZE9) << endl;
	cout << "arr26: " << shellsort(arr26, TESTSIZE9) << endl;
	cout << "arr27: " << shellsort(arr27, TESTSIZE9) << endl;
	cout << "arr28: " << shellsort(arr28, TESTSIZE10) << endl;
	cout << "arr29: " << shellsort(arr29, TESTSIZE10) << endl;
	cout << "arr30: " << shellsort(arr30, TESTSIZE10) << endl;

	//strings
	cout << "arr91: " << shellsort(arr91, TESTSIZE91) << endl;
	cout << "arr92: " << shellsort(arr92, TESTSIZE92) << endl;
	cout << "arr93: " << shellsort(arr93, TESTSIZE93) << endl;
	cout << "arr94: " << shellsort(arr94, TESTSIZE94) << endl;
	cout << "arr95: " << shellsort(arr95, TESTSIZE95) << endl;
	cout << "arr96: " << shellsort(arr96, TESTSIZE96) << endl;
	cout << "arr97: " << shellsort(arr97, TESTSIZE97) << endl;

	cout << "array contents of arr2:" << endl;
	for (int i = 0; i < TESTSIZE; i++) {
		cout << arr2[i] << endl;
	}
	cout << "array contents of arr3:" << endl;
	for (int i = 0; i < TESTSIZE; i++) {
		cout << arr3[i] << endl;
	}
	cout << "array contents of arr4:" << endl;
	for (int i = 0; i < TESTSIZE2; i++) {
		cout << arr4[i] << endl;
	}
	cout << "array contents of arr5:" << endl;
	for (int i = 0; i < TESTSIZE2; i++) {
		cout << arr5[i] << endl;
	}
	cout << "array contents of arr6:" << endl;
	for (int i = 0; i < TESTSIZE2; i++) {
		cout << arr6[i] << endl;
	}
	cout << "array contents of arr7:" << endl;
	for (int i = 0; i < TESTSIZE3; i++) {
		cout << arr7[i] << endl;
	}
	cout << "array contents of arr8:" << endl;
	for (int i = 0; i < TESTSIZE3; i++) {
		cout << arr8[i] << endl;
	}
	cout << "array contents of arr9:" << endl;
	for (int i = 0; i < TESTSIZE3; i++) {
		cout << arr9[i] << endl;
	}
	cout << "array contents of arr10:" << endl;
	for (int i = 0; i < TESTSIZE4; i++) {
		cout << arr10[i] << endl;
	}


	cout << "array contents of arr25:" << endl;
	for (int i = 0; i < TESTSIZE9; i++) {
		cout << arr25[i] << endl;
	}
	//cout << "array contents of arr26:" << endl;
	//for (int i = 0; i < TESTSIZE9; i++) {
	//	cout << arr26[i] << endl;
	//}
	//cout << "array contents of arr27:" << endl;
	//for (int i = 0; i < TESTSIZE9; i++) {
	//	cout << arr27[i] << endl;
	//}

	//cout << "array contents of arr92:" << endl;
	//for (int i = 0; i < TESTSIZE92; i++) {
	//	cout << arr92[i] << endl;
	//}
	//cout << "array contents of arr93:" << endl;
	//for (int i = 0; i < TESTSIZE93; i++) {
	//	cout << arr93[i] << endl;
	//}
	//cout << "array contents of arr94:" << endl;
	//for (int i = 0; i < TESTSIZE94; i++) {
	//	cout << arr94[i] << endl;
	//}
	//cout << "array contents of arr95:" << endl;
	//for (int i = 0; i < TESTSIZE95; i++) {
	//	cout << arr95[i] << endl;
	//}
	//cout << "array contents of arr96:" << endl;
	//for (int i = 0; i < TESTSIZE96; i++) {
	//	cout << arr96[i] << endl;
	//}
	//cout << "array contents of arr97:" << endl;
	//for (int i = 0; i < TESTSIZE97; i++) {
	//	cout << arr97[i] << endl;
	//}


	return 0;
}


//*/