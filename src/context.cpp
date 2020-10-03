#include "context.h"

#include <raylib.h>

#include "consts.h"
#include "scene_game.h"
#include "scene_logo.h"

Context::Context() {
  SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
  InitWindow(WIDTH, HEIGHT, "Loopman");
  SetTargetFPS(30);
  SetTextureFilter(GetFontDefault().texture, FILTER_POINT);

  assets = std::make_unique<Assets>();

  scene_manager.Register<SceneLogo>();
  scene_manager.Register<SceneGame>();
}
Context::~Context() {
  CloseWindow();
}
void Context::Update() {
  scene_manager.Update();
  BeginDrawing();
  ClearBackground(BLACK);
  scene_manager.Draw();
  EndDrawing();
}
