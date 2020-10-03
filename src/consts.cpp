#include "consts.h"

#include <cmath>

int ToTileX(double x) {
  return ToInt(x / TILE_WIDTH);
}
int ToTileY(double y) {
  return ToInt((HEIGHT - y) / TILE_HEIGHT);
}
int ToRealX(int tileX) {
  return TILE_WIDTH * tileX;
}
int ToRealY(int tileY) {
  return HEIGHT - TILE_HEIGHT * tileY;
}
int ToInt(double v) {
  return static_cast<int>(std::round(v));
}
int ToFixedPosX(double x) {
  return ToRealX(ToTileX(x));
}
int ToFixedPosY(double y) {
  return ToRealY(ToTileY(y));
}
float ToFloat(int v) {
  return static_cast<float>(v);
}
