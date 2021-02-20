#ifndef ELF_H
#define ELF_H

class Elf : public Character {
	private:
		string family;
	
	public:
		Elf(const string& name, double health, double attackStrength, string family);
		void attack(Character& attackee);
};

#endif
