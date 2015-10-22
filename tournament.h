//Combat
//CS 162 - Fall 2014
//author: Boone Neligan
//
//Tournament header file

#include "creature2.h"

#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::queue;
using std::stack;
using std::vector;
using std::to_string;

struct Results {
	int points;
	int team;
	string name;
};

//takes pointers to two creature objects and pits them against eachother in battle
//returns an int value indicating which team the winning creature is on
int clash(Creature *one, Creature *two);

//takes a long long value (b/c to_string() function would only implement with a long long)
//and a char value that is incremented each time the function's while loop runs
//returns a pointer to a new creature object
Creature* chooseCreature(long long player, char name_mod);

//prompts user for team sizes and returns this as an int value
int setTeamSize();

//allows user to fill their team with creature objects
//takes a queue to hold the team, an int for team size, and an int to indicate the player choosing
//queue is passed by reference, so nothing is returned
void chooseTeam(queue<Creature*> &team, int size, int player);

//takes the winner's queue (because the loser's will be empty) and the dead pile stack
//produces final results based on the values after the tournament has run 
void results(queue<Creature*> &winner, stack<Creature*> &vqd);
