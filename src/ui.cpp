#include "ui.h"

#include <array>

#include "consts.h"
#include "context.h"
#include "player.h"
#include "scene_game.h"

static std::array<const char*, 9> MAN_TEXT{"PRESS KEY TO ADD",
                                           "INSTRUCTION",
                                           "A - LEFT",
                                           "D - RIGHT",
                                           "W - JUMP",
                                           "Q - JUMP LEFT",
                                           "E - JUMP RIGHT",
                                           "X - ATTACK",
                                           "ENTER - EXECUTE"};

int DrawTextInBox(int ty, int width, const char* text) {
  int height = BIG_FONT + 2;
  auto tw = MeasureText(text, BIG_FONT);
  auto tx = width / 2 - tw / 2;
  DrawText(text, tx, ty + 2, BIG_FONT, COLOR_9);
  DrawRectangleLinesEx({0, ToFloat(ty), ToFloat(width), ToFloat(height)}, 2, COLOR_9);
  return height;
}

int GetLineY(int offset_top, int n_line) {
  return offset_top + 4 + n_line * SMALL_FONT;
}

void UI::Draw() {
  BeginTextureMode(target);
  ClearBackground(COLOR_15);

  auto inst_height = DrawTextInBox(UI_INSTRUCTIONS_Y, width, "INSTRUCTIONS");

  if (parent_->GetPlayer()->IsExecuting()) {
    auto idx = parent_->GetPlayer()->GetCurrentCmdIdx();
    DrawRectangle(0, GetLineY(inst_height, idx), width, SMALL_FONT, COLOR_3);
  } else {
    blink_counter++;
    if (blink_counter >= no_blink_frames) {
      if (blink_counter <= no_blink_frames * 2) {
        auto idx = parent_->GetPlayer()->GetCommands().size();
        DrawRectangle(0, GetLineY(inst_height, idx), width, SMALL_FONT, COLOR_3);
      } else {
        blink_counter = 0;
      }
    }
  }

  int i = 0;
  for (const auto& cmd : parent_->GetPlayer()->GetCommands()) {
    DrawText(cmd->GetName().c_str(), 6, GetLineY(inst_height, i), SMALL_FONT, COLOR_9);
    i++;
  }

  auto res_height = DrawTextInBox(UI_RESOURCES_Y, width, "MAN PAGE");
  for (size_t j = 0; j < MAN_TEXT.size(); j++) {
    DrawText(MAN_TEXT.at(j), 6, j*SMALL_FONT + res_height + UI_RESOURCES_Y, SMALL_FONT, COLOR_9);
  }

  DrawRectangleLinesEx({0, 0, ToFloat(width), ToFloat(height)}, 2, COLOR_9);
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
