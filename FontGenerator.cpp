#include "FontGenerator.h"


void FontGenerator::openFormatFile(string fileName) {
	
	string tempFileName{ fileName };
	
	ifs->open(tempFileName, ios::ios_base::in);

	if (!ifs) cerr << "file open error\n";
	
}

void FontGenerator::allocateFormat() /* source format */ {
	if (!ifs->is_open()) cerr << "open error\n";

	char ch{ 0 };
	string tempCount;

	getline(*ifs, tempCount);      // read word count
	wordCount = stoi(tempCount) + 1; 	//   27 = alphabet(26) + ' '     
	
	/* for target array */
	outputRow = ROW * ROW_RATIO;
	outputCol = COL * COL_RATIO;
	
	originalArray.assign(wordCount, vector<vector<char>>(ROW, vector<char>(COL)));
	enlargeArray.assign(wordCount, vector<vector<char>>(outputRow, vector<char>(outputCol, NULL)));

	/*        read from file        */
	while (!ifs->eof()) {
		for (int alpha = 0; alpha < wordCount; ++alpha) {
			for (int row = 0; row < ROW; ++row) {
				for (int col = 0; col < COL; ++col) {
					ch = 0;
					if (!(*ifs >> ch)) break;
					
					if (ch == '0') ch = ' ';
					if (ch == '1') ch = '@';
					
					originalArray[alpha][row][col] = ch;
				}
			}
		}
	}

	ifs->close();
	
}


void FontGenerator::enlargeText() {
	
	rowCount = originalArray[0].size();
	colCount = originalArray[0][0].size();

		for (int alpha = 0; alpha < wordCount; ++alpha) {
			for (int row = 0; row < rowCount; ++row) {
				int dstRow = row * ROW_RATIO;
				for (int col = 0; col < colCount; ++col) {
					char temp = originalArray[alpha][row][col];
					int dstCol = col * COL_RATIO;

					for (int j = 0; j < ROW_RATIO; ++j) {
						for (int i = 0; i < COL_RATIO; ++i) {
							enlargeArray[alpha][dstRow + j][dstCol + i] = temp;
						}
					}
				}
			}
		}


	//printFormat(originalArray);
	//printFormat(enlargeArray);
}

void FontGenerator::rotateText() {

	rotateArray.assign(wordCount, vector<vector<char>>(outputCol, vector<char>(outputRow, 0)));

	for (int alpha = 0; alpha < wordCount; ++alpha) {
		for (int col = 0; col < outputCol; ++col) {
			int rrow = 0;
			for (int row = outputRow - 1; row >= 0; --row) {
				rotateArray[alpha][col][rrow] = enlargeArray[alpha][row][col];
				++rrow;
			}
		}
	}

}

int toupper(string& cmd) {

	int i = 0;
	int size = cmd.size();
	while(i < size){
		if (!isalpha(cmd[i])) {
			if (cmd[i] != 32 /* if(!space) */) {
				cout << "not alphabet\n";
				return -1;
			}
		}
		cmd[i] = toupper(cmd[i]);
		++i;
	}
	return 1;
}


void FontGenerator::inputFromCmd(string& cmd){
	int cmdSize = cmd.size();
	if(toupper(cmd) < 0) return;
	
	int i = 0;
	while (i < cmdSize) {
		printText(cmd[i]);
		++i;
	}
	
}


void FontGenerator::printText(int input) {
	int alpha{ 0 };
	alpha = input - 65;  // input - 'A'

	if (input == ' ') {
		alpha = wordCount - 1;
	}
	

	for (int row = 0; row < outputCol; ++row) {
		for (int cel = 0; cel < outputRow; ++cel) {
			cout << rotateArray[alpha][row][cel];
		}
		cout << "\n";
	}
	cout << "\n";
}






















void FontGenerator::printFormat(vector<vector<vector<char> > >& inputArray)/* for debug */ {
	int wordCount = inputArray.size();
	int rowCount = inputArray[0].size();
	int colCount = inputArray[0][0].size();

	cout << "alphaCount " << wordCount << endl;
	cout << "rowCount " << rowCount << endl;
	cout << "colCount " << colCount << endl;

	for (int alpha = 0; alpha < wordCount; ++alpha) {
		//cout << "========== " << alpha << " =========\n";
		cout << endl << endl;
		for (int row = 0; row < rowCount; ++row) {
			for (int cel = 0; cel < colCount; ++cel) {
				cout << inputArray[alpha][row][cel];
			}
			cout << endl;
		}

	}
	
}


