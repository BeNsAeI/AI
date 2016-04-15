#include <iostream>
#include "Tree.h"
#include "Print.h"
#include "Const.h"

using namespace std;

void print(std::unordered_map<string, string> &hash, string key, ReadFile &myfile)
{
	string arr[4096];
	int arrC = 0;
	while (key != "ROOT" && key != "Error")
	{
		if (1)
		{
			cout << key << endl;
		}
		if (arrC < 4096)
		{
			arr[arrC] = key;
			arrC++;
		}
		key = hash[key];
	}
	for (arrC; arrC >= 0; arrC--)
		myfile.HandleText(arr[arrC]);
}