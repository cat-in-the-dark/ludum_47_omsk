#include "level.h"

#include <raylib.h>

#include <memory>

#include "consts.h"
#include "player.h"
#include "portal.h"
#include "scene_game.h"
#include "tile.h"

Tile* Level::Get(int x, int y) const {
  auto idx = x + y * width;
  if (idx < 0 || idx >= static_cast<int>(tiles.size())) {
    return nullptr;
  }
  if (tiles.at(idx)) {
    return tiles.at(idx).get();
  }
  return nullptr;
}
Level::Level(int width, int height) : tiles(height * width), width(width), height(height) {}
void Level::Put(Tile* tile) {
  auto x_idx = ToTileX(tile->GetX());
  auto y_idx = ToTileY(tile->GetY());
  TraceLog(LOG_INFO, "Platform xi=%d yi=%d x=%d y=%d", x_idx, y_idx, tile->GetX(), tile->GetY());
  auto idx = x_idx + y_idx * width;
  tiles[idx].reset(tile);
}
void Level::Draw() {
  for (auto& el : tiles) {
    if (el) {
      el->Draw();
    }
  }
  if (portal_) {
    portal_->Draw();
  }

//  DrawRectangleRec(parent_->GetPlayer()->GetRec(), GREEN);
//  DrawRectangleRec(portal_->GetRec(), RED);
}
void Level::Update() {
  for (auto& el : tiles) {
    if (el) {
      el->Update();
    }
  }
  if (portal_) {
    portal_->Update();
  }
  auto plbbox = parent_->GetPlayer()->GetRec();
  auto pobbxo = portal_->GetRec();
  auto collision = CheckCollisionRecs(pobbxo, plbbox);
  if (collision) {
    parent_->SetWin();
  }
}
Level::~Level() = default;
void Level::SetPortal(Portal* portal) {
  portal_.reset(portal);
}
void Level::SetParent(SceneGame* parent) {
  parent_ = parent;
}
