#include "context.h"

#include <raylib.h>

#include "consts.h"
#include "level_builder.h"
#include "player.h"
#include "scene_game.h"
#include "scene_logo.h"
#include "scene_menu.h"
#include "ui.h"

Context::Context() {
  SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
  InitWindow(WIDTH, HEIGHT, "Loopman");
  SetTargetFPS(30);
  SetTextureFilter(GetFontDefault().texture, FILTER_POINT);

  assets = std::make_unique<Assets>();

  scene_manager.Register<SceneLogo>();
  scene_manager.Register<SceneMenu>();

  auto* ui = new UI(UI_WIDTH, UI_HEIGHT, GAME_WIDTH, 0);

  {
    scene_manager.Register<SceneGame>(
        new Player(&(assets->player_attack_left_anim), &(assets->player_attack_right_anim),
                   &(assets->player_run_left_anim), &(assets->player_run_right_anim),
                   &(assets->player_idle_anim), &(assets->player_jump_anim), 0.0f, ToFloat(HEIGHT)),
        Level1(assets.get()), ui);
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
