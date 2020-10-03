#pragma once

#include <memory>

#include "consts.h"
#include "scene.h"

class Player;
class Level;

class SceneGame : public IScene {
  std::unique_ptr<Player> player;
  std::unique_ptr<Level> level;

 public:
  SceneGame(Player* player, Level* level);
  void Dispose() override;
  void Init() override;
  bool Update() override;
  void Draw() override;
};
