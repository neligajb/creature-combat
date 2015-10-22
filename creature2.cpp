//Combat
//CS 162 - Fall 2014
//author: Boone Neligan
//
//Creature class and subclasses - implementation file

#include "creature2.h"


int Creature::attackRoll() {
	int total = 0;
	for (int i=0; i<a_dice.num; i++) {
		total += (rand() % a_dice.sides + 1);
	}
	return total;
}

int Creature::defendRoll() {
	int total = 0;
	for (int i=0; i<d_dice.num; i++) {
		total += (rand() % d_dice.sides + 1);
	}
	return total;
}

void Creature::takeDamage(int a, int d) {
	int total_damage = a - d - armor;
	if (total_damage > 0) {
		cout << total_damage << " damage points to " << name << "!" << endl << endl;
		int new_strength = strength - total_damage;
		strength = new_strength;
	}
	else {
		cout << "0 damage points to " << name << "!" << endl << endl;
	}
}

int Creature::recover(int start_strength) {
	srand(time(NULL));
	double damage_taken = start_strength - strength;
	double rand_num = (rand() % 9) + 1;
	double percentage = rand_num / 10;
	double dub_strength = (damage_taken * percentage);
	strength += round(dub_strength);
	return round(dub_strength);
}

int Creature::getArmor() {
	return armor;
}

int Creature::getStrength() {
	return strength;
}

string Creature::getName() {
	return name;
}

int Creature::getCreatureClass() {
	return creature_class;
}

int Creature::getTourneyPoints() {
	return tourney_points;
}

int Creature::getTeam() {
	return team;
}

void Creature::setTeam(int team) {
	this->team = team;
}

void Creature::setTourneyPoints(int points) {
	tourney_points += points;
}

void Creature::setName(string n) {
	name += n;
}


Goblin::Goblin() : Creature() {
	name = "Goblin";
	a_dice.num = 2;
	a_dice.sides = 6;
	d_dice.num = 1;
	d_dice.sides = 6;
	armor = 3;
	strength = 8;
	achilles = false;
	tourney_points = 0;
	creature_class = 1;
}

int Goblin::attackRoll() {
	int total = 0;
	for (int i=0; i<a_dice.num; i++) {
		total += (rand() % a_dice.sides + 1);
	}
	if (total == 12) {
		achilles = true;
		cout << "     Achilles Strike!" << endl;
		cout << "Opponent's attacks are 50%!" << endl << endl;
	}
	return total;
}

void Goblin::takeDamage(int a, int d) {
	if (achilles == true) {
		int temp = a/2;
		a = temp;
		cout << name << "'s" << " opponent's Achilles has been cut!" << endl;
		cout << "Opponent's attacks are halved!" << endl << endl;
	}

	int total_damage = a - d - armor;
	if (total_damage > 0) {
		cout << total_damage << " damage points to " << name << "!"  << endl << endl;
		int new_strength = strength - total_damage;
		strength = new_strength;
	}
	else {
		cout << "0 damage points to " << name << "!" << endl << endl;
	}
}

Barbarian::Barbarian() : Creature() {
	name = "Barbarous Maximus";
	a_dice.num = 2;
	a_dice.sides = 6;
	d_dice.num = 2;
	d_dice.sides = 6;
	armor = 0;
	strength = 12;
	tourney_points = 0;
	creature_class = 2;
}

Reptile::Reptile() : Creature(){
	name = "Reptilian";
	a_dice.num = 3;
	a_dice.sides = 6;
	d_dice.num = 1;
	d_dice.sides = 6;
	armor = 7;
	strength = 18;
	tourney_points = 0;
	creature_class = 3;
}

BlueMen::BlueMen() : Creature(){
	name = "The Blue Man Horde";
	a_dice.num = 2;
	a_dice.sides = 10;
	d_dice.num = 3;
	d_dice.sides = 6;
	armor = 3;
	strength = 12;
	tourney_points = 0;
	creature_class = 3;
}

Shadow::Shadow() : Creature(){
	name = "The Shadow";
	a_dice.num = 2;
	a_dice.sides = 10;
	d_dice.num = 1;
	d_dice.sides = 6;
	armor = 0;
	strength = 12;
	tourney_points = 0;
	creature_class = 2;
}

void Shadow::takeDamage(int a, int d) {
	int flip = (rand() % 2);
	if (flip == 0) {
		cout << " ||((::))||" << endl << endl;
		cout <<  "Shadow Flash!" << endl;
		cout <<  " No Damage!" << endl << endl;
		return;
	} 
	int total_damage = a - d - armor;
	if (total_damage > 0) {
		cout << total_damage << " damage points to " << name << "!" << endl << endl;
		int new_strength = strength - total_damage;
		strength = new_strength;
	}
	else {
		cout << "0 damage points to " << name << "!" << endl << endl;
	}
}

