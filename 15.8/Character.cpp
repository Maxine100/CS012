#include "Character.h"

Character::Character(HeroType type, const string& name, double health, double attackStrength) {
	this->type = type;
	this->name = name;
	this->health = health;
	this->attackStrength = attackStrength;
}

HeroType Character::getType() const {
	return this->type;
}

const string& Character::getName() const {
	return this->name;
}

int Character::getHealth() const {
	return static_cast<int>(this->health);
}

void Character::setHealth(double h) {
	if (h < 0) {
		h = 0;
	}
	this->health = h;
}

void Character::damage(double d) {
	this->health = this->health - d;
}

bool Character::isAlive() const {
	if (getHealth() > 0) {
		return true;
	}
	return false;
}
