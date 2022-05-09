#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class PGM {
private:
	int** board;
	int numrows;
	int numcols;
	int max;
	string magic;
	string comment;
	void readInput(ifstream& infile);
public:
	PGM(ifstream& infile);
	~PGM();
	template<class T>
	PGM& operator()(T fun, int deg);
	void saveToPGM(const char* fn);
};

PGM::PGM(ifstream& infile) : board(nullptr), numrows(0), numcols(0), max(0), magic(""), comment("") {
	readInput(infile);
}

PGM::~PGM() {
	for (int i = 0; i < numrows; i++) {
		delete[] board[i];
	}
	delete[] board;
}

void PGM::readInput(ifstream& infile) {
	getline(infile, magic, '\n');
	/*if (magic != "P1" && magic != "P2" && magic != "P3" && magic != "P4" && magic != "P5" && magic != "P6") {
		throw("File does not appear to be in PGM format");
	}*/
	getline(infile, comment, '\n');
	infile >> numcols;
	infile >> numrows;
	infile >> max;

	board = new int* [numrows];
	for (int i = 0; i < numrows; i++) {
		board[i] = new int[numcols];
		for (int j = 0; j < numcols; j++) {
			infile >> board[i][j];
		}
	}
}

template<class T>
PGM& PGM::operator()(T fun, int deg) {
	for (int i = 0; i < numrows; i++) {
		for (int j = 0; j < numcols; j++) {
			fun(board[i][j], deg);
		}
	}
	return *this;
}

void PGM::saveToPGM(const char* fn) {
	cout << "Saving PGM object to ASCII file..." << endl;
	ofstream outfile(fn);
	
	outfile << magic << '\n';
	outfile << comment << '\n';
	outfile << numcols << ' ';
	outfile << numrows << '\n';
	outfile << max << '\n';
	for (int i = 0; i < numrows; i++) {
		for (int j = 0; j < numcols; j++) {
			outfile << board[i][j] << ' ';
		}
		outfile << '\n';
	}
	outfile.close();
}


class DarkenPGM {
public:
	void operator()(int& x, int deg);
};

void DarkenPGM::operator()(int& x, int deg) {
	[&x, deg] {  //should deg be via reference? ...what if the for loop was inside of DarkenPGM::operator(), would &deg be better?
		x = x - deg;
		if (x < 0)
			x = 0;
	}();
}

int main() {
	ifstream file1("image1.pgm", ios::in);
	
	DarkenPGM d;
	PGM* image1 = new PGM(file1);

	(*image1)(d, 20);
	image1->saveToPGM("image1_darkened.pgm");


	return 0;
}

