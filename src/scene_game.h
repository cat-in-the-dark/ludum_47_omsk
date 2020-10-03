#pragma once

#include "consts.h"
#include "player.h"
#include "scene.h"

class SceneGame : public IScene {
  Player player{4, HEIGHT - TILE_HEIGHT};

 public:
  void Dispose() override;
  void Init() override;
  bool Update() override;
  void Draw() override;
};
