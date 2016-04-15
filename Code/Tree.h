#ifndef TREE_H
#define TREE_H

struct Tree
{
	int data[6];
	int parent;
};

struct Queue
{
	Tree * Sent;
	Tree * current;
	Queue * Next;
	Queue * Prev;
};

#endif
