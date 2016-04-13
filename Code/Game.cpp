#include <iostream>
#include "Game.h"

Game::Game(int FLM, int FLC, int FLB, int FRM, int FRC, int FRB)
{
	FL[0] = FLM;
	FL[1] = FLC;
	FL[2] = FLB;

	FR[0] = FRM;
	FR[1] = FRC;
	FR[2] = FRB;
}
bool Game::Assert(int LM, int LC, int LB, int RM, int RC, int RB)
{
	if (LM < LC || RM < RC || LB == RB)
	{
		return false;
	}
	else
		return true;
}
bool Game::endGame(int LM, int LC, int LB, int RM, int RC, int RB)
{
	if (LM == FL[0] &&
		LC == FL[1] &&
		LB == FL[2] &&
		RM == FR[0] &&
		RC == FR[1] &&
		RB == FR[2])
	{
		return true;
	}
	else
		return false;
}