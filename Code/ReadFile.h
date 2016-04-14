#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <fstream>

#define READ 0
#define WRITE 1
#define APPEND 2

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