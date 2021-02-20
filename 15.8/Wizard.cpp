#include "Wizard.h"

Wizard::Wizard(const string& name, double health, double attackStrength, int rank) : Character(WIZARD, name, health, attackStrength) {
	this->rank = rank;
}

void Wizard::attack(Character& attackee) {
	double d;
	// if attackee is Wizard
	if (attackee.getType() == this->type) {
		Wizard &attackedWizard = dynamic_cast<Wizard&>(attackee);
		d = attackStrength * this->rank / attackedWizard.rank;
		attackedWizard.damage(d);
		cout << "Wizard " << this->name << " attacks " << attackedWizard.name << " --- POOF!!" << endl;
		cout << attackedWizard.name << " takes " << d << " damage." << endl;
	}
	// else if attackee isn't wizard
	else {
		d = this->attackStrength;
		cout << "Wizard " << this->name << " attacks " << attackee.getName() << " --- POOF!!" << endl;
		cout << attackee.getName() << " takes " << d << " damage." << endl;
		attackee.damage(d);
	}

	/* if (opponent.getType() == type) {
		Wizard &opp = dynamic_cast<Wizard&>(opponent);
		d = attackStrength * rank / opp.rank;
		opp.damage(d);
	}
	else {
		d = attackStrength;
		opponent.damage(d);
	}
	cout << "Wizard " << this->name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
	cout << opponent.getName() << " takes " << d << " damage." << endl; */
}
