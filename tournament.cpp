//Combat
//author: Boone Neligan
//
//Tournament implementaiton file

#include "creature2.h"
#include "tournament.h"


void results(queue<Creature*> &winner, stack<Creature*> &vqd) {
	vector<Results*> final_results;

	while (!winner.empty()) {
		Results* p_results = new Results;
		p_results->name = winner.front()->getName();
		p_results->points = winner.front()->getTourneyPoints();
		p_results->team = winner.front()->getTeam();
		final_results.push_back(p_results);
		winner.pop();
	}

	while (!vqd.empty()) {
		Results* p_results = new Results;
		p_results->name = vqd.top()->getName();
		p_results->points = vqd.top()->getTourneyPoints();
		p_results->team = vqd.top()->getTeam();
		final_results.push_back(p_results);
		vqd.pop();
	}

	int team1_total = 0;
	int team2_total = 0;

	for (unsigned int i = 0; i < final_results.size(); i++) {
		Results *temp = final_results.at(i);
		if (temp->team == 1) {
			team1_total += temp->points;
		}
		else {
			team2_total += temp->points;
		}
	}


	Results *first;
	Results *second;
	Results *third;

	int max = 0;
	unsigned int loc;
	for (unsigned int i = 0; i < final_results.size(); i++) {
		Results *temp = final_results.at(i);
		if (temp->points > max) {
			max = temp->points;
			loc = i;
		}
	}
	first = final_results.at(loc);
	final_results.erase(final_results.begin() + loc);
	max = 0;

	for (unsigned int i = 0; i < final_results.size(); i++) {
		Results *temp = final_results.at(i);
		if (temp->points > max) {
			max = temp->points;
			loc = i;
		}
	}
	second = final_results.at(loc);
	final_results.erase(final_results.begin() + loc);
	max = 0;

	for (unsigned int i = 0; i < final_results.size(); i++) {
		Results *temp = final_results.at(i);
		if (temp->points > max) {
			max = temp->points;
			loc = i;
		}
	}
	third = final_results.at(loc);
	final_results.erase(final_results.begin() + loc);
	max = 0;


	cout << endl;
	cout << "**********************" << endl;
	cout << "* TOURNAMENT RESULTS *" << endl;
	cout << "**********************" << endl << endl;

	if (team1_total == team2_total) {
		cout << "Miraculously, Player 1 and Player 2 have tied, each with totals of ";
		cout << team1_total << " points!" << endl;
	}
	else if (team1_total > team2_total) {
		cout << "Player 1 has won the Tournament with a grand total of ";
		cout << team1_total << " points!" << endl;
		cout << "Congratulations!!" << endl;
	}
	else if (team1_total < team2_total) {
		cout << "Player 2 has won the Tournament with a grand total of ";
		cout << team2_total << " points!" << endl;
		cout << "Congratulations!!" << endl << endl;
	}

	cout << "Top Three Individual Combatants:" << endl;
	cout << "*******************************" << endl;
	cout << "1. " << first->name << ", with " << first->points; 
	cout << " points! (Player " << first->team << ")" << endl;

	cout << "2. " << second->name << ", with " << second->points;
	cout << " points! (Player " << second->team << ")" << endl;

	cout << "3. " << third->name << ", with " << third->points;
	cout << " points! (Player " << third->team << ")" << endl << endl;

	//free memory
	final_results.clear();
}


void chooseTeam(queue<Creature*> &team, int size, int player) {
	cout << endl;
	cout << "Player " << player << ", please choose " << size << " characters for your team...";
	cout << endl << endl;

	char name_mod = 'a';

	long long l_player = player;

	for (int i = 0; i < size; i++) {
		cout << "Combatant " << i + 1 << ":" << endl;
		cout << "************" << endl;
		team.push(chooseCreature(l_player, name_mod));
		cout << endl;
		++name_mod;
	}
}


int setTeamSize() {
	cout << endl;
	int input;
	do {
		cout << "Choose size of teams for battle (2 - 8): ";
		cin >> input;
	} while (input < 2 || input > 8);

	return input;
}


