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
#include <unordered_map>
#include "Game.h"
#include "ReadFile.h"
#include "Search.h"
#include "Tree.h"
#include "Print.h"
#include "Const.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::queue;

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
		{
			cout << "Input 1: " << argv[1] << endl;
			cout << "Input 2: " << argv[2] << endl;
			cout << "Mode: " << argv[3] << endl;
			cout << "Output 1: " << argv[4] << endl;
		}
	}
	int input[6];
	
	ReadFile myfileIn1(argv[1], READ);
	ReadFile myfileIn2(argv[2], READ);
	ReadFile myfileOut(argv[4], APPEND);
	int start[6];
	myfileIn1.Handle(start);
	if (DEBUG)
		cout << "start[0],[1],[2],[3],[4],[5] are: " << start[0] << ", " << start[1] << ", " << start[2] << ", " << start[3] << ", " << start[4] << ", " << start[5] << endl;
	int end[6];
	myfileIn2.Handle(end);
	if (DEBUG)
		cout << "end[0],[1],[2],[3],[4],[5] are: " << end[0] << ", " << end[1] << ", " << end[2] << ", " << end[3] << ", " << end[4] << ", " << end[5] << endl;
	Game * state = new Game(end[0], end[1], end[2], end[3], end[4], end[5]);
	std::unordered_map<int, struct Tree *> hash;
	int Key = BFS(start, end, state, hash);
	if (DEBUG)
		cout << "Hash is: " << Key << endl;
	print(hash,Key);
	return 0;
}
