#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
#include <unordered_map>
#include "Game.h"
#include "ReadFile.h"
#include "Search.h"
#include "Tree.h"
#include "Print.h"
#include "Const.h"

using std::string;

string hashGen(int * data)
{
	string str = "";
	for (int i = 0; i < 6; i++)
	{
		str = str + SSTR(data[i]);
		if (i < 5)
			str = str + ",";
	}
	return str;
}

#endif