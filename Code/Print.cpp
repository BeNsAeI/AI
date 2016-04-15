#include <iostream>
#include "Print.h"
#define DEBUG 0
using namespace std;

void print(std::unordered_map<int, struct Tree *> &hash, int key)
{
	while (key != 0)
	{
		if (DEBUG)
			cout << key << endl;
		cout << (hash[key])->data[0] << ' ';
		cout << (hash[key])->data[1] << ' ';
		cout << (hash[key])->data[2] << ' ';
		cout << (hash[key])->data[3] << ' ';
		cout << (hash[key])->data[4] << ' ';
		cout << (hash[key])->data[5] << ' ';
		cout << endl;
		key = (hash[key])->parent;
	}
}