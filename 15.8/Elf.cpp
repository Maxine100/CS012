#include "Elf.h"

Elf::Elf(const string& name, double health, double attackStrength, string family): Character(Elf, name, health, attackStrength) {
	this->family = family;
}

void Elf::attack(Character& opponent) {
	double d;
	if (type == opponent.getType()) {
		Elf &opp = dynamic_cast<Elf&>(opponent);
		if (this->family != opp.family) {
			d = health / MAX_HEALTH * attackStrength;
			cout << "Elf " << this->getName() << " shoots an arrow at " << opp.name << "---TWANG!!" << endl;
			cout << opp.name << " takes " << d << " damage." << endl;
			opp.damage(d);
		}
		else {
			cout << "Elf " << this->getName() << " does not attack Elf " << opp.name << "." << endl;
			cout << "They are both members of the " << this->family << " family." << endl;
		}
	}
	else {
		d = this->health / MAX_HEALTH * this->attackStrength;
		opponent.damage(d);
		cout << "Elf " << this->getName() << " shoots an arrow at " << opponent.getName() << " ---TWANG!!" << endl;
		cout << opponent.getName() << " takes " << d << " damage." << endl;
	}
}
