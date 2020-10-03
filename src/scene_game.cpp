#include "scene_game.h"
void SceneGame::Dispose() {}
void SceneGame::Init() {}
bool SceneGame::Update() {
  player.Update();

  return false;
}
void SceneGame::Draw() {
  player.Draw();
}
