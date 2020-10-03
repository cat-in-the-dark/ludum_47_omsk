#include "scene_logo.h"

#include <raylib.h>

#include "context.h"

void SceneLogo::Dispose() {}
void SceneLogo::Init() {
  time = 0;
}
bool SceneLogo::Update() {
  time += GetFrameTime();
  if (time >= show_time) {
    return true;
  }
  if (IsKeyPressed(KEY_SPACE)) {
    return true;
  }
  return false;
}
void SceneLogo::Draw() {
  DrawTexture(GetContext()->assets->title, 0, 0, WHITE);
}
