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
	//Checking for arguments
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
			//Outputting the arguments
			cout << "Input 1: " << argv[1] << endl;
			cout << "Input 2: " << argv[2] << endl;
			cout << "Mode: " << argv[3] << endl;
			cout << "Output 1: " << argv[4] << endl;
		}
	}
	// File handle
	ReadFile myfileIn1(argv[1], READ);
	ReadFile myfileIn2(argv[2], READ);
	ReadFile myfileOut(argv[4], APPEND);

	//Populating the starting value from argument 1
	int start[6];
	myfileIn1.Handle(start);

	//Populating ending state from argument 2
	int end[6];
	myfileIn2.Handle(end);

	//Creating the game state
	Game * state = new Game(end[0], end[1], end[2], end[3], end[4], end[5]);

	//Creating the hash table and key
	std::unordered_map<string,string> hash;
	string Key;

	//running the search
	if (argv[3][0] == 'b' || argv[3][0] == 'B')
		Key = BFS(start, end, state, hash);
	if (argv[3][0] == 'd' || argv[3][0] == 'D')
		Key = DFS(start, end, state, hash);
	if (argv[3][0] == 'i' || argv[3][0] == 'I')
		Key = IDDFS(start, end, state, hash);
	if (argv[3][0] == 'a' || argv[3][0] == 'A')
		Key = AS(start, end, state, hash);

	//Outpu
	//Printing the output
	print(hash,Key);
	return 0;
}
