#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Warrior : public Character {
	private:
		string allegiance;

	public:
		Warrior(const string& name, double health, double attackStrength, string allegiance);
		void attack(Character& defender);
};

#endif
