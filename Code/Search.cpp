
#include "Search.h"
int ** Action(int * current)
{
	int ** Next = new int *[5];
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
int BFS(int * Start, int * End, Game * state, std::unordered_map<int, struct Tree> &explored)
{
	int key=1;
	int expanded=0;
	int **ActionResults;
	
	std::queue<struct Tree> fringe;

	struct Tree current;
	current.data[0] = Start[0];
	current.data[1] = Start[1];
	current.data[2] = Start[2];
	current.data[3] = Start[3];
	current.data[4] = Start[4];
	current.data[5] = Start[5];
	current.parent = 0;
	
	fringe.push(current);
	if (!state->Assert(current.data[LM], current.data[LC], current.data[LB], current.data[RM], current.data[RC], current.data[RB]))
		return -2;
	if (state->endGame(current.data[LM], current.data[LC], current.data[LB], current.data[RM], current.data[RC], current.data[RB]))
	{
		/* Add current to the explored hash map */
		explored[key] = current;
		return key;
	}
	/* TODO add a goal check here */

	do{
		if (fringe.empty())
		{
			return -1;
		}
		/* Choose the oldest node on the fringe */
		current = fringe.front();
		fringe.pop();

		/* Add current to the explored hash map */
		explored[key] = current;
		++key;

		++expanded;
		ActionResults = Action(current.data);
		for (int i = 0; i < 5; i++)
		{
			/* Check if the expanded node is a fail state */
			/* Check if the expanded node is in the explored or fringe*/
			/* Check if the expanded node is the goal node */
			/* If neither of the above, add it to the fringe */
		}
	}while(true);
}
