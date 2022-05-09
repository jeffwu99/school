#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void applyGrayScale(ifstream& inData, ofstream& outData) {
	char whitespace;
	string chars;
	string check = "#";
	int max;
	int set = 3;
	int r, g, b;
	int width, height;
	double grayScale;
	string errorMessage = "Not .ppm format";
	cout << "Applying the grayscale filter to image..." << endl;
	
	getline(inData, chars, '\n');
	if (chars != "P1" && chars != "P2" && chars != "P3" && chars != "P4" && chars != "P5" && chars != "P6") {
		throw runtime_error(errorMessage);
	}
	//getting header info
	cout << "Header information from file:" << endl;
	//version
	cout << "Version : ";
	cout << chars << endl;
	outData << chars << '\n';

	//getting comment
	inData >> chars; 	//check if there is a comment
	if (chars == "#") {
		cout << "Comment : # ";
		outData << chars;
		getline(inData, chars, '\n');
		cout << chars << endl;
		outData << chars << '\n';

		inData >> width;
	}
	else { // chars currently contains the width
		width = stoi(chars);
	}

	//getting width and height
	cout << "Image has " << width;
	outData << width << ' ';
	inData >> height;
	cout << " columns and " << height << " rows" << endl;
	outData << height << '\n';

	//getting rgb max
	inData >> max; //has either read rgb max or the first pixel's r
	inData.get(whitespace);
	if (whitespace == '\n') { //max has rgbmax
		cout << "Max color: " << max << endl;
		outData << max << '\n';

		inData >> r;
		inData >> g;
		inData >> b;
		grayScale = (0.3 * r) + (0.59 * g) + (0.11 * b);
		outData << grayScale << ' ';
		outData << grayScale << ' ';
		outData << grayScale << ' ';

	}
	else {//max has first pixel's r 
		r = max;
		inData >> g;
		inData >> b;
		grayScale = (0.3 * r) + (0.59 * g) + (0.11 * b);
		outData << grayScale << ' ';
		outData << grayScale << ' ';
		outData << grayScale << ' ';
	}
	//getting rest of rgb
	int count = width * height;
	for (int i = 1; i < count; i++) {
		inData >> r;
		inData >> g;
		inData >> b;
		grayScale = (0.3 * r) + (0.59 * g) + (0.11 * b);
		outData << grayScale << ' ';
		outData << grayScale << ' ';
		outData << grayScale << ' ';
	}
}



int main() {
	const char* infile = "Ferrari.ppm";
	const char* outfile = "Ferrari_GS.ppm";
	ifstream dataFile(infile);
	ofstream grayFile(outfile);

	if (!dataFile) {
		cout << "Cannot open '" << infile << "'" << endl;
		return -1;
	}

	try {
		applyGrayScale(dataFile, grayFile);
		cout << "Finished processing image..." << endl;
		dataFile.close();
		grayFile.close();
	}
	catch (runtime_error(errorMessage)) {
		cerr << "Error: file does not appear to be in correct ppm format. Grayscale cannot be applied." << endl;
	}
	catch (ifstream::failure err) {
		cerr << "Exception reading/writing/closing files";
	}
	return 0;
}

