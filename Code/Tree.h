#ifndef TREE_H
#define TREE_H
#include <string>
struct Tree
{
	int data[6];
	std::string parent;
};

struct Queue
{
	Tree * Sent;
	Tree * current;
	Queue * Next;
	Queue * Prev;
};

#endif
