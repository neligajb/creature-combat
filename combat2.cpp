//Combat
//author: Boone Neligan
//
//Combat main file

#include "creature2.h"
#include "tournament.h"


int main() {
	cout << endl;
	cout << "*****************" << endl;
	cout << "* BATTLE ROYALE *" << endl;
	cout << "*****************" << endl;

	char replay;
	do {
		queue<Creature*> team1;
		queue<Creature*> team2;
		int team_size = setTeamSize();
		chooseTeam(team1, team_size, 1);
		chooseTeam(team2, team_size, 2);

		stack<Creature*> vanquished;

		while (!team1.empty() && !team2.empty()) {
			Creature *temp;
			int winner = clash(team1.front(), team2.front());
			if (winner == 1) {
				temp = team1.front();
				team1.pop();
				team1.push(temp);

				temp = team2.front();
				team2.pop();
				vanquished.push(temp);
			}
			else {
				temp = team2.front();
				team2.pop();
				team2.push(temp);

				temp = team1.front();
				team1.pop();
				vanquished.push(temp);
			}
		}

		if (team1.empty()) {
			results(team2, vanquished);
		}
		else {
			results(team1, vanquished);
		}


		do {
			cout << "Play again? (y/n) ";
			cin >> replay;
		} while (replay != 'Y' && replay != 'y' && replay != 'N' && replay != 'n');
	} while (replay != 'N' && replay != 'n');

	return 0;
}

