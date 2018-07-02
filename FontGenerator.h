#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#define ROW 7
#define COL 6
#define ROW_RATIO 6
#define COL_RATIO 2

using namespace std;

class FontGenerator {

public:
	void openFormatFile();
	void allocateFormat();
	void inputFromCmd(string&);
	void enlargeText();
	void rotateText();
	void printText(int alpha); /* result */

	void printFormat(vector<vector<vector<char> > >&); /* for debug */
private:

	vector<vector<vector<char> > > originalArray; /* from the bitmap.txt */
	vector<vector<vector<char> > > enlargeArray;  
	vector<vector<vector<char> > > rotateArray;  /*  result  */
	ifstream *ifs = new ifstream;

	/*  total words */
	int wordCount{ 0 };

	/* source format */
	int rowCount{ 0 };
	int colCount{ 0 };

	/* result format size */
	int outputRow{ 0 };
	int outputCol{ 0 };

	
};
