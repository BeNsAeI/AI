#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include "ReadFile.h"
#include <fstream>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

ReadFile::ReadFile(std::string PathIn,char mode)
{
	Mode = mode;
	switch (mode)
	{
	case (2) :
		cout << "Setting up a file to append to..." << endl;
		myfileO = new std::ofstream();
		myfileO->open(PathIn.c_str(), std::ios::app);
		break;
	case (1):
		cout << "Setting up a file to write to..." << endl;
		myfileO = new std::ofstream();
		myfileO->open(PathIn.c_str());
		break;
	default:
		cout << "Setting up a file to read from..." << endl;
		myfileI = new std::ifstream(PathIn.c_str());
		break;
	}
}
int ReadFile::Handle(int * data)
{
	switch (Mode)
	{
	case 2:
	case 1:
		(*myfileO) << "Writing this to a file.\n";
		break;
	default:
		cout << "Reading: " << endl;
		string line;
		if (myfileI->is_open())
		{
			while (getline(*myfileI, line))
			{
				cout << line << '\n';
			}
			myfileI->close();
		}
		else
		{
			cout << "No such a file found." << endl;
		}
		break;
	}
	return 0;
}
ReadFile::~ReadFile()
{
	switch (Mode)
	{
	case 2:
	case 1:
		myfileO->close();
		delete myfileO;
		break;
	default:
		delete myfileI;
		break;
	}
}
int ReadFile::StringToInt(string line)
{
	return 0;
}