#include "scene_logo.h"

#include "context.h"
#include <raylib.h>

void SceneLogo::Dispose() {}
void SceneLogo::Init() {}
bool SceneLogo::Update() {
  time += GetFrameTime();
  if (time >= show_time) {
    time = 0;
    return true;
  }
  return false;
}
void SceneLogo::Draw() {
  DrawTexture(GetContext()->assets->title, 0,0, WHITE);
}
