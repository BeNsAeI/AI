#ifndef TREE_H
#define TREE_H
struct Tree
{
	int data[6];
	Tree * Parent;
};

struct Queue
{
	Tree * Sent;
	Tree * current;
	Queue * Next;
	Queue * Prev;
};
struct Data
{
	int LM;
	int LC;
	int LB;

	int RM;
	int RC;
	int RB;
};

#endif