#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Characters.h"

using namespace std;

int main(void)
{
	srand((unsigned)time(0));

	chooseCharacter();
	stats();
	travel();

	cin.get();
}

// when you loose or wn the game this funcion closes the window
void gameOver()
{
	cout << "GAME OVER" << endl;
	system("PAUSE");
	std::exit(0);
}

//function gets which character you choose
void chooseCharacter()
{
	cout << "Choose Character: \n 1) Troll\n 2) Orc" << endl;
	cin >> character;
	system("CLS");
}

//outputs your stats (health, coins)
void stats()
{
	cout << "Health : " << health <<"\n Coins : "<< coins << endl;
	system("Pause");
	system("CLS");
}

//first travel function, gets where you would like to go next
void travel()
{
	cout << "Which way would you like to go?" << endl;
	cout << "1) North: Towards town" << endl;
	cout << "2) East: Towards woods" << endl;
	cout << "3) West: Towards Spooky Forest" << endl;
	cin >> variables.direction;
	system("CLS");

	if (variables.direction == 1)
	{
		town();
	}
	if (variables.direction == 2)
	{
		woods();
	}
	if (variables.direction == 3)
	{
		forest();
	}
	
}

void woods()
{
	int flowers = 0;
	int goShop = 0;
	cout << "You walk throught the forest and see some flowers" << endl;
	cout << "Pick flowers?\n 1)Yes\n 2)No" << endl;
	cin >> flowers;
	
	if (flowers = 1)
	{
		//adds 200 to the coins variable
		coins = coins + 200;
		cout << "You found 200 coins" << endl;
		cout << "You keep walking and find the town" << endl;
		system("Pause");
		system("CLS");
	}
	else
	{
		cout << "You keep walking and find the town" << endl;
		cout << "Would you like to\n1) stop and buy some weapons\n2) continue ahead?" << endl;
		cin >> goShop;
		if (goShop == 1)
		{
			system("CLS");
			shop(&character, &coins);
		}
		else
		{
			system("CLS");
			travel2();
		}
		system("Pause");
	}
	//calls the next function
	town();
}

void forest()
{
	cout << " You walk toward a spooky forest, there is no path so you try to keep walking straight\n You never find a way out of the forest you walk for days on end\n and eventually starve to death\n GAME OVER" << endl;
	system("Pause");
	gameOver();
}

void town()
{
	int goShop = 0;
	cout << "You have reached the town," << endl;
	cout << "Would you like to\n1) stop and buy some weapons\n2) continue ahead?" << endl;
	cin >> goShop;
	if (goShop == 1)
	{
		system("CLS");
		shop(&character, &coins);
	}
	else
	{
		system("CLS");
		travel2();
	}
}

