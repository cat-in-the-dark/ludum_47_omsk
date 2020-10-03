#include "context.h"

#include <raylib.h>


Context::Context() {
  SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
  InitWindow(width, height, "Loopman");
  SetTargetFPS(30);
  SetTextureFilter(GetFontDefault().texture, FILTER_POINT);

  assets = std::make_unique<Assets>();
}
Context::~Context() {
  CloseWindow();
}
void Context::Update() {
  BeginDrawing();
  ClearBackground(BLACK);
  DrawTexture(assets->title, 0,0, WHITE);
  EndDrawing();
}
