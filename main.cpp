#include <iostream>
#include "FontGenerator.h"

#define MAX_CMD 1000

void commandline() {
		
}

int main() {

	string cmd;
	FontGenerator generator;

	generator.openFormatFile();
	generator.allocateFormat();
	generator.enlargeText();
	generator.rotateText();

	while (1) {
		

		cout << ">>> ";
		getline(cin, cmd);
		
	//	fgets(cmd, MAX_CMD, stdin);
		// ��������� �Է¿����ڶ����..����� ������� �����۰˻�(ABC~)�� ������ �Ϳ� ���� ó�� �ʿ�.
		
		
		generator.inputFromCmd(cmd);
		//generator.printFormat();
	
	}
	

	return 0;
}