//function takes 2 pointers
void shop(int *ptrcharacter, int *ptrcoins)
{
	int buy;
	cout << "What would you like to buy?" << endl;
	cout << "1) Shield\n2) Weapon\n3) Spell\n4)leave shop" << endl;
	cin >> buy;
	system("CLS");

	if (buy == 1)
	{
		cout << "Which Shield would you like to buy?" << endl;
		cout << "1) Common: 50 coins, can block 10 damage" << endl;
		cout << "2) Rare: 100 coins, can block 20 damage" << endl;
		cout << "3) Legendary: 200 coins, can bloack 50 damage" << endl;
		cin >> variables.shield;

		if (variables.shield == 1)
		{
			*ptrcoins -= 50;
		}
		else if (variables.shield == 2)
		{
			*ptrcoins -= 100;
		}
		else if (variables.shield == 3)
		{
			*ptrcoins -= 200;
		}
		//shows you your stats again after every purchase
		stats();
		//calls the function again 
		shop(ptrcharacter, ptrcoins);
	}
	if (buy == 2)
	{
		cout << "Which Weapon would you like to buy?" << endl;
		if (*ptrcharacter == 2)
		{
			cout << "1) Hammer: 100 coins, can deal 60 damage" << endl;
			cout << "2) Axe: 150 coins, can deal 90 damage" << endl;
			cout << "3) Sword: 50 coins, can deal 30 damage" << endl;
			cout << "4) Spear: 10 coins, can deal 20 damage" << endl;
			cin >> variables.weapon;
			if (variables.weapon == 1)
			{
				*ptrcoins -= 100;
			}
			else if (variables.weapon == 2)
			{
				*ptrcoins -= 150;
			}
			else if (variables.weapon == 3)
			{
				*ptrcoins -= 50;
			}
			else if (variables.weapon == 4)
			{
				*ptrcoins -= 10;
			}
			stats();
			shop(ptrcharacter, ptrcoins);
		}
		else
		{
			cout << "1) club: 50 coins, can deal 30 damage" << endl;
			cout << "2) Saw: 100 coins, can deal 60 damage" << endl;
			cout << "3) Whip: 10 coins, can deal 20 damage" << endl;
			cout << "4) Glaive: 150 coins, can deal 90 damage" << endl;
			cin >> variables.weapon;
			if (variables.weapon == 1)
			{
				*ptrcoins -= 50;
			}
			else if (variables.weapon == 2)
			{
				*ptrcoins -= 100;
			}
			else if (variables.weapon == 3)
			{
				*ptrcoins -= 10;
			}
			else if (variables.weapon == 4)
			{
				*ptrcoins -= 150;
			}
			stats();
			shop(ptrcharacter, ptrcoins);
		}
	
	}
	if (buy == 3)
	{
		if (*ptrcharacter == 1)
		{
			cout << "1) Heal: 20 coins, Heals to full health once" << endl;
			cout << "2) Confusion: 30 coins, Causes enemy to become confused and lets you do 100 damage" << endl;
			cout << "3) faithfulHound: 50 coins, calls an allie to help you fight, 150 damage" << endl;
			cout << "4) callLightning: 100 coins, Strikes enemy with lightning, 200 damage" << endl;
			cout << "5) chillTouch: 150 coins, Freezes enemy, 230 damage" << endl;
			cin >> variables.spell;
			if (variables.spell == 1)
			{
				*ptrcoins -= 20;
			}
			else if (variables.spell == 2)
			{
				*ptrcoins -= 30;
			}
			else if (variables.spell == 3)
			{
				*ptrcoins -= 50;
			}
			else if (variables.spell == 4)
			{
				*ptrcoins -= 100;
			}
			else if (variables.spell == 5)
			{
				*ptrcoins -= 150;
			}
			stats();
			shop(ptrcharacter, ptrcoins);
		}
		else
		{
			cout << "1) Heal: 20 coins, Heals to full health once" << endl;
			cout << "2) Confusion: 30 coins, Causes enemy to become confused and  lets you do 100 damage" << endl;
			cout << "3) faithfulHound: 50 coins, calls an allie to help you fight, 150 damage" << endl;
			cout << "4) fireball: 150 coins, lights enemy on fire, 230 damage" << endl;
			cout << "5) darkness: 100 coins, calls creatures of the dark to fight enemy, 200 damage" << endl;
			cin >>  variables.spell;
			if (variables.spell == 1)
			{
				*ptrcoins -= 20;
			}
			else if (variables.spell == 2)
			{
				*ptrcoins -= 30;
			}
			else if (variables.spell == 3)
			{
				*ptrcoins -= 50;
			}
			else if (variables.spell == 4)
			{
				*ptrcoins -= 150;
			}
			else if (variables.spell == 5)
			{
				*ptrcoins -= 100;
			}
			stats();
			shop(ptrcharacter, ptrcoins);
		}
	}
	if(buy == 4)
	{
		travel2();
	}

	if (*ptrcoins <= 19)
	{
		cout << "You cant afford anything else" << endl;
		system("Pause");
		travel2();
	}
}

void travel2()
{
	system("CLS");
	cout << "Now that you have your weapons where would you like to go?" << endl;
	cout << "1) East: Spooky forest" << endl;
	cout << "2) North: Open field" << endl;
	cin >> variables.direction;

	if (variables.direction == 1)
	{
		cout << "You walk into the spooky forest, you hear weird noises coming from all over\n you turn to go back but the exit is gone you run for hours until you fall with tiredness\n you pass out from exhaustion and are never hear from again.";
		system("Pause");
		gameOver();

	}
	if (variables.direction == 2)
	{
		cout << "You move toward an open field and see someone walking toward you" << endl;
		cout << "You realise who it is run towards him you see that he starts to run toward you" << endl;
		cout << "You get ready for battle";
		system("Pause");
		system("CLS");
		battle();
	}
}

