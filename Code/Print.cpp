#include <iostream>
#include "Tree.h"
#include "Print.h"
#include "Const.h"

using namespace std;

void print(std::unordered_map<int, struct Tree *> &hash, int key)
{
	int ** data = new int* [key];
	while (key != 0)
	{
		if (DEBUG)
		{
			cout << key << endl;
			cout << (hash[key])->data[0] << ' ';
			cout << (hash[key])->data[1] << ' ';
			cout << (hash[key])->data[2] << ' ';
			cout << (hash[key])->data[3] << ' ';
			cout << (hash[key])->data[4] << ' ';
			cout << (hash[key])->data[5] << ' ';
			cout << endl;
		}
		key = (hash[key])->parent;
	}
}