#ifndef PLAYER_H //If not defined
#define PLAYER_H // define it 

#include"raylib.h"

class Player { // create template with no defenitions in the header
	public:
		Player();

		int xPos;
		int yPos;
		int tileSize;
		int size;

		void drawPlayer();
		void spawnPlayer(int x, int y);
		void updatePosition(int x, int y);
};

#endif // PLAYER_H