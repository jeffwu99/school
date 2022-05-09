#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class PGM {
private:
	void readInput(ifstream& infile);
protected:
	int** board;
	int numrows;
	int numcols;
	int max;
	string magic;
	string comment;
public:
	PGM() : board(nullptr), numrows(0), numcols(0), max(0), magic(""), comment("") {
		cout << "Default constructor being called" << endl;
	}
	PGM(ifstream& infile) : board(nullptr), numrows(0), numcols(0), max(0), magic(""), comment("") {
		cout << "One-arg PGM constructor called..." << endl;
	}
	virtual ~PGM() {
		cout << "Destroying PGM object..." << endl;
	};

	virtual PGM& operator<<(int deg) = 0;
	class exceptionClass {
	private:
		const char* err;
	public:
		exceptionClass(const char* err) : err(err) {}
		const char* returnError() {
			return this->err;
		}
	};
	friend void saveToPGM(const PGM& f, const char* fn);
};

class DarkenPGM : public PGM {
private: 
	void readInput(ifstream& infile) {
		getline(infile, magic, '\n');
		if (magic != "P1" && magic != "P2" && magic != "P3" && magic != "P4" && magic != "P5" && magic != "P6") {
			throw(exceptionClass("File does not appear to be in PGM format"));
		}
		getline(infile, comment, '\n');
		infile >> numcols;
		infile >> numrows;
		infile >> max;
		do {
			if (infile.fail()) {
				throw(exceptionClass("Error reading contents of first image."));
			}
			board = new int* [numrows];  //pointer to heights
			for (int i = 0; i < numrows; i++) {
				board[i] = new int[numcols];
				for (int j = 0; j < numcols; j++) {
					infile >> board[i][j];
				}
			}
		} while (infile.fail());
	}
public:
	DarkenPGM() {};
	DarkenPGM(ifstream& infile): PGM(infile) {
		cout << "One-arg DarkenPGM constructor called..." << endl;
		readInput(infile);
	}
	virtual ~DarkenPGM() {
		cout << "DarkenPGM destructor called..." << endl;
		for (int i = 0; i < numrows; i++) {
			delete[] board[i];
		}
		delete[] board;
	}
	virtual PGM& operator<<(int deg) final {
		for (int i = 0; i < numrows; i++) {
			for (int j = 0; j < numcols; j++) {
				board[i][j] = board[i][j] - deg;
				if (board[i][j] < 0) {
					board[i][j] = 0;
				}
			}
		}

		return *this;
	}
};

class TshirtPGM : public PGM {
	void readInput(ifstream& infile) {
		getline(infile, magic, '\n');
		if (magic != "P1" && magic != "P2" && magic != "P3" && magic != "P4" && magic != "P5" && magic != "P6") {
			throw(exceptionClass("File does not appear to be in PGM format"));
		}
		getline(infile, comment, '\n');
		infile >> numcols;
		infile >> numrows;
		infile >> max;
		do {
			if (infile.fail()) {
				throw(exceptionClass("Error reading contents of image 2."));
			}
			board = new int* [numrows];  //pointer to heights
			for (int i = 0; i < numrows; i++) {
				board[i] = new int[numcols];
				for (int j = 0; j < numcols; j++) {
					infile >> board[i][j];
				}
			}
		} while (infile.fail());
	}
public:
	TshirtPGM() {};
	TshirtPGM(ifstream& infile) : PGM(infile) {
		cout << "One-arg DarkenPGM constructor called..." << endl;
		readInput(infile);
	}
	virtual ~TshirtPGM() {
		cout << "TshirtPGM destructor called..." << endl;
		for (int i = 0; i < numrows; i++) {
			delete[] board[i];
		}
		delete[] board;
	}
	virtual PGM& operator<<(int deg) final {
		int threshold = max / deg;
		for (int i = 0; i < numrows; i++) {
			for (int j = 0; j < numcols; j++) {
				if (board[i][j] > threshold) {
					board[i][j] = max;
				}
				else {
					board[i][j] = 0;
				}
			}
		}
		return *this;
	}
};

void saveToPGM(const PGM& f, const char* fn) {
	cout << "Saving PGM object to ASCII file..." << endl;
	ofstream outfile(fn);
	do {
		if (outfile.fail()) {
			throw(PGM::exceptionClass("Error in output file. Data or format may be incorrect or file could not close properly."));
		}
		outfile << f.magic << '\n';
		outfile << f.comment << '\n';
		outfile << f.numcols << ' ';
		outfile << f.numrows << '\n';
		outfile << f.max << '\n';

		for (int i = 0; i < f.numrows; i++) {
			for (int j = 0; j < f.numcols; j++) {
				outfile << f.board[i][j] << ' ';
			}
			outfile << '\n';
		}
		outfile.close();
	} while (outfile.fail());
}


int main() {

	ifstream file1("image1.pgm", ios::in);
	ifstream file2("image2.pgm", ios::in);
	try {
		DarkenPGM image1(file1);
		TshirtPGM image2(file2);
		// Close the two input image files
		file1.close();
		file2.close();

		// Declare an integer array for the amount of change
		int degree[2] = { 10, 3 };

		// Declare an array of pointers to the objects
		PGM* ptrToPGM[2] = { &image1, &image2 };

		// Use overridden virtual function for each object
		for (int i = 0; i < 2; i++)
			(*(ptrToPGM[i])) << degree[i];

		// Save modified images to file.
		saveToPGM(image1, "image1_mod.pgm");
		saveToPGM(image2, "image2_mod.pgm");
	}
	catch (PGM::exceptionClass e)
	{
		cout << e.returnError() << endl;
		return 0;
	}


	return 0;
}