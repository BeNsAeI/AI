/*****************************************************
**				CS331 (Spring 2016)					**
**		Introduction to Artificial Intelligence		**
**			Programming Assignment #1				**
**		  Uninformed and Informed Search			**
**		Name: Behnam Saeedi & Connor Yates			**
**				   Onid: Saeedib					**
**				   Onid: yatesco				    **
**				Out: April 1, 2016					**
**			Due: April 15, 2016 at 17:00:00			**
**		Type: Team Assignment (Groups of 2 max)		**
*****************************************************/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <queue>
#include "Game.h"
#include "Tree.h"
#include "ReadFile.h"

#define DEBUG 1

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::queue;

//Print
//readfile
//Uninformed
//Informed
//breadth-firs
//depth-first
//iterative deepening depth-first
//A-star

int main(int argc, char ** argv)
{
	if (argc < 5)
	{
		cout << "missing argument" << endl;
		cout << "./<executable> < initial state file > < goal state file > < mode > < output file >" << endl;
		return 1;
	}
	else
	{
		if (DEBUG)
			cout << argv[4] << endl;
	}
	int input[6];
	
	if (DEBUG)
	{
		Game * state = new Game(3, 3, 1, 0, 0, 0);
		cout << "Status 1(Pass):" << state->Assert(0, 0, 0, 3, 3, 1) << endl;
		cout << "Status 2(Pass):" << state->Assert(3, 3, 1, 0, 0, 0) << endl;
		cout << "Status 3(Fail):" << state->Assert(0, 0, 0, 3, 3, 0) << endl;
		cout << "Status 1(Fail):" << state->Assert(1, 2, 0, 2, 1, 0) << endl;

		cout << "Allocating memory..." << endl;
		struct Tree * myTree = new struct Tree;
		struct Tree * leftTree = new struct Tree;
		struct Tree * rightTree = new struct Tree;

		cout << "Creating the branches..." << endl;
		myTree->branch = new Tree*[2];

		cout << "Populating Data..." << endl;
		myTree->data[0] = 1;
		leftTree->data[0] = 2;
		rightTree->data[0] = 3;
		myTree->branch[0] = leftTree;
		myTree->branch[1] = rightTree;

		cout << "Values are: " << myTree->data[0] << ", " << myTree->branch[0]->data[0] << ", " << myTree->branch[1]->data[0] << endl;

		cout << "Returning memory to heap..." << endl;
		delete leftTree;
		delete rightTree;
		delete myTree;

		cout << "Handling pointer ..." << endl;
		myTree = NULL;
		leftTree = NULL;
		rightTree = NULL;
		cout << "End of test ..." << endl;

		queue<struct Data> List;
		struct Data tmp;
		tmp.LM = 3;
		tmp.LC = 3;
		tmp.LB = 1;
		tmp.RM = 0;
		tmp.RC = 0;
		tmp.RB = 0;

		List.push(tmp);

		cout << "Value: " << (List.front()).LM << endl;

		ReadFile myfileIn(argv[1],READ);
		ReadFile myfileOut(argv[4], APPEND);
		int data[6];
		myfileIn.Handle(data);
		myfileOut.Handle(data);

	}

	return 0;
}