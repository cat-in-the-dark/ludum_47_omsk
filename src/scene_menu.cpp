#include "scene_menu.h"

#include <raylib.h>

#include "context.h"

void SceneMenu::Dispose() {}
void SceneMenu::Init() {}
bool SceneMenu::Update() {
  if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
    return true;
  }
  return false;
}
void SceneMenu::Draw() {
  DrawTexture(GetContext()->assets->art, 0, 0, WHITE);

  blink_counter++;
  if (blink_counter >= no_blink_frames) {
    if (blink_counter <= no_blink_frames * 2) {
      DrawText("PRESS ENTER TO HACK", 32, HEIGHT - 32, 24, COLOR_9);
    } else {
      blink_counter = 0;
    }
  }
}
