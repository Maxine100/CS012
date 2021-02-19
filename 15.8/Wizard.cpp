#include "Character.h"
#include "Wizard.h"

Wizard::Wizard(const string& name, double health, double attackStrength, int rank) : Character(WIZARD, name, health, attackStrength) {
	this->rank = rank;
}

void Wizard::attack(Character& opponent) {
	double d = 0.0;
	if (opponent.getType() == type) {
		Wizard &opp = dynamic_cast<Wizard&>(opponent);
		d = attackStrength * rank / opp.rank;
		opp.damage(d);
	}
	else {
		d = attackStrength;
		opponent.damage(d);
	}
	cout << "Wizard " << this->name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
	cout << opponent.getName() << " takes " << d << " damage." << endl;
}