Creature* chooseCreature(long long player, char name_mod) {
	char choice;
	string mod = '.' + to_string(player) + name_mod;

	do {
		cout << "1. Goblin" << endl;
		cout << "2. Barbarous Maximus" << endl;
		cout << "3. Reptilian" << endl;
		cout << "4. Blue Men Horde" << endl;
		cout << "5. The Shadow" << endl;

		cout << endl;
		cout << "Enter your choice (1-5): ";
		cin >> choice;
		if (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5') {
			cout << "Invalid input." << endl << endl;
		}
	} while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5');


	if (choice == '1') {
		Creature* p_creature = new Goblin();
		p_creature->setTeam(player);
		p_creature->setName(mod);
		return p_creature;
	}
	else if (choice == '2') {
		Creature* p_creature = new Barbarian();
		p_creature->setTeam(player);
		p_creature->setName(mod);
		return p_creature;
	}
	else if (choice == '3') {
		Creature* p_creature = new Reptile();
		p_creature->setTeam(player);
		p_creature->setName(mod);
		return p_creature;
	}
	else if (choice == '4') {
		Creature* p_creature = new BlueMen();
		p_creature->setTeam(player);
		p_creature->setName(mod);
		return p_creature;
	}
	else if (choice == '5') {
		Creature* p_creature = new Shadow();
		p_creature->setTeam(player);
		p_creature->setName(mod);
		return p_creature;
	}
}

int matchupValue(Creature *winner, Creature *loser) {
	if (winner->getCreatureClass() > loser->getCreatureClass()) {
		return 2;
	}
	else if (winner->getCreatureClass() == loser->getCreatureClass()) {
		return 5;
	}
	else if (winner->getCreatureClass() < loser->getCreatureClass()) {
		return 10;
	}
}


int clash(Creature *one, Creature *two) {
	char input;
	int attack;
	int defense;
	int rnd = 1;

	cout << endl;
	cout << one->getName() << " vs. " << two->getName() << endl;
	cout << "Ready to Battle!" << endl << endl;
	cout << "enter any key to begin: ";
	cin >> input;
	cout << endl;

	int one_start_strength = one->getStrength(); 
	int two_start_strength = two->getStrength();

	while (one->getStrength() > 0 && two->getStrength() > 0) {
		cout << "***********" << endl;
		cout << "* ROUND " << rnd << " *" << endl;
		cout << "***********" << endl << endl;
		attack = one->attackRoll();
		defense = two->defendRoll();

		cout << one->getName() << " attack roll = " << attack << endl;
		cout << two->getName() << " defense roll = " << defense << endl;
		cout << two->getName() << " armor = " << two->getArmor() << endl << endl;

		two->takeDamage(attack, defense);

		cout << endl;
		cout << one->getName() << endl;
		for (int i=0; i<(one->getName()).length(); i++) {
			cout << "*";
		}
		cout << endl;
		cout << "strength = " << one->getStrength() << endl << endl;
	
		cout << two->getName() << endl; 
		for (int i=0; i<(two->getName()).length(); i++) {
			cout << "*";
		}
		cout << endl;
		cout << "strength = " << two->getStrength() << endl << endl << endl; 

		if (one->getStrength() <= 0 || two->getStrength() <= 0) {
			break;
		}

		cout << "enter any key for counter-attack: ";
		cin >> input;
		cout << endl << "***********************************" << endl << endl;
///////////////////////////////////////////////////////////////////////////////

		attack = two->attackRoll();
		defense = one->defendRoll();

		cout << two->getName() << " attack roll = " << attack << endl;
		cout << one->getName() << " defense roll = " << defense << endl;
		cout << one->getName() << " armor = " << one->getArmor() << endl << endl;

		one->takeDamage(attack, defense);

		cout << one->getName() << endl;
		for (int i=0; i<(one->getName()).length(); i++) {
			cout << "*";
		}
		cout << endl;
		cout << "strength = " << one->getStrength() << endl << endl;

		cout << two->getName() << endl;
		for (int i=0; i<(two->getName()).length(); i++) {
			cout << "*";
		}
		cout << endl;
		cout << "strength = " << two->getStrength() << endl << endl << endl;

		rnd++;

		if (one->getStrength() <= 0 || two->getStrength() <= 0) {
			break;
		}

		cout << "enter any key for next round: ";
		cin >> input;
		cout << endl << endl << endl;
	} 
	if (one->getStrength() <= 0) {
		cout << "**" <<one->getName() << " was crushed by " << two->getName() << "**" << endl << endl;
		two->setTourneyPoints(matchupValue(two, one)); 
		cout << two->getName() << " recovers " << two->recover(two_start_strength) << " points.";
		cout << endl << endl; 
		return 2;
	}
	else { 
		cout << "**" << two->getName() << " was crushed by " << one->getName() << "**" << endl << endl;
		one->setTourneyPoints(matchupValue(one, two));  
		cout << one->getName() << " recovers " << one->recover(one_start_strength) << " points.";
		cout << endl << endl; 
		return 1;
	}
}



