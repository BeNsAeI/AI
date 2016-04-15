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
#include "Const.h"

using std::string;

// (LM,LC,LB,RM,RC,RB)
int ** Action(int * current, Game * state);
string BFS(int * Start, int * End, Game * state, std::unordered_map<string, string> &explored);
string DFS(int * Start, int * End, Game * state, std::unordered_map<string, string> &explored);
string IDDFS(int * Start, int * End, Game * state, std::unordered_map<string, string> &explored);
string DLS(int * Start, int * End, Game * state, std::unordered_map<string, string> &explored,int depth);
string RDLS(struct Tree *current, Game * state, std::unordered_map<string, string> &explored, int depth);
string AS(int * Start, int * End, Game * state, std::unordered_map<string, string> &explored);
int heuristic(int * data);
#endif
