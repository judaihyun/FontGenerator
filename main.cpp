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
		// 사용자정의 입력연산자라든지..등등의 방법으로 구간밖검사(ABC~)를 제외한 것에 대한 처리 필요.
		
		
		generator.inputFromCmd(cmd);
		//generator.printFormat();
	
	}
	

	return 0;
}