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

    std::vector<std::tuple<int, int, int>> tiles{
        {4, 4, 0},
        {5, 4, 1},
        {6, 4, 2},
        {7, 4, 3},
        {8, 8, 0},
        {9, 8, 1},
        {10, 8, 2},
        {11, 8, 3},
    };

    for (auto& el : tiles) {
      level->Put(new Platform(&assets->platform_1, ToRealX(std::get<0>(el)), ToRealY(std::get<1>(el)), std::get<2>(el)));
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
