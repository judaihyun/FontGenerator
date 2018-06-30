#pragma once

#include <iostream>
#include "MainHeader.h"



class FontGenerator {

public:
	~FontGenerator() { delete[]alphaArray; }
	void openFormatFile();
	void allocateFormat();
private:
	std::ifstream *ifs = new std::ifstream;
	char *alphaArray = nullptr;
	int alphaCount{ 0 };
};
