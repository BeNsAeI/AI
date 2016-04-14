#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include "ReadFile.h"
#include <fstream>
#include <sstream>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */

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
		cout << "Reading: " << endl;
		string line;
		if (myfileI->is_open())
		{
			while (getline(*myfileI, line))
			{
				cout << line << '\n';
				string pop = line;
				for (int i = 0; i < line.size(); i++)
					pop[i] = '/0';
				int DC = 0;
				for (int i = 0; i < line.size(); i++)
				{
					switch (line[i])
					{
					case'(':
						DC = 0;
						cout << " ";
						break;
					case ')':
						break;
					case ' ':
						break;
					case ',':
						DC++;
						for (int i = 0; i < pop.size(); i++)
							pop[i] = '/0';
						cout << " ";
						break;
					default:
						pop = pop + line[i];
						cout << '^';
						data[DC] = atoi(pop.c_str());
						break;
					}
				}
				cout << endl;
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