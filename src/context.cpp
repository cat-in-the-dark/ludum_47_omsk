#include "context.h"

#include <raylib.h>

#include <utility>

#include "consts.h"
#include "level.h"
#include "platform.h"
#include "player.h"
#include "scene_game.h"
#include "scene_logo.h"

Context::Context() {
  SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
  InitWindow(WIDTH, HEIGHT, "Loopman");
  SetTargetFPS(30);
  SetTextureFilter(GetFontDefault().texture, FILTER_POINT);

  assets = std::make_unique<Assets>();

  scene_manager.Register<SceneLogo>();

  {
    // FIRST level
    auto* level = new Level(WIDTH / TILE_WIDTH, HEIGHT / TILE_HEIGHT);

    std::vector<std::pair<int, int>> tiles{{1, 4}, {2, 8}};

    for (auto& el : tiles) {
      level->Put(new Platform(&assets->platform_1, ToRealX(el.first), ToRealY(el.second)));
    }

    scene_manager.Register<SceneGame>(new Player(&(assets->player), 0, HEIGHT), level);
  }
}
Context::~Context() {
  CloseWindow();
}
void Context::Update() {
  if (IsKeyPressed(KEY_R)) {
    shouldRestart = true;
  }
  scene_manager.Update();
  BeginDrawing();
  ClearBackground(BLACK);
  scene_manager.Draw();
  EndDrawing();
}
bool Context::ShouldRestart() const {
  return WindowShouldClose() || shouldRestart;
}
bool Context::ShouldStop() const {
  return WindowShouldClose();
}