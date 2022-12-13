#include "Game.h"
#include "Character.h"
#include "Enemy.h"
#include "Location.h"
#include "Merchant.h"

Game::Game() {

	m_difficulty = Normal; //does litteraly nothing
	m_playingGame = false;
}

Game::~Game() {

}

void Game::mainMenu() {
	int choice;

	do {
		std::cout << "------------------------------------------------------------------------------------------------------------\n";
		std::cout << "Main Menu\n";
		std::cout << "1. New Game.\n";
		std::cout << "2. Settings.\n";
		std::cout << "0. Quit.\n";
	
		std::cin >> choice;
		switch (choice) {
		case 1:
			std::cout << "Creating New Game...\n";
			newGame();
			break;
		case 2:
			std::cout << "Opening Settings...\n";
			settings();
			break;
		case 0:
			std::cout << "Quiting Game...\n";
			exit(0);
			break;
		default:
			std::cout << "Invalid Input\n";
			break;
		}
	} while (choice != 0);
}

//puts the player through the character creator system then asks if they want to confirm
void Game::newGame() {
	char confirmCharacter;
	m_playingGame = true;

	player.newCharacter(player);
	std::cout << "Difficulty: " << m_difficulty << std::endl;
	std::cout << "Confirm Character? [y] or [n]\n";
	do {
		std::cin >> confirmCharacter;
		if (confirmCharacter == 'y') std::cout << "Confirmed Character.\n";
		else if (confirmCharacter == 'n') mainMenu();
		else std::cout << "Invalid Input.\n";
	} while (confirmCharacter != 'y');

	player.displayAllStats();

	std::cout << "\nLoading Game...\n";

	playingGame();
}

void Game::playingGame() {
	char pause;

	home.locHome(player);
	do {
		std::cout << "------------------------------------------------------------------------------------------------------------\n";
		std::cout << "Press \"p\" to pause the game.\n";
		std::cout << "Press \"i\" to open your inventory.\n";
		std::cout << "Press \"m\" to open the map.\n";
		std::cin >> pause;
		if (pause == 'p') pauseMenu();
		else if (pause == 'm') displayMap();
		else if (pause == 'i') player.Inventory(player, player.getPInventory(), player.getEquipedWeapon(), player.getEquipedHelmet(), player.getEquipedChest(), player.getEquipedGreaves());
		
	} while (m_playingGame != false);
	mainMenu();
}

void Game::settings() {
	int choice;

	std::cout << "------------------------------------------------------------------------------------------------------------\n";
	std::cout << "Settings\n";
	std::cout << "1. Difficulty.\n";
	std::cout << "0. Main Menu.\n";
	std::cin >> choice;

	do {
		switch (choice) {
		case 1:
			difficultyMenu();
			break;
		case 0:
			mainMenu();
			break;
		default:
			std::cout << "Invalid Input.\n";
			break;
		}
	} while (choice != 0);
	std::cout << "Going back to Main Menu...\n";
}
//sets the difficulty for the playthrough. does litteraly nothing :D
void Game::difficultyMenu() {
	int choice;

	std::cout << "------------------------------------------------------------------------------------------------------------\n";
	std::cout << "Current selection: " << m_difficulty << std::endl << std::endl;
	std::cout << "Difficulty\n";
	std::cout << "1. Easy.\n";
	std::cout << "2. Normal.\n";
	std::cout << "3. Hard.\n";
	std::cout << "0. Settings.\n";

		do {
			std::cin >> choice;
			if (m_playingGame == false) {

				switch (choice) {
				case 1:
					m_difficulty = Easy;
					break;
				case 2:
					m_difficulty = Normal;
					break;
				case 3:
					m_difficulty = Hard;
					break;
				case 0:
					std::cout << "Going back to Settings...\n";
					settings();
					break;
				default:
					std::cout << "Invalid Input.\n";
					break;
				}
				std::cout << "Current selection: " << m_difficulty << std::endl;
			}
			else {
				std::cout << "You cannot change the difficulty after your character is created.\n";
				choice = 0;
			}
		} while (choice != 0);
	
}

void Game::pauseMenu() {
	int choice;

	do {
		std::cout << "------------------------------------------------------------------------------------------------------------\n";
		std::cout << "\nPaused" << std::endl;
		std::cout << "1.Resume." << std::endl;
		std::cout << "2.Display Stats." << std::endl;
		std::cout << "3.Settings." << std::endl;
		std::cout << "0.Quit to Main Menu." << std::endl;

		std::cin >> choice;
		switch (choice) {
		case 1:
			std::cout << "Back to Game..." << std::endl;
			break;
		case 2:
			player.displayAllStats();
			break;
		case 3:
			std::cout << "Opening Settings...\n";
			settings();
			break;
		case 0:
			m_playingGame = false;
			break;
		default:
			std::cout << "Invalid Input" << std::endl;
		}
	} while (choice != 1 && choice != 0);
}

//displays the larger main map
void Game::displayMap() {
	int choice;
	do {
		std::cout << "----------------------------------------\n";
		std::cout << "|  [1]Town _____                  ^    |\n";
		std::cout << "|              |              ^  ^     |\n";
		std::cout << "|              |                ^  ^   |\n";
		std::cout << "|     ^        |_______ [2]Local Cave  |\n";
		std::cout << "|  ^  ^          |                     |\n";
		std::cout << "|       ^        |                   ^ |\n";
		std::cout << "|                |               ^    ^|\n";
		std::cout << "|            [3]Dungeon       ^   ^    |\n";
		std::cout << "|                               [0]Back|\n";
		std::cout << "----------------------------------------\n\n";
		std::cout << "Where would you like to visit?\n";

		std::cin >> choice;
		switch (choice) {

		case 1:
			displayTown();
			break;
		case 2:
			localcave.locLocalCave();
			break;
		case 3:
			dungeon.setLocLevel(1);
			if (player.getPLevel() < dungeon.getLocLevel()) {
				std::cout << "You must be level " << dungeon.getLocLevel() << " in order to enter.\n";
			}
			else dungeon.locDungeon(player, home, player.getPInventory());
			break;
		case 0:
			break;
		default:
			std::cout << "Invalid Input\n";
			break;
		}
	} while (choice != 0 && choice != 3);
}
//displays the smaller town map
void Game::displayTown() {
	int choice;
	do {
		std::cout << "----------------------------------------\n";
		std::cout << "|-----------[[]]   ||   [[]]-----------|\n";
		std::cout << "|___[1]Merchant____||______[2]Home_____|\n";
		std::cout << "|_______  _________  _________  _______|\n";
		std::cout << "|       ||         ||         || ^     |\n";
		std::cout << "|  ^    ||   [3]Wishing Well  ||    ^  |\n";
		std::cout << "| ^ ^   ||        ____        ||   ^   |\n";
		std::cout << "| ^   ^ ||        |YY|        ||^      |\n"; 
		std::cout << "|  ^    ||________[##]________||    ^  |\n";
		std::cout << "|       |______________________|[0]Back|\n";
		std::cout << "----------------------------------------\n\n";
		std::cout << "Where would you like to go?\n";

		std::cin >> choice;
		switch (choice) {
		case 1:
			merchant.locMerchant(player, player.getPInventory(), player.getEquipedWeapon(), player.getEquipedHelmet(), player.getEquipedChest(), player.getEquipedGreaves());
			break;
		case 2:
			home.locHome(player);
			break;
		case 3:
			wishingwell.locWishingWell(player, player.getPInventory());
			break;
		case 0:
			break;
		default:
			std::cout << "Invalid Input\n";
			break;
		}
	} while (choice != 0);
}