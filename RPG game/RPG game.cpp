#include"Game.h"
#include"Character.h"
#include"Enemy.h"

int main() {
	srand(static_cast<unsigned int>(time(0)));

	Game game;


	game.displayGame();

	return 0;
}

//TO DO.