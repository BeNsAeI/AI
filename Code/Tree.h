struct Tree
{
	int data[6];
	Tree ** branch;
};

struct Queue
{
	int data[6];
	Queue * Sent;
	Queue * Next;
	Queue * Prev;
	Queue * Last;
	Queue Add(Queue NextNode)
	{

	}
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