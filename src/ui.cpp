#include "ui.h"

#include "consts.h"
#include "context.h"
#include "player.h"
#include "scene_game.h"

int DrawTextInBox(int ty, int width, const char* text) {
  int height = BIG_FONT + 2;
  auto tw = MeasureText(text, BIG_FONT);
  auto tx = width / 2 - tw / 2;
  DrawText(text, tx, ty + 2, BIG_FONT, COLOR_9);
  DrawRectangleLinesEx({0, ToFloat(ty), ToFloat(width), ToFloat(height)}, 2, COLOR_9);
  return height;
}

void UI::Draw() {
  BeginTextureMode(target);
  ClearBackground(COLOR_15);
  DrawRectangleLinesEx({0, 0, ToFloat(width), ToFloat(height)}, 2, COLOR_9);

  auto inst_height = DrawTextInBox(UI_INSTRUCTIONS_Y, width, "INSTRUCTIONS");

  int i = 0;
  for (const auto& cmd : parent_->GetPlayer()->GetCommands()) {
    DrawText(cmd->GetName().c_str(), 6, inst_height + 4 + i * SMALL_FONT, SMALL_FONT, COLOR_9);
    i++;
  }

  DrawTextInBox(UI_RESOURCES_Y, width, "RESOURCES");

  EndTextureMode();
  DrawTextureRec(target.texture,
                 {0, 0, ToFloat(target.texture.width), ToFloat(-target.texture.height)},
                 {ToFloat(posX), ToFloat(posY)}, WHITE);
}
void UI::Update() {}
UI::UI(int width, int height, int posX, int posY)
    : width(width),
      height(height),
      target(LoadRenderTexture(width, height)),
      posX(posX),
      posY(posY) {
  SetTextureFilter(target.texture, FILTER_POINT);
}
UI::~UI() {
  UnloadRenderTexture(target);
}
void UI::SetParent(SceneGame* parent) {
  parent_ = parent;
}
