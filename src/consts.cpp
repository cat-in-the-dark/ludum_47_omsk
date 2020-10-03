#include "consts.h"
int GetTileX(int x) {
  return static_cast<int>(x / TILE_WIDTH);
}
int GetTileY(int y) {
  return static_cast<int>((HEIGHT - y) / TILE_HEIGHT);
}
int ToRealX(int tileX) {
  return TILE_WIDTH * tileX;
}
int ToRealY(int tileY) {
  return HEIGHT - TILE_HEIGHT * tileY;
}
