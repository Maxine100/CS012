#ifndef WARRIOR_H
#define WARRIOR_H

class Warrior : public Character {
	private:
		string allegiance;

	public:
		Warrior(const string& name, double health, double attackStrength, string allegiance);
		void attack(Character& attackee);
};

#endif
