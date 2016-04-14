#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <queue>
#include "Game.h"
#include "ReadFile.h"

#define LM 0
#define LC 1
#define LB 2
#define RM 3
#define RC 4
#define RB 5

// (LM,LC,LB,RM,RC,RB)
int ** Action(int * current, Game * state)
{
	int ** Next;
	for (int i = 0; i < 5; i++)
		Next[i] = new int[6];
	if (current[LB] == 1 && current[RB] == 0)
	{
		Next[0][LM] = current[LM] - 1;
		Next[0][LC] = current[LC];
		Next[0][LB] = 0;
		Next[0][RM] = current[RM] + 1;
		Next[0][RC] = current[RC];
		Next[0][RB] = 1;

		Next[1][LM] = current[LM] - 2;
		Next[1][LC] = current[LC];
		Next[1][LB] = 0;
		Next[1][RM] = current[RM] + 2;
		Next[1][RC] = current[RC];
		Next[1][RB] = 1;

		Next[2][LM] = current[LM];
		Next[2][LC] = current[LC] - 1;
		Next[2][LB] = 0;
		Next[2][RM] = current[RM];
		Next[2][RC] = current[RC] + 1;
		Next[2][RB] = 1;

		Next[3][LM] = current[LM] - 1;
		Next[3][LC] = current[LC] - 1;
		Next[3][LB] = 0;
		Next[3][RM] = current[RM] + 1;
		Next[3][RC] = current[RC] + 1;
		Next[3][RB] = 1;

		Next[4][LM] = current[LM];
		Next[4][LC] = current[LC] - 2;
		Next[4][LB] = 0;
		Next[4][RM] = current[RM];
		Next[4][RC] = current[RC] + 2;
		Next[4][RB] = 1;
	}
	if (current[LB] == 0 && current[RB] == 1)
	{
		Next[0][LM] = current[LM] + 1;
		Next[0][LC] = current[LC];
		Next[0][LB] = 1;
		Next[0][RM] = current[RM] - 1;
		Next[0][RC] = current[RC];
		Next[0][RB] = 0;

		Next[1][LM] = current[LM] + 2;
		Next[1][LC] = current[LC];
		Next[1][LB] = 1;
		Next[1][RM] = current[RM] - 2;
		Next[1][RC] = current[RC];
		Next[1][RB] = 0;

		Next[2][LM] = current[LM];
		Next[2][LC] = current[LC] + 1;
		Next[2][LB] = 1;
		Next[2][RM] = current[RM];
		Next[2][RC] = current[RC] - 1;
		Next[2][RB] = 0;

		Next[3][LM] = current[LM] + 1;
		Next[3][LC] = current[LC] + 1;
		Next[3][LB] = 1;
		Next[3][RM] = current[RM] - 1;
		Next[3][RC] = current[RC] - 1;
		Next[3][RB] = 0;

		Next[4][LM] = current[LM];
		Next[4][LC] = current[LC] + 2;
		Next[4][LB] = 1;
		Next[4][RM] = current[RM];
		Next[4][RC] = current[RC] - 2;
		Next[4][RB] = 0;
	}
	return Next;
}

#endif
