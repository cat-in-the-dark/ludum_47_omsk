#include "scene_game.h"

#include "context.h"
#include "level.h"
#include "player.h"

void SceneGame::Dispose() {}
void SceneGame::Init() {}
bool SceneGame::Update() {
  level->Update();
  player->Update();
  return false;
}
void SceneGame::Draw() {
  DrawTexture(GetContext()->assets->fon_10, 0, 0, WHITE);
  level->Draw();
  player->Draw();
}
SceneGame::SceneGame(Player* player, Level* level)
    : player(std::unique_ptr<Player>(player)), level(std::unique_ptr<Level>(level)) {}
