#include"gui.h"
#include"raylib.h"

void drawGrid(int x, int y, int tilesize){
  for (int i = 0; i < x; i += tilesize) {
    DrawLine(i, 0, i, y, LIGHTGRAY);
  }
  
  for (int j = 0; j < y; j += tilesize) {
    DrawLine(0, j, x, j, LIGHTGRAY);
  }
}

void drawPosition(int x, int y){
  DrawText((TextFormat("%i, %i", x, y)), 20, 20, 12, RED);
}