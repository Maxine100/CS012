#include "Character.h"

Character::Character(HeroType type, const string& name, double health, double attackStrength) {
	this->type = type;
	this->name = name;
	this->healh = health = health;
	this->attackStrength = attackStrength;
}

HeroType Character::getType() const {
	return type;
}

const string& Character::getName() const {
	return name;
}

int Character::getHealth() const {
	return statics_cast<int>(health);
}

void Character::setHealth(double h) {
	if (h < 0) {
		h = 0;
	}
	health = h;
}

void Character::damage(double d) {
	health = health - d;
}

bool Character::isAlive() const {
	if (getHealth() > 0) {
		return true;
	}
	return false;
}
