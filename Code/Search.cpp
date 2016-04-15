
#include "Search.h"
#include "Const.h"
#include "hash.h"

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

bool isInFringe(std::deque<struct Tree *> &fringe,int * current)
{
	std::deque<struct Tree *>::iterator it = fringe.begin();
	while (it != fringe.end())
	{
		if (   (*it)->data[LM] == current[LM]
			&& (*it)->data[LC] == current[LC]
			&& (*it)->data[LB] == current[LB]
			&& (*it)->data[RM] == current[RM]
			&& (*it)->data[RC] == current[RC]
			&& (*it)->data[RB] == current[RB])

		{
			return true;
		}
		it++;
	}
	return false;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
string BFS(int * Start, int * End, Game * state, std::unordered_map<string,string> &explored)
{
	if (DEBUG)
		std::cout << "BFS: " << std::endl;
	int expanded=0;
	int **ActionResults;
	
	std::deque<struct Tree *> fringe;

	struct Tree * current = new struct Tree;
	current->data[LM] = Start[LM];
	current->data[LC] = Start[LC];
	current->data[LB] = Start[LB];
	current->data[RM] = Start[RM];
	current->data[RC] = Start[RC];
	current->data[RB] = Start[RB];
	current->parent = "ROOT";
	fringe.push_back(current);

	if (!state->Assert(current->data[LM], current->data[LC], current->data[LB], current->data[RM], current->data[RC], current->data[RB]))
		return SSTR(-2);
	if (state->endGame(current->data[LM], current->data[LC], current->data[LB], current->data[RM], current->data[RC], current->data[RB]))
	{
		/* Add current to the explored hash map */
		explored[hashGen(current->data)] = SSTR(0);
		return hashGen(current->data);
	}
	do{
		if (fringe.empty())
		{
			return "Error";
		}
		else{
			if (DEBUG)
				std::cout << "-" <<std::endl; 
		}
		/* Choose the oldest node on the fringe */
		current = fringe.front();
		fringe.pop_front();

		/* Add current to the explored hash map */
		explored[hashGen(current->data)] = current->parent;

		++expanded;
		ActionResults = Action(current->data);
		for (int i = 0; i < 5; i++)
		{
			struct Tree * child = new struct Tree;
			child->data[0] = ActionResults[i][0];
			child->data[1] = ActionResults[i][1];
			child->data[2] = ActionResults[i][2];
			child->data[3] = ActionResults[i][3];
			child->data[4] = ActionResults[i][4];
			child->data[5] = ActionResults[i][5];
			child->parent = hashGen(current->data);

			if (DEBUG)
				std::cout << "ACTION: " << ActionResults[i][LM]<< ActionResults[i][LC]<< ActionResults[i][LB]<< ActionResults[i][RM]<< ActionResults[i][RC]<< ActionResults[i][RB] << std::endl;
			if (state->Assert(ActionResults[i][LM], ActionResults[i][LC], ActionResults[i][LB], ActionResults[i][RM], ActionResults[i][RC], ActionResults[i][RB])
				&& explored.count(hashGen(child->data)) == 0
				&& !isInFringe(fringe, ActionResults[i])
				)
			{
				
				if (state->endGame(ActionResults[i][LM], ActionResults[i][LC], ActionResults[i][LB], ActionResults[i][RM], ActionResults[i][RC], ActionResults[i][RB]))
				{
					explored[hashGen(child->data)] = child->parent;
					return hashGen(child->data);
				}
				fringe.push_back(child);
			}
			else{ 
				if (DEBUG)
					std::cout << "Failed at index: " << i << std::endl;
			}
		}
	}while(true);
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
string DFS(int * Start, int * End, Game * state, std::unordered_map<string, string> &explored)
{
	if (DEBUG)
		std::cout << "DFS: " << std::endl;
	int expanded = 0;
	int **ActionResults;

	std::deque<struct Tree *> fringe;

	struct Tree * current = new struct Tree;
	current->data[LM] = Start[LM];
	current->data[LC] = Start[LC];
	current->data[LB] = Start[LB];
	current->data[RM] = Start[RM];
	current->data[RC] = Start[RC];
	current->data[RB] = Start[RB];
	current->parent = "ROOT";
	fringe.push_back(current);

	if (!state->Assert(current->data[LM], current->data[LC], current->data[LB], current->data[RM], current->data[RC], current->data[RB]))
		return SSTR(-2);
	if (state->endGame(current->data[LM], current->data[LC], current->data[LB], current->data[RM], current->data[RC], current->data[RB]))
	{
		/* Add current to the explored hash map */
		explored[hashGen(current->data)] = SSTR(0);
		return hashGen(current->data);
	}
	do{
		if (fringe.empty())
		{
			return "Error";
		}
		else{
			if (DEBUG)
				std::cout << "-" << std::endl;
		}
		/* Choose the oldest node on the fringe */
		current = fringe.back();
		fringe.pop_back();

		/* Add current to the explored hash map */
		explored[hashGen(current->data)] = current->parent;

		++expanded;
		ActionResults = Action(current->data);
		for (int i = 0; i < 5; i++)
		{
			struct Tree * child = new struct Tree;
			child->data[0] = ActionResults[i][0];
			child->data[1] = ActionResults[i][1];
			child->data[2] = ActionResults[i][2];
			child->data[3] = ActionResults[i][3];
			child->data[4] = ActionResults[i][4];
			child->data[5] = ActionResults[i][5];
			child->parent = hashGen(current->data);

			if (DEBUG)
				std::cout << "ACTION: " << ActionResults[i][LM] << ActionResults[i][LC] << ActionResults[i][LB] << ActionResults[i][RM] << ActionResults[i][RC] << ActionResults[i][RB] << std::endl;
			if (state->Assert(ActionResults[i][LM], ActionResults[i][LC], ActionResults[i][LB], ActionResults[i][RM], ActionResults[i][RC], ActionResults[i][RB])
				&& explored.count(hashGen(child->data)) == 0
				&& !isInFringe(fringe, ActionResults[i])
				)
			{

				if (state->endGame(ActionResults[i][LM], ActionResults[i][LC], ActionResults[i][LB], ActionResults[i][RM], ActionResults[i][RC], ActionResults[i][RB]))
				{
					explored[hashGen(child->data)] = child->parent;
					return hashGen(child->data);
				}
				fringe.push_back(child);
			}
			else{
				if (DEBUG)
					std::cout << "Failed at index: " << i << std::endl;
			}
		}
	} while (true);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
string IDDFS(int * Start, int * End, Game * state, std::unordered_map<string, string> &explored)
{
	if (DEBUG)
		std::cout << "IDDFS: " << std::endl;
	for (int depth = 0;; depth++)
	{
		explored.clear();
		std::cout << "DEPTH: " << depth << std::endl;
		string result = DLS(Start, End, state,explored,depth);		//Figure out clearing explored
		if (result != "Error" && result != "cutOff")				// if we found the answer
		{
			return result;
		}	

	}
	return "Error";
}
string DLS(int * Start, int * End, Game * state, std::unordered_map<string, string> &explored,int depth)
{
	int expanded = 0;
	int **ActionResults;

	std::deque<struct Tree *> fringe;

	struct Tree * current = new struct Tree;
	current->data[LM] = Start[LM];
	current->data[LC] = Start[LC];
	current->data[LB] = Start[LB];
	current->data[RM] = Start[RM];
	current->data[RC] = Start[RC];
	current->data[RB] = Start[RB];
	current->parent = "ROOT";
	
	return RDLS(current,state,explored,depth);
	//
}
string RDLS(struct Tree *current, Game * state, std::unordered_map<string, string> &explored, int depth)
{

	int expanded = 0;
	int **ActionResults;

	string result;
	explored[hashGen(current->data)] = current->parent;

	if (!state->Assert(current->data[LM], current->data[LC], current->data[LB], current->data[RM], current->data[RC], current->data[RB]))
		return SSTR(-2);
	if (state->endGame(current->data[LM], current->data[LC], current->data[LB], current->data[RM], current->data[RC], current->data[RB]))
	{
		/* Add current to the explored hash map */
		return hashGen(current->data);
	}
	if (depth == 0)
	{
		return "cutOff";
	}
	bool cutOff = false;

	++expanded;
	ActionResults = Action(current->data);
	for (int i = 0; i < 5; i++)
	{
		struct Tree * child = new struct Tree;
		child->data[0] = ActionResults[i][0];
		child->data[1] = ActionResults[i][1];
		child->data[2] = ActionResults[i][2];
		child->data[3] = ActionResults[i][3];
		child->data[4] = ActionResults[i][4];
		child->data[5] = ActionResults[i][5];
		child->parent = hashGen(current->data);
		if (DEBUG)
			std::cout << "ACTION: " << ActionResults[i][LM] << ActionResults[i][LC] << ActionResults[i][LB] << ActionResults[i][RM] << ActionResults[i][RC] << ActionResults[i][RB] << std::endl;
		if (state->Assert(ActionResults[i][LM], ActionResults[i][LC], ActionResults[i][LB], ActionResults[i][RM], ActionResults[i][RC], ActionResults[i][RB])
			&& explored.count(hashGen(child->data)) == 0)
		{
			explored[hashGen(child->data)] = child->parent;
			result = RDLS(child,state,explored,depth-1);
			if (result == "cutOff")
			{
				cutOff = true;
			}
			else
			{
				if (result != "Error")
				{
					for (int j = 0; j < 5; j++)
					{
						delete[] ActionResults[j];
					}
					delete[] ActionResults;
					return result;
				}
			}
		}
		else{
			if (DEBUG)
				std::cout << "Failed at index: " << i << std::endl;
		}
	}
	if (cutOff)
	{
		for (int j = 0; j < 5; j++)
		{
			delete[] ActionResults[j];
		}
		delete[] ActionResults;
		return "cutOff";
	}
	for (int j = 0; j < 5; j++)
	{
		delete[] ActionResults[j];
	}
	delete[] ActionResults;
	return "Error";
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
string AS(int * Start, int * End, Game * state, std::unordered_map<string, string> &explored)
{
	if (DEBUG)
		std::cout << "AS: " << std::endl;
	int expanded = 0;
	int **ActionResults;

	std::priority_queue<struct Tree *,std::vector<struct Tree*>,struct PTree> fringe;

	struct Tree * current = new struct Tree;
	current->data[LM] = Start[LM];
	current->data[LC] = Start[LC];
	current->data[LB] = Start[LB];
	current->data[RM] = Start[RM];
	current->data[RC] = Start[RC];
	current->data[RB] = Start[RB];
	current->cost = 0;
	current->priority = heuristic(current->data);
	current->parent = "ROOT";
	fringe.push(current);

	if (!state->Assert(current->data[LM], current->data[LC], current->data[LB], current->data[RM], current->data[RC], current->data[RB]))
		return SSTR(-2);
	if (state->endGame(current->data[LM], current->data[LC], current->data[LB], current->data[RM], current->data[RC], current->data[RB]))
	{
		/* Add current to the explored hash map */
		explored[hashGen(current->data)] = SSTR(0);
		return hashGen(current->data);
	}
	do{
		if (fringe.empty())
		{
			return "Error";
		}
		else{
			if (DEBUG)
				std::cout << "-" << std::endl;
		}
		/* Choose the oldest node on the fringe */
		current = fringe.top();
		fringe.pop();


		/* Add current to the explored hash map */
		explored[hashGen(current->data)] = current->parent;
		if (state->endGame(current->data[LM], current->data[LC], current->data[LB], current->data[RM], current->data[RC], current->data[RB]))
		{
			/* Add current to the explored hash map */
			return hashGen(current->data);
		}
		++expanded;
		ActionResults = Action(current->data);
		for (int i = 0; i < 5; i++)
		{
			struct Tree * child = new struct Tree;
			child->data[0] = ActionResults[i][0];
			child->data[1] = ActionResults[i][1];
			child->data[2] = ActionResults[i][2];
			child->data[3] = ActionResults[i][3];
			child->data[4] = ActionResults[i][4];
			child->data[5] = ActionResults[i][5];
			child->parent = hashGen(current->data);
			child->cost = current->cost + 1;
			child->priority = heuristic(child->data) + child->cost;

			if (DEBUG)
				std::cout << "ACTION: " << ActionResults[i][LM] << ActionResults[i][LC] << ActionResults[i][LB] << ActionResults[i][RM] << ActionResults[i][RC] << ActionResults[i][RB] << std::endl;
			if (state->Assert(ActionResults[i][LM], ActionResults[i][LC], ActionResults[i][LB], ActionResults[i][RM], ActionResults[i][RC], ActionResults[i][RB])
				&& explored.count(hashGen(child->data)) == 0
				)
			{
				fringe.push(child);
			}
			else{
				if (DEBUG)
					std::cout << "Failed at index: " << i << std::endl;
			}
		}
	} while (true);
	return "Error";
}

int heuristic(int * data)
{
	return data[0] + data[1] - 1;
}