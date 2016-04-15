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
int BFS(int * Start, int * End, Game * state, std::unordered_map<int, struct Tree *> &explored);
int DFS(int * Start, int * End, Game * state, std::unordered_map<int, struct Tree *> &explored);
#endif
