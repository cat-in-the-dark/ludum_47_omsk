#pragma once

constexpr double LOGO_SHOW_TIME = 0.1;

constexpr int WIDTH = 960;
constexpr int HEIGHT = 544;
constexpr int TILE_HEIGHT = 96;
constexpr int TILE_WIDTH = 96;

int GetTileX(int x);
int GetTileY(int y);
int ToRealX(int tileX);
int ToRealY(int tileY);
