#include "raylib.h"

// My libraries / classes
#include "gui.h"
#include "player.h"

#include<cmath>
#include<iostream>

typedef enum GameScreen {MAIN = 0, TITLE} GameScreen;

#define TILESIZE 32
#define SCREENWIDTH 800
#define SCREENHEIGHT 450

int main(){
  Player player;
  player.tileSize = TILESIZE;
  player.spawnPlayer(SCREENWIDTH, SCREENHEIGHT);

  GameScreen currentScreen = TITLE;

  // Setup game window 
  InitWindow(SCREENWIDTH, SCREENHEIGHT, "Hello, World!");
  SetExitKey(KEY_NULL); //Disables escape to exit 
  SetTargetFPS(60);

  bool exitWindowRequested = false;
  bool exitWindow = false;

  while(!exitWindow){
    //Update Function
    switch(currentScreen){
      case MAIN: { // current gameplay 'level'
          if (IsKeyPressed(KEY_P)){
            currentScreen = TITLE;
          }

          if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) exitWindowRequested = true;

          if (exitWindowRequested){
            if (IsKeyPressed(KEY_Y)) exitWindow = true;
            else if (IsKeyPressed(KEY_N)) exitWindowRequested = false;
          }

          if (!exitWindowRequested) {
            // Keyboard inputs
            if (IsKeyPressed(KEY_RIGHT)) {
              player.updatePosition(player.xPos + TILESIZE, player.yPos);
            }
            if (IsKeyPressed(KEY_LEFT)) {
              player.updatePosition(player.xPos - TILESIZE, player.yPos);
            }
            if (IsKeyPressed(KEY_UP)) {
              player.updatePosition(player.xPos, player.yPos - TILESIZE);
            }
            if (IsKeyPressed(KEY_DOWN)) {
              player.updatePosition(player.xPos, player.yPos + TILESIZE);
            }
          }

          //Draw function begin
          BeginDrawing();

          ClearBackground(RAYWHITE);
          
          drawGrid(SCREENWIDTH, SCREENHEIGHT, TILESIZE);
          drawPosition(player.xPos, player.yPos);
          player.drawPlayer();
          
          if (exitWindowRequested){
            DrawRectangle(0, 100, SCREENWIDTH, 200, BLACK);
            DrawText("Exit the game? [y/n]", 40, 180, 30, WHITE);
          }
        }break;

        case TITLE:{ // current placeholder alternate 'level'
          if (IsKeyPressed(KEY_P)){
            currentScreen = MAIN;
          }

          ClearBackground(BLUE);
          DrawRectangle(0, 100, SCREENWIDTH, 200, BLACK);
          DrawText("Menu", 40, 180, 30, WHITE);
        }break;
      }
    
    EndDrawing();
    // Draw function end 
  }
  
  CloseWindow();
  return 0;
}
