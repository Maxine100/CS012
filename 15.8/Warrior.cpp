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
}
