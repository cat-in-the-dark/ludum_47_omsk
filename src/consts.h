#pragma once

constexpr double LOGO_SHOW_TIME = 0.1;

constexpr int WIDTH = 960;
constexpr int HEIGHT = 544;
constexpr int TILE_HEIGHT = 24;
constexpr int TILE_WIDTH = 24;

float ToFloat(int v);
int ToFixedPosY(double x);
int ToFixedPosX(double y);
int ToInt(double v);
int ToTileX(double x);
int ToTileY(double y);
int ToRealX(int tileX);
int ToRealY(int tileY);
