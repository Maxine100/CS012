/* 7.17 LAB 1 (Part 2) Using Vectors and Functions
This program will store roster and rating information for a soccer team. Coaches rate players during tryouts to ensure a balanced team.

(1) Prompt the user to input five pairs of numbers: A player's jersey number (0 - 99) and the player's rating (1 - 9). Store the jersey numbers in one int vector and the ratings in another int vector. Output these vectors (i.e., output the roster).
	Ex:

	Enter player 1's jersey number:
	84
	Enter player 1's rating:
	7

	Enter player 2's jsersey number:
	23
	Enter player 2's rating:
	4

	Enter player 3's jersey number:
	4
	Enter player 3's rating:
	5

	Enter player 4's jersey number:
	30
	Enter player 4's rating:
	2

	Enter player 5's jersey number:
	66
	Enter player 5's rating:
	9

	ROSTER
	Player 1 -- Jersey number: 84, Rating: 7
	Player 2 -- Jersey number: 23, Rating: 4
	...

(2) Implement a menu of options for a user to modify the roster. Each option is represented by a single character. The program initially outputs the menu, and outputs the menu after a user chooses an option. The program ends when the user chooses the option to Quit. For this step, the other options do nothing.

	Ex:

	MENU
	a - Add player
	d - Remove player
	u - Update player rating
	r - Output players above a rating
	o - Output roster
	q - Quit

	Choose an option:

(3) Implement the "Output roster" menu option. Be sure to write a separate function for each menu option.
	Ex:

	ROSTER
	Player 1 -- Jersey number: 84, Rating: 7
	Player 2 -- Jersey number: 23, Rating: 4
	...

(4) Implement the "Add player" menu option. Prompt the user for a new player's jersey number and rating. Append the values to the two vectors.

	Ex:
	
	Enter another player's jersey number:
	49
	Enter another player's rating:
	8

(5) Implement the "Delete player" menu option. Prompt the user for a player's jersey number. Remove the player from the roster (delete the jersey number and rating).

	Ex:
	
	Enter a jersey number:
	4

(6) Implement the "Update player rating" menu option. Prompt the user for a player's jersey number. Prompt again for a new rating for the player, and then change that player's rating.

	Ex:
	
	Enter a jersey number:
	23
	Enter a new rating for player:
	6

(7) Implement the "Output players above a rating" menu option. Prompt the user for a rating. Print the jersey number and rating for all players with ratings above the entered value.

	Ex:
	
	Enter a rating:
	5
	
	ABOVE 5
	Player 1 -- Jersey number: 84, Rating: 7
... */

#include <iostream>
// FIXME include ector library
#include <vector>
using namespace std;

void outputRoster(const vector<int> &, const vector<int> &);
void addPlayer(vector<int> &, vector<int> &);
void removePlayer(vector<int> &, vector<int> &);
void updatePlayerRating(const vector<int> &, vector<int> &);
void outputPlayersAboveRating(const vector<int> &, const vector<int> &);

int main() {

	/* Type your code here. */
	vector<int> jerseyNumbers;
	vector<int> ratings;

	for (int i = 0; i < 5; ++i) {
		int num;
		cout << "Enter player " << i + 1 << "'s jsersey number:";
		cout << endl;
		cin >> num;
		jerseyNumbers.push_back(num);
		cout << "Enter player " << i + 1 << "'s rating:";
		cout << endl;
		cin >> num;
		ratings.push_back(num);
		cout << endl;
	}

	outputRoster(jerseyNumbers, ratings);

	char option = 'c';
	while (option != 'q') {
		cout << "MENU" << endl;
		cout << "a - Add player" << endl;
		cout << "d - Remove player" << endl;
		cout << "u - Update player rating" << endl;
		cout << "r - Output players above a rating" << endl;
		cout << "o - Output roster" << endl;
		cout << "q - Quit" << endl;
		cout << endl;
		cout << "Choose an option:" << endl;
		cin >> option;
		if (option == 'a') {
			addPlayer(jerseyNumbers, ratings);
		}
		else if (option == 'd') {
			removePlayer(jerseyNumbers, ratings);
		}
		else if (option == 'u') {
			updatePlayerRating(jerseyNumbers, ratings);
		}
		else if (option == 'r') {
			outputPlayersAboveRating(jerseyNumbers, ratings);
		}
		else if (option == 'o') {
			outputRoster(jerseyNumbers, ratings);
		}
		else {

		}
	}

	return 0;
}

void outputRoster(const vector<int>& jerseyNumbers, const vector<int>& ratings) {
	cout << "ROSTER" << endl;
	for (int i = 0; i < jerseyNumbers.size(); ++i) {
		cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNumbers.at(i) << ", Rating: " << ratings.at(i) << endl;
	}
	cout << endl;
}
void addPlayer(vector<int>& jerseyNumbers, vector<int>& ratings) {
	int num;
	cout << "Enter another player's jersey number:" << endl;
	cin >> num;
	jerseyNumbers.push_back(num);
	cout << "Enter another player's rating:" << endl;
	cin >> num;
	ratings.push_back(num);
	cout << endl;
}
void removePlayer(vector<int>& jerseyNumbers, vector<int>& ratings) {
	int num;
	cout << "Enter a jersey number:" << endl;
	cin >> num;
	int pos = -1;
	for (int i = 0; i < jerseyNumbers.size(); ++i) {
		if (jerseyNumbers.at(i) == num) {
			pos = i;
			break;
		}
	}
	if (pos != -1) {
		for (int i = pos; i < jerseyNumbers.size() - 1; ++i) {
			jerseyNumbers.at(i) = jerseyNumbers.at(i + 1);
			ratings.at(i) = ratings.at(i + 1);
		}
		jerseyNumbers.pop_back();
		ratings.pop_back();
	}
	cout << endl;
}
void updatePlayerRating(const vector<int>& jerseyNumbers, vector<int>& ratings) {
	int num;
	int pos = -1;
	cout << "Enter a jersey number:" << endl;
	cin >> num;
	for (int i = 0; i < jerseyNumbers.size(); ++i) {
		if (jerseyNumbers.at(i) == num) {
			pos = i;
			break;
		}
	}
	cout << "Enter a new rating for player:" << endl;
	cin >> num;
	if (pos != -1) {
		ratings.at(pos) = num;
	}
	cout << endl;
}
void outputPlayersAboveRating(const vector<int>& jerseyNumbers, const vector<int>& ratings) {
	int num;
	cout << "Enter a rating:" << endl;
	cin >> num;
	cout << endl;
	cout << "ABOVE " << num << endl;
	for (int i = 0; i < jerseyNumbers.size(); ++i) {
		if (ratings.at(i) > num) {
			cout << "PLAYER " << i + 1 << " -- Jersey number: " << jerseyNumbers.at(i) << ", Rating: " << ratings.at(i) << endl;
		}
	}
	cout << endl;
}
