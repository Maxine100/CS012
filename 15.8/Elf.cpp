#include "Elf.h"

Elf::Elf(const string& name, double health, double attackStrength, string family) : Character(ELF, name, health, attackStrength) {
	this->family = family;
}

void Elf::attack(Character& attackee) {
	double d;
	// if attackee is elf
	if (attackee.getType() == this->type) {
		Elf &attackedElf = dynamic_cast<Elf&>(attackee);
		// if attackee is of same family
		if (attackedElf.family == this->family) {
			cout << "Elf " << this->name << " does not attack Elf " << attackedElf.name << "." << endl;
			cout << "They are both members of the " << this->family << " family." << endl;
		}
		// else if attackee isn't of same family
		else {
			d = this->health / MAX_HEALTH * this->attackStrength;
			cout << "Elf " << this->name << " shoots an arrow at " << attackedElf.name << " --- TWANG!!" << endl;
			cout << attackedElf.name << " takes " << d << " damage." << endl;
			attackedElf.damage(d);
		}
	}
	// else if attackee isn't elf
	else {
		d = this->health / MAX_HEALTH * attackStrength;
		cout << "Elf " << name << " shoots an arrow at " << attackee.getName() << " --- TWANG!!" << endl;
		cout << attackee.getName() << " takes " << d << " damage." << endl;
		attackee.damage(d);
	}
}
