#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include "ReadFile.h"
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h> 
#include "Const.h"

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
		if (DEBUG)
			cout << "Setting up a file to append to..." << endl;
		myfileO = new std::ofstream();
		myfileO->open(PathIn.c_str(), std::ios::app);
		break;
	case (1):
		if (DEBUG)
			cout << "Setting up a file to write to..." << endl;
		myfileO = new std::ofstream();
		myfileO->open(PathIn.c_str());
		break;
	default:
		if (DEBUG)
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
		(*myfileO) << "(";
		for (int i = 0; i < 6; i++)
		{
			(*myfileO) << data[i];
			if (i < 5)
				(*myfileO) << ",";
		}
		(*myfileO) << ")\n";
		break;
	default:
		if (DEBUG)
			cout << "Reading: " << endl;
		string line;
		if (myfileI->is_open())
		{
			int DC = 0;
			while (getline(*myfileI, line))
			{
				if (DEBUG)
					cout << line << '\n';
				string pop = line;
				for (int i = 0; i < line.size(); i++)
					pop[i] = '0';
				for (int i = 0; i < line.size(); i++)
				{
					switch (line[i])
					{
					case ' ':
						break;
					case ',':
						DC++;
						for (int i = 0; i < pop.size(); i++)
							pop[i] = '0';
						if (DEBUG)
							cout << " ";
						break;
					default:
						pop = pop + line[i];
						if (DEBUG)
							cout << '^';
						data[DC] = atoi(pop.c_str());
						break;
					}
				}
				if (DEBUG)
					cout << endl;
				DC++;
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