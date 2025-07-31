#include"player.h" 
#include "raylib.h"

#include<cmath>

// Contructor defenition
Player::Player(){
	xPos = 0;
	yPos = 0;
	tileSize = 32;
	size = 12;
}

// Class defenition before name for defenitions 
void Player::drawPlayer(){    
	DrawCircle(xPos + (tileSize - 2*size) / 2, yPos + (tileSize - size) / 2, size, BLUE);
}
  
void Player::spawnPlayer(int x, int y){
	xPos = floor(x/2/tileSize), yPos = floor(y/2/tileSize);
}

void Player::updatePosition(int x, int y){
	xPos = x, yPos = y;
    DrawCircle(xPos, yPos, size, BLUE);
}  