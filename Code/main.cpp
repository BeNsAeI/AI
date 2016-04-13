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
#include "Game.h"

#define DEBUG 0

using std::cout;
using std::cin;
using std::endl;
using std::string;

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
	Game * state = new Game(3, 3, 1, 0, 0, 0);
	if (DEBUG)
	{
		cout << "Status 1(Pass):" << state->Assert(0, 0, 0, 3, 3, 1) << endl;
		cout << "Status 2(Pass):" << state->Assert(3, 3, 1, 0, 0, 0) << endl;
		cout << "Status 3(Fail):" << state->Assert(0, 0, 0, 3, 3, 0) << endl;
		cout << "Status 1(Fail):" << state->Assert(1, 2, 0, 2, 1, 0) << endl;
	}	
	return 0;
}