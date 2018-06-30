#include "FontGenerator.h"

using namespace std;

void FontGenerator::openFormatFile() {
	
	string tempFileName{ "bitmap.txt" };
	//cout << "FomatFilePath : "; cin >> tempFileName;
	ifs->open(tempFileName, ios::ios_base::in);

	if (!ifs) cerr << "file open error\n";
	
}

void FontGenerator::allocateFormat() {
	if (ifs->is_open()) cout << "File Open\n\n";
	//char ch;
	string tempCount;
	getline(*ifs, tempCount);

	alphaCount = stoi(tempCount);

	char arr[26][7][6]{ -1, };
	
	while (!ifs->eof()) {

		for (int al = 0; al < 26; ++al) {
			for (int row = 0; row < 7; ++row) {
				for (int cel = 0; cel < 6; ++cel) {
					char ch;
					if (!(*ifs >> ch)) break; // { cout << "not good\n"; break; }
					//cout << ch << " ";

					arr[al][row][cel] = ch;
					//cout << "arr[" << row << "][" << cel << "]:" << arr[row][cel] << " ";
				}
				//cout << "ROW: " << row <<endl;
				//cout << endl;
			}
		}
	}
	
	cout << endl;

//	cout << "count : " << alphaCount;
	
	for (int al = 0; al < 26; ++al) {
		cout << "========== " << al << " =========\n";
		for (int row = 0; row < 7; ++row) {
			for (int cel = 0; cel < 6; ++cel) {
				cout << arr[al][row][cel];
				//cout << "arr[" << row << "][" << cel << "]:" << arr[al][row][cel] << " ";
			}
			cout << endl;
		}
	
	}
	

	//alphaArray = new char[alphaCount];
}