#ifndef GAME_H
#define GAME_H

class Game{
public:
	Game(int FLM, int FLC, int FLB, int FRM, int FRC, int FRB);
	bool Assert(int LM, int LC, int LB, int RM, int RC, int RB);
	bool endGame(int LM, int LC, int LB, int RM, int RC, int RB);
	int L[3];
	int R[3];
	int FL[3];
	int FR[3];
};
#endif