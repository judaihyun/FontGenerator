#include <iostream>
#include "FontGenerator.h"


int main() {

	string cmd{ "" };
	FontGenerator generator;

	generator.openFormatFile("bitmap.txt");
	generator.allocateFormat();
	generator.enlargeText();
	generator.rotateText();

	while (1) {
		cmd = "";
		cout << ">>> ";
		getline(cin, cmd);
		
		generator.inputFromCmd(cmd);
	
	}
	
	return 0;
}