//Combat
//author: Boone Neligan
//
//Creature class and subclasses - header file

#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

struct Dice {
	int num;
	int sides;
};

class Creature {
protected:
	Dice a_dice;
	Dice d_dice;
	int armor;
	int strength;
	int tourney_points;
	int creature_class;
	int team;
	string name;
public:
	//Creature constructor seeds srand for dice rolls imminent to creation of these objects
	Creature() {srand(time(NULL));}  

	//generates a random int value within the bounds of the object's attack dice values 
	//returns this value
	virtual int attackRoll();

	//generates a random int value within the bounds of the object's defense dice values 
	//returns this value
	virtual int defendRoll();

	//takes an attack value and a defense value as parameters and calculates damage
	//function then updates the calling object's strength value accordingly
	virtual void takeDamage(int, int);

	//generates a random number 1-10 and allows a victorious creature to recover 
	//strength after battle. Takes creature's starting strength (before battle) as a parameter
	int recover(int);

	//returns armor value
	int getArmor();

	//returns strength value
	int getStrength();

	//returns name value
	string getName();

	//returns team value
	int getTeam();

	//sets name value
	void setName(string);

	//sets Team assignment
	void setTeam(int);

	//adds to a Creatures tourney points
	void setTourneyPoints(int);

	//returns creature_class value
	int getCreatureClass();

	//returns tourney_points value
	int getTourneyPoints();
};

class Goblin : public Creature {
protected:
	bool achilles;
public:
	//instantiates a Goblin object with the appropriate starting values
	Goblin();

	//overrides Creature::attackRoll()
	//sets bool flag (achilles) to "true" when a 12 is rolled
	int attackRoll();

	//overrides Creature::takeDamage()
	//if value of Goblin member achilles is true, then attack value is halved when
	//calculating damge to Goblin objects
	void takeDamage(int, int);
};

class Barbarian : public Creature {
public:
	//instantiates a Barbarian object with the appropriate starting values
	Barbarian();
};

class Reptile : public Creature {
public:
	//instantiates a Reptile object with the appropriate starting values
	Reptile();
};

class BlueMen : public Creature {
public:
	//instantiates a BlueMen object with the appropriate starting values
	BlueMen();
};

class Shadow : public Creature {
public:
	//instantiates a Shadow object with the appropriate starting values
	Shadow();

	//overrides Creature::takeDamage()
	//a 50/50 "coin flip" is performed before damage is assessed
	//when Shadow objects "win" this flip, no damage is assessed  
	void takeDamage(int, int);
};

#endif