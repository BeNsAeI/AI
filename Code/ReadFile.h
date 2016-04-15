#ifndef READFILE_H
#define READFILE_H

#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <fstream>
#include "Const.h"

using std::string;

class ReadFile{
public:
	ReadFile(std::string PathIn, char mode);
	int Handle(int * data);
	~ReadFile();
private:
	std::ofstream * myfileO;
	std::ifstream * myfileI;
	int Mode;
};

#endif