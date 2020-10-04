#pragma once

#include <raylib.h>

constexpr double LOGO_SHOW_TIME = 0.1;

constexpr int WIDTH = 960;
constexpr int HEIGHT = 544;
constexpr int TILE_HEIGHT = 24;
constexpr int TILE_WIDTH = 24;
constexpr int BIG_TILE_WIDTH = 96;
constexpr int BIG_TILE_HEIGHT = 96;
constexpr int UI_HEIGHT = HEIGHT;
constexpr int UI_WIDTH = TILE_WIDTH * 10;
constexpr int GAME_WIDTH = WIDTH - UI_WIDTH;
constexpr int GAME_HEIGHT = HEIGHT;

constexpr int UI_INSTRUCTIONS_Y = 0;
constexpr int UI_RESOURCES_Y = HEIGHT - TILE_HEIGHT * 8;

constexpr int SMALL_FONT = 20;
constexpr int BIG_FONT = 22;

constexpr Color COLOR_3 = Color {95, 44, 131, 255};
constexpr Color COLOR_9 = Color{246, 219, 186 , 255};
constexpr Color COLOR_15 = Color{39, 24, 84 , 255};

float ToFloat(int v);
int ToFixedPosY(double x);
int ToFixedPosX(double y);
int ToInt(double v);
int ToTileX(double x);
int ToTileY(double y);
int ToRealX(int tileX);
int ToRealY(int tileY);
