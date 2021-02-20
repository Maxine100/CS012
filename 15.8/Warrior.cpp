#include "Warrior.h"

Warrior::Warrior(const string& name, double health, double attackStrength, string allegiance) : Character(WARRIOR, name, health, attackStrength) {
	this->allegiance = allegiance;
}

void Warrior::attack(Character &attackee) {
	double d;
	// if attackee is Warrior
	if (attackee.getType() == this->type) {
		Warrior &attackedWarrior = dynamic_cast<Warrior&>(attackee);
		// if attackee has same allegiance
		if (attackedWarrior.allegiance == this->allegiance) {
			cout << "Warrior " << name << " does not attack Warrior " << attackedWarrior.name << "." << endl;
			cout << "They share an allegiance with " << this->allegiance << "." << endl;
		}
		// else if attackee doesn't have same allegiance
		else {
			d = this->health / MAX_HEALTH * this->attackStrength;
			cout << "Warrior " << name << " attacks " << attackedWarrior.name << " --- SLASH!!" << endl;
			cout << attackedWarrior.name << " takes " << d << " damage." << endl;
			attackedWarrior.damage(d);
		}
	}
	// else if attackee is not warrior
	else {
		d = this->health / MAX_HEALTH * this->attackStrength;
		cout << "Warrior " << name << " attacks " << attackee.getName() << " --- SLASH!" << endl;
		cout << attackee.getName() << " takes " << d << " damage." << endl;
		attackee.damage(d);
	}

	/* if (type == opponent.getType()) {
		Warrior &opp = dynamic_cast<Warrior &>(opponent);
		if (this->allegiance != opp.allegiance) {
			d = (health / MAX_HEALTH) * attackStrength;
			cout << "Warrior " << this->getName() << " attacks " << opp.name << " --- SLASH!!" << endl;
			cout << opp.name << " takes " << d << " damage." << endl;
			opp.damage(d);
		}
		else {
			cout << "Warrior " << this->getName() << " does not attack Warrior " << opp.name << "." << endl;
			cout << "They share an allegiance with " << this->allegiance << "." << endl;
		}
	}
	else {
		d = (health / MAX_HEALTH) * attackStrength;
		opponent.damage(d);
		cout << "Warrior " << this->getName() << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
		cout << opponent.getName() << " takes " << d << " damage." << endl;
	} */
}