//battle function contains switch statements that control the battle
void battle()
{
	int battleAction = 0;
	cout << "What would you like to do?\n1) Attack\n2) Defend\n3) Use spell" << endl;
	cin >> battleAction;

	//creates a new orcmelee 
	OrcMelee *orcMelee = new OrcMelee();
	TrollMelee *trollMelee = new TrollMelee();
	OrcSpells *orcSpells = new OrcSpells();
	TrollSpells *trollSpells = new TrollSpells();

	if (battleAction == 1)
	{
		cout << "You attack with your weapon" << endl;
		//checks what character you choose at the beginning
		switch (character)
		{
		case 1:
			//checks what weapon you have if any
			switch (variables.weapon)
			{
			case 0:
				//if you dont have a weapon a random one is choosen
				switch (randWeapon)
				{
				case 1:
					cout << "You have no weapons so you use your fists" << endl;
					//calls function from the polymorphic class
					trollMelee->punch();
					if (variables.hit == 2)
					{
						variables.enemyHealth = variables.enemyHealth - damage;
						cout << "The enemy now has " << variables.enemyHealth << "health" << endl;
						system("Pause");
						win();
					}
					else
					{
						health = health - 10;
						cout << "You missed he hit you\n Your health:" << health << endl;
						system("Pause");
						lose();
					}
					
					break;
					
				case 2:
					cout << "You have no weapons so you use your feet" << endl;
					trollMelee->kick();
					if (variables.hit == 2)
					{
						variables.enemyHealth = variables.enemyHealth - damage;
						cout << "The enemy now has " << variables.enemyHealth << "health" << endl;
						system("Pause");
						win();
					}
					else
					{
						health = health - 10;
						cout << "You missed he hit you\n Your health:" << health << endl;
						system("Pause");
						lose();
					}

					
					break;
					
				case 3:
					cout << "You have no weapons so you use a stick you find on the ground" << endl;
					trollMelee->stick();
					if (variables.hit == 2)
					{
						variables.enemyHealth = variables.enemyHealth - damage;
						cout << "The enemy now has " << variables.enemyHealth << "health" << endl;
						system("Pause");
						win();
					}
					else
					{
						health = health - 10;
						cout << "You missed he hit you\n Your health:" << health << endl;
						system("Pause");
						lose();
					}

					
					break;
					
				case 4:
					cout << "You have no weapons so you use a frying pan you find on the ground\n dont know why its there but lets not ask questions." << endl;
					trollMelee->fryingPan();
					if (variables.hit == 2)
					{
						variables.enemyHealth = variables.enemyHealth - damage;
						cout << "The enemy now has " << variables.enemyHealth << "health" << endl;
						system("Pause");
						win();
					}
					else
					{
						health = health - 10;
						cout << "You missed he hit you\n Your health:" << health << endl;
						system("Pause"); 
						lose();
					}

					
					break;
					
				case 5:
					cout << "You have no weapons so you use a dagger you had in your pocket" << endl;
					trollMelee->dagger();
					if (variables.hit == 2)
					{
						variables.enemyHealth = variables.enemyHealth - damage;
						cout << "The enemy now has " << variables.enemyHealth << "health" << endl;
						system("Pause");
						win();
					}
					else
					{
						health = health - 10;
						cout << "You missed he hit you\n Your health:" << health << endl;
						system("Pause");
						lose();
					}

					
					break;
					
				case 6:
					cout << "You have no weapons so you use a bone you find on the battlefield" << endl;
					trollMelee->bone();
					if (variables.hit == 2)
					{
						variables.enemyHealth = variables.enemyHealth - damage;
						cout << "The enemy now has " << variables.enemyHealth << "health" << endl;
						system("Pause");
						win();
					}
					else
					{
						health = health - 10;
						cout << "You missed he hit you\n Your health:" << health << endl;
						system("Pause");
						lose();
					}

					
					break;
					
				default:
					break;
				}
			case 1:
				trollMelee->club();
				if (variables.hit == 2)
				{
					variables.enemyHealth = variables.enemyHealth - 30;
					cout << "You hit, Enemy has" << variables.enemyHealth << endl;
					system("Pause");
					win();
				}
				else
				{
					health = health - 10;
					cout << "You missed he hit you\n Your health:" << health << endl;
					system("Pause");
					lose();
				}
			case 2:
				trollMelee->saw();
				if (variables.hit == 2)
				{
					variables.enemyHealth = variables.enemyHealth - 60;
					cout << "You hit, Enemy has" << variables.enemyHealth << endl;
					system("Pause");
					win();
				}
				else
				{
					health = health - 10;
					cout << "You missed he hit you\n Your health:" << health << endl;
					system("Pause");
					lose();
				}
			case 3:
				trollMelee->whip();
				if (variables.hit == 2)
				{
					variables.enemyHealth = variables.enemyHealth - 20;
					cout << "You hit, Enemy has" << variables.enemyHealth << endl;
					system("Pause");
					win();
				}
				else
				{
					health = health - 10;
					cout << "You missed he hit you\n Your health:" << health << endl;
					system("Pause");
					lose();
				}
			case 4:
				trollMelee->glaive();
				if (variables.hit == 2)
				{
					variables.enemyHealth = variables.enemyHealth - 90;
					cout << "You hit, Enemy has" << variables.enemyHealth << endl;
					system("Pause");
					win();
				}
				else
				{
					health = health - 10;
					cout << "You missed he hit you\n Your health:" << health << endl;
					system("Pause");
					lose();
				}
			default:
				break;
			}

		case 2:
			switch (variables.weapon)
			{
			case 0:
				switch (randWeapon)
				{
				case 1:
					cout << "You have no weapons so you use your fists" << endl;
					orcMelee->punch();
					randomNumber(&variables.hit);
					if (variables.hit == 2)
					{
						variables.enemyHealth = variables.enemyHealth - damage;
						cout << "The enemy now has " << variables.enemyHealth << "health" << endl;
						system("Pause");
						win();
					}
					else
					{
						health = health - 10;
						cout << "You missed he hit you\n Your health:" << health << endl;
						system("Pause");
						lose();
					}
					break;
				case 2:
					cout << "You have no weapons so you use your feet" << endl;
					orcMelee->kick();
					randomNumber(&variables.hit);
					if (variables.hit == 2)
					{
						variables.enemyHealth = variables.enemyHealth - damage;
						cout << "The enemy now has " << variables.enemyHealth << "health" << endl;
						system("Pause");
						win();
					}
					else
					{
						health = health - 10;
						cout << "You missed he hit you\n Your health:" << health << endl;
						system("Pause");
						lose();
					}
					break;
				case 3:
					cout << "You have no weapons so you use a stick you find on the ground" << endl;
					orcMelee->stick();
					randomNumber(&variables.hit);
					if (variables.hit == 2)
					{
						variables.enemyHealth = variables.enemyHealth - damage;
						cout << "The enemy now has " << variables.enemyHealth << "health" << endl;
						system("Pause");
						win();
					}
					else
					{
						health = health - 10;
						cout << "You missed he hit you\n Your health:" << health << endl;
						system("Pause");
						lose();
					}
					break;
				case 4:
					cout << "You have no weapons so you use a frying pan you find on the ground\n dont know why its there but lets not ask questions." << endl;
					orcMelee->fryingPan();
					randomNumber(&variables.hit);
					if (variables.hit == 2)
					{
						variables.enemyHealth = variables.enemyHealth - damage;
						cout << "The enemy now has " << variables.enemyHealth << "health" << endl;
						system("Pause");
						win();
					}
					else
					{
						health = health - 10;
						cout << "You missed he hit you\n Your health:" << health << endl;
						system("Pause");
						lose();
					}
					break;
				case 5:
					cout << "You have no weapons so you use a dagger you had in your pocket" << endl;
					orcMelee->dagger();
					randomNumber(&variables.hit);
					if (variables.hit == 2)
					{
						variables.enemyHealth = variables.enemyHealth - damage;
						cout << "The enemy now has " << variables.enemyHealth << "health" << endl;
						system("Pause");
						win();
					}
					else
					{
						health = health - 10;
						cout << "You missed he hit you\n Your health:" << health << endl;
						system("Pause");
						lose();
					}
					break;
				case 6:
					cout << "You have no weapons so you use a bone you find on the battlefield" << endl;
					orcMelee->bone();
					randomNumber(&variables.hit);
					if (variables.hit == 2)
					{
						variables.enemyHealth = variables.enemyHealth - damage;
						cout << "The enemy now has " << variables.enemyHealth << "health" << endl;
						system("Pause");
						win();
					}
					else
					{
						health = health - 10;
						cout << "You missed he hit you\n Your health:" << health << endl;
						system("Pause");
						lose();
					}
					break;
				default:
					break;
				}
			case 1:
				orcMelee->hammer();
				randomNumber(&variables.hit);
				if (variables.hit == 2)
				{
					variables.enemyHealth = variables.enemyHealth - 60;
					cout << "You hit, Enemy has" << variables.enemyHealth << endl;
					system("Pause");
					win();
				}
				else
				{
					health = health - 10;
					cout << "You missed he hit you\n Your health:" << health << endl;
					system("Pause");
					lose();
				}
				break;
			case 2:
				orcMelee->axe();
				randomNumber(&variables.hit);
				if (variables.hit == 2)
				{
					variables.enemyHealth = variables.enemyHealth - 90;
					cout << "You hit, Enemy has" << variables.enemyHealth << endl;
					system("Pause");
					win();
				}
				else
				{
					health = health - 10;
					cout << "You missed he hit you\n Your health:" << health << endl;
					system("Pause");
					lose();
				}
				break;
			case 3:
				orcMelee->sword();
				randomNumber(&variables.hit);
				if (variables.hit == 2)
				{
					variables.enemyHealth = variables.enemyHealth - 30;
					cout << "You hit, Enemy has" << variables.enemyHealth << endl;
					system("Pause");
					win();
				}
				else
				{
					health = health - 10;
					cout << "You missed he hit you\n Your health:" << health << endl;
					system("Pause");
					lose();
				}
				break;
			case 4:
				orcMelee->spear();
				randomNumber(&variables.hit);
				if (variables.hit == 2)
				{
					variables.enemyHealth = variables.enemyHealth - 20;
					cout << "You hit, Enemy has" << variables.enemyHealth << endl;
					system("Pause");
					win();
				}
				else
				{
					health = health - 10;
					cout << "You missed he hit you\n Your health:" << health << endl;
					lose();
				}
				break;

			default:
				break;
			}

			break;

		default:
			break;
		}
	}

	//if you choose to defend 
	if (battleAction == 2)
	{
		switch (variables.shield)
		{
		case 1:
			if (variables.hit == 1)
			{
				cout << "He hit you but you used your shield\n Your health:" << health << endl;
				system("Pause");
				health -= 9;
				lose();
			}
			else
			{
				cout << "He missed" << endl;
				win();
			}
			break;
		case 2:
			if (variables.hit == 1)
			{
				cout << "He hit you but you used your shield\n Your health:" << health << endl;
				system("Pause");
				health -= 5;
				lose();
			}
			else
			{
				cout << "He missed" << endl;
				win();
			}
			break;
		case 3:
			if (variables.hit == 1)
			{
				cout << "He hit you but you used your shield\n Your health:" << health << endl;
				system("Pause");
				health -= 2;
				lose();
			}
			else
			{
				cout << "He missed" << endl;
				win();
			}
			break;
		default:
			break;
		}
	}

	//if you choose to use a spell
	if (battleAction == 3)
	{
		switch (character)
		{
		case 1:
			switch (variables.spell)
			{
			case 0:
				break;
			case 1:
				trollSpells->heal();
				health = 100;
				break;
			case 2:
				trollSpells->confusion();
				randomNumber(&variables.hit);
				if (variables.hit == 2)
				{
					variables.enemyHealth = variables.enemyHealth - 100;
					cout << "You hit, Enemy has" << variables.enemyHealth << endl;
					system("Pause");
					win();
				}
				else
				{
					health = health - 10;
					cout << "You missed he hit you\n Your health:" << health << endl;
					system("Pause");
					lose();
				}
				break;
			case 3:
				trollSpells->faithfulHound();
				randomNumber(&variables.hit);
				if (variables.hit == 2)
				{
					variables.enemyHealth = variables.enemyHealth - 150;
					cout << "You hit, Enemy has" << variables.enemyHealth << endl;
					system("Pause");
					win();
				}
				else
				{
					health = health - 10;
					cout << "You missed he hit you\n Your health:" << health << endl;
					system("Pause");
					lose();
				}
				break;
			case 4:
				trollSpells->callLightning();
				randomNumber(&variables.hit);
				if ( variables.hit == 2)
				{
					variables.enemyHealth = variables.enemyHealth - 200;
					cout << "You hit, Enemy has" << variables.enemyHealth << endl;
					system("Pause");
					win();
				}
				else
				{
					health = health - 10;
					cout << "You missed he hit you\n Your health:" << health << endl;
					system("Pause");
					lose();
				}
				break;
			case 5:
				trollSpells->chillTouch();
				randomNumber(&variables.hit);
				if (variables.hit == 2)
				{
					variables.enemyHealth = variables.enemyHealth - 230;
					cout << "You hit, Enemy has" << variables.enemyHealth << endl;
					system("Pause");
					win();
				}
				else
				{
					health = health - 10;
					cout << "You missed he hit you\n Your health:" << health << endl;
					system("Pause"); 
					lose();
				}
				break;
			}
		case 2:
			switch (variables.spell)
			{
			case 0:
				break;
			case 1:
				orcSpells->heal();
				health = 100;
				break;
			case 2:
				orcSpells->confusion();
				randomNumber(&variables.hit);
				if (variables.hit == 2)
				{
					variables.enemyHealth = variables.enemyHealth - 100;
					cout << "You hit, Enemy has" << variables.enemyHealth << endl;
					system("Pause");
					win();
				}
				else
				{
					health = health - 10;
					cout << "You missed he hit you\n Your health:" << health << endl;
					system("Pause");
					lose();
				}
				break;
			case 3:
				orcSpells->faithfulHound();
				randomNumber(&variables.hit);
				if (variables.hit == 2)
				{
					variables.enemyHealth = variables.enemyHealth - 150;
					cout << "You hit, Enemy has" << variables.enemyHealth << endl;
					system("Pause");
					win();
				}
				else
				{
					health = health - 10;
					cout << "You missed he hit you\n Your health:" << health << endl;
					system("Pause");
					lose();
				}
				break;
			case 4:
				orcSpells->fireball();
				randomNumber(&variables.hit);
				if (variables.hit == 2)
				{
					variables.enemyHealth = variables.enemyHealth - 230;
					cout << "You hit, Enemy has" << variables.enemyHealth << endl;
					system("Pause");
					win();
				}
				else
				{
					health = health - 10;
					cout << "You missed he hit you\n Your health:" << health << endl;
					system("Pause");
					lose();
				}
				break;
			case 5:
				orcSpells->darkness();
				randomNumber(&variables.hit);
				if (variables.hit == 2)
				{
					variables.enemyHealth = variables.enemyHealth - 200;
					cout << "You hit, Enemy has" << variables.enemyHealth << endl;
					system("Pause");
					win();
				}
				else
				{
					health = health - 10;
					cout << "You missed he hit you\n Your health:" << health << endl;
					system("Pause");
					lose();
				}
				break;
			}
			break;
			default:
				break;
			}
	}

}

//function creates a random number between 1 and 2 
void randomNumber(int *hit)
{
	*hit = (rand() % 2) + 1;
}

void win()
{
	if (variables.enemyHealth <= 0)
	{
		cout << "You have defeated the enemy and saved the kingdom" << endl;
		system("Pause");
		gameOver();
	}
	else
	{
		battle();
	}
}

void lose()
{
	//if you or the enemy dies the game is over
	if (health <= 0)
	{
		gameOver();
	}
	else
	{
		battle();
	}
}






