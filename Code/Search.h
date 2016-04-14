#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <queue>
#include "Game.h"
#include "Tree.h"
#include "ReadFile.h"
#include <unordered_map>


#define LM 0
#define LC 1
#define LB 2
#define RM 3
#define RC 4
#define RB 5

// (LM,LC,LB,RM,RC,RB)
int ** Action(int * current, Game * state);
int BFS(int * Start, int * End, Game * state, std::unordered_map<int, struct Tree> &explored);

/*
struct Tree * DFS(int * Start, int * End, Game * state)
{
	struct Tree * final = new struct Tree;
	struct Tree * current = new struct Tree;
	current->Parent = NULL;
	current->data[0] = Start[0];
	current->data[1] = Start[1];
	current->data[2] = Start[2];
	current->data[3] = Start[3];
	current->data[4] = Start[4];
	current->data[5] = Start[5];
	std::queue<struct Tree *> next;

	return final;
}
*/

#endif
