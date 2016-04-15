#include <iostream>
#include "Tree.h"
#include "Print.h"
#include "Const.h"

using namespace std;

void print(std::unordered_map<string,string> &hash, string key)
{
	while (key != "ROOT" && key != "Error")
	{
		if (DEBUG)
		{
			cout << key << endl;
		}
		key = hash[key];
	}
}