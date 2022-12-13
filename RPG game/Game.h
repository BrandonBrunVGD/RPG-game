#pragma once
#include"Character.h"
#include "Location.h"

class Game{
private:

	bool m_playingGame;
	int m_difficulty;

public:

	Game();
	virtual ~Game();

	enum difficulty { Easy = 1, Normal, Hard };

	Character player; //Creates the player

	Location dungeon;
	Location town;
	Location merchant;
	Location wishingwell;
	Location localcave;
	Location home;

	void playingGame();

	void mainMenu(); // displays the main menu
	void settings();
	void difficultyMenu();
	void pauseMenu();
	void displayMap();
	void displayTown();

	void newGame(); //Creates a new game
	
	int getDifficulty() { return m_difficulty; }
protected:

	
};

