#ifndef TREE_H
#define TREE_H
#include <string>
#include "Search.h"

struct Tree
{
	int data[6];
	std::string parent;
	int cost;
	int priority;
};

struct PTree
{
	bool operator() (const struct Tree * lhs, const struct Tree * rhs) const
	{
		return lhs->priority < rhs->priority;
	}
};
#endif
