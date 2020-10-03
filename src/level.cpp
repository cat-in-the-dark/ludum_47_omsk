#include "level.h"

#include <raylib.h>

#include "consts.h"
#include "tile.h"

Tile* Level::Get(int x, int y) const {
  auto x_idx = GetTileX(x);
  auto y_idx = GetTileY(y);
  auto idx = x_idx + y_idx * width;
  return tiles.at(idx).get();
}
Level::Level(int width, int height) : tiles(height * width), width(width), height(height) {}
void Level::Put(Tile* tile) {
  auto x_idx = GetTileX(tile->GetX());
  auto y_idx = GetTileY(tile->GetY());
  TraceLog(LOG_INFO, "xi=%d yi=%d x=%d y=%d", x_idx, y_idx, tile->GetX(), tile->GetY());
  auto idx = x_idx + y_idx * width;
  tiles[idx].reset(tile);
}
void Level::Draw() {
  for (auto& el : tiles) {
    if (el) {
      DrawRectangle(ToRealX(GetTileX(el->GetX())), ToRealY(GetTileY(el->GetY())), TILE_WIDTH,
                    TILE_HEIGHT, GREEN);
      el->Draw();
    }
  }
}
void Level::Update() {
  for (auto& el : tiles) {
    if (el) {
      el->Update();
    }
  }
}
