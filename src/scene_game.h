#pragma once

#include <memory>

#include "consts.h"
#include "scene.h"

class Player;
class Level;
class UI;

class SceneGame : public IScene {
  std::unique_ptr<Player> player;
  std::unique_ptr<Level> level;
  std::unique_ptr<UI> ui;

  Shader shader;

 public:
  SceneGame(Player* player, Level* level, UI* ui);
  void Dispose() override;
  void Init() override;
  bool Update() override;
  void Draw() override;
  Player* GetPlayer();
  ~SceneGame();
};
