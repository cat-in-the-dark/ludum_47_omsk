#include "scene_game.h"
#include "context.h"

void SceneGame::Dispose() {}
void SceneGame::Init() {}
bool SceneGame::Update() {
  player.Update();

  return false;
}
void SceneGame::Draw() {
  DrawTexture(GetContext()->assets->fon_7, 0, 0, WHITE);
  player.Draw();
}
