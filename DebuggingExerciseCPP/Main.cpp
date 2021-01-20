#include "Player.h"
#include "Enemy.h"
#include <iostream>

/// <summary>
/// Prints a menu with the given options to the screen.
/// </summary>
/// <param name="context">The menu header. Displays at the top of the menu to give the player context.</param>
/// <param name="option1">The player's first option to select.</param>
/// <param name="option2">The player's second option to select.</param>
/// <returns>The decision made by the player.</returns>
int printOptions(const char* context, const char* option1, const char* option2)
{
	
	int input = -1;

	//Loops until the player selects an existing option
	while (input != 1 && input != 2)
	{
		//Prints the header and options for the menu.
		std::cout << context << std::endl;
		std::cout << "1. " << option1 << std::endl;
		std::cout << "2. " << option2 << std::endl;
		std::cout << "> ";

		//Gets player input.
		std::cin >> input;

		//Checks if the player entered an acceptable input.
		if (input != 1 && input != 2)
		{
			//If the player did not input something valid, print an error and clear the screen.
			std::cout << "Invalid Input. Try Again";
			system("pause");
			system("cls");
		}
	}
	
	//Return the player's choice.
	return input;
}

/// <summary>
/// Prints all stats for the given character to the screen.
/// </summary>
/// <param name="character">The character to print stats for.</param>
void printCharacterStats(Character* character)
{
	std::cout << "Name: " << character->getName() << std::endl;
	std::cout << "Health: " << character->getHealth() << std::endl;
	std::cout << "Attack Power: " << character->getDamage() << std::endl;
	std::cout << "Defense: " << character->getDefense() << std::endl;
}

/// <summary>
/// Begins a battle between the player and the given character. 
/// Gets player input for decisions and loops until either the player or the character is dead.
/// </summary>
/// <param name="player">One of the user controlled players.</param>
/// <param name="enemy">The current character the player is fighting.</param>
/// <returns>
/// The result of the battle. 
/// 0 - Player has lost
/// 1- Player has won
/// 2 - Player has escaped.
/// </returns>
int startPlayerBattle(Player* player, Character* enemy)
{
	//Loop while both the enemy and player are alive.
	while (player->getHealth() > 0 && enemy->getHealth() > 0)
	{
		system("cls");

		//Display stats for both characters.
		printCharacterStats(player);
		std::cout << std::endl;
		printCharacterStats(enemy);
		std::cout << std::endl;
		
		//Gets player action
		int choice = printOptions("Your Turn", "Attack", "Run");

		//If action select was attack, have the player attack the enemy. Otherwise, return that the player escaped.
		if (choice == 1)
			std::cout << "You did: " << player->attack(enemy) << " damage!" << std::endl;
		else
			return 2;

		//Enemy attack.
		std::cout << enemy->getName() << " did: " << enemy->attack(player) << " damage!" << std::endl;
		system("pause");
	}

	return player->getHealth() > 0;
}

int main()
{
	//Gets the player name for player initialization.
	std::cout << "Welcome! Enter a name!" << std::endl;
	std::cout << "> ";
	char* playerName = new char();
	std::cin >> playerName;
	//Initialize new player.
	Player* player = new Player(playerName, 100, 10, 5);

	//Gets player weapon choice and equips the choosen weapon.
	int choice = printOptions("Pick an Item: ", "Sword", "Shield");
	if (choice == 1)
		player->equipWeapon(Item(10));
	else if (choice == 2)
		player->equipShield(Item(10));

	//Initialize new enemy.
	Enemy* enemy = new Enemy("Monster", 50, 10, 5);
	
	//Start battle with enemy and player and record the result.
	int result = startPlayerBattle(player, enemy);

	//Based on the result of the battle, display the proper end game message.
	switch (result)
	{
	case 0:
		std::cout << "You Lose!!" << std::endl;
	case 1:
		std::cout << "You Win!!" << std::endl;
	case 2:
		std::cout << "You Escaped....." << std::endl;
	}
	system("pause");
}