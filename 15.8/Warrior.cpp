#include "Warrior.h"

Warrior::Warrior(const string& name, double health, double attackStrength, string allegiance) : Character(WARRIOR, name, health, attackStrength) {
	this->allegiance = allegiance;
}

void Warrior::attack(Character &opponent) {
	double d;
	if (type == opponent.getType()) {
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
		cout << "Warrior " << this->getname() << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
		cout << opponent.getName() << " takes " << d << " damage." << endl;
	}
}
