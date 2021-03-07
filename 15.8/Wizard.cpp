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
	}
	// else if attackee isn't wizard
	else {
		d = this->attackStrength;
		attackee.damage(d);
	}
	cout << "Wizard " << this->name << " attacks " << attackee.getName() << " --- POOF!!" << endl;
	cout << attackee.getName() << " takes " << d << " damage." << endl;
}
