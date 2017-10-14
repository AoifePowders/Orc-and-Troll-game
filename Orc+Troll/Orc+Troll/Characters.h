#pragma once
#include <iostream>

using namespace std;

//encapsulated variables
struct Variable
{
	int direction = 0;
	int weapon = 0;
	int spell = 0;
	int shield = 0;
	int hit = 0;
	int enemyHealth = 500;
}variables;

//pointers
int coins = 400;
int *ptrCoins = &coins;

int health = 100;

int character = 0;
int *ptrCharacter = &character;

//random numbers
int randWeapon = (rand() % 6) + 1;
int damage = (rand() % 20) + 1;

//functions
void chooseCharacter();
void stats();
void travel();
void woods();
void forest();
void town();
void gameOver();
void shop(int *ptrcharacter, int *ptrcoins);
void travel2();
void battle();
void randomNumber(int *hit);
void win();
void lose();


//polymorphism
class Melee {
public:
	virtual void punch() = 0;
	virtual void kick() = 0;
	virtual void stick() = 0;
	virtual void fryingPan() = 0;
	virtual void dagger() = 0;
	virtual void bone() = 0;
	
};

class OrcMelee : public Melee {
public:
	void hammer() { cout << "You swing to smash the enemy with the mighty hammer" << endl; }
	void axe() { cout << "you swing to cut a chunk of flesh from the enemy" << endl; }
	void sword() { cout << "you swing to stab the enemy with your sword" << endl; }
	void spear() { cout << "you swing to stab the enemy with your spear" << endl; }

	void punch() { cout << "You swing to punch the enemy" << endl; }
	void kick() { cout << "you swing to kick the emeny" << endl; }
	void stick() { cout << "you swing to whack the enemy with a stick, he laughs" << endl; }
	void fryingPan() { cout << "you swing to whack the enemy with your frying pan" << endl; }
	void dagger() { cout << "you swing to throw your dagger at the enemy" << endl; }
	void bone() { cout << "youswing to  hit the enemy with your bone" << endl; }
};

class TrollMelee : public Melee {
public:
	void club() { cout << "you swing to whack the enemy with your club" << endl; }
	void saw() { cout << "you swing to saw flesh off your enemy\n there is blood all over the battle field" << endl; }
	void whip() { cout << "you swing to whip the enemy" << endl; }
	void glaive() { cout << "you swing to slice the enemy with your glaive" << endl; }

	void punch() { cout << "you swing to Punch the enemy" << endl; }
	void kick() { cout << "you swing to Kick the enemy" << endl; }
	void stick() { cout << "you swing to whack the enemy with your stick, he laughs" << endl; }
	void fryingPan() { cout << "you swing to whack the enemy" << endl; }
	void dagger() { cout << "you swing to stab the enemy" << endl; }
	void bone() { cout << "you swing to hit the enemy with your bone" << endl; }
 };


class spells {
	virtual void confusion() = 0;
	virtual void heal() = 0;
	virtual void faithfulHound() = 0;
};

class OrcSpells : public spells {
public:
	void heal() { cout << "You heal to full health" << endl; }
	void confusion() { cout << "The enemy is confused" << endl; }
	void faithfulHound() { cout << "hound attacks" << endl; }

	void fireball() { cout << "fireball flys towards enemy" << endl; }
	void darkness() { cout << "darkness surrounds the enemy" << endl; }

};

class TrollSpells : public spells {
public:
	void heal() { cout << "You heal to full health" << endl; }
	void confusion() { cout << "The enemy is confused" << endl; }
	void faithfulHound() { cout << "hound" << endl; }

	void callLightning() { cout << "Lightning strikes the enemy" << endl; }
	void chillTouch() { cout << "You try Freeze the enemy" << endl; }
};

class shield {
	virtual void commonShield() = 0;
	virtual void rareShield() = 0;
	virtual void legendary() = 0;
};

class OrcShield : public shield {
public:
	void commonShield() { cout << "You defend with your common orc shield" << endl; }
	void rareShield() { cout << "You defend with your rare orc shield" << endl; }
	void legendary() { cout << "You defend with your legendary orc shield" << endl; }
};

class TrollShield : public shield {
public:
	void commonShield() { cout << "You defend with your common troll shield" << endl; }
	void rareShield() { cout << "You defend with your rare troll shield" << endl; }
	void legendary() { cout << "You defend with your legendary troll shield" << endl; }
};
