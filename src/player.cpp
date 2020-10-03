#include "player.h"

#include "command.h"
#include "consts.h"

void Player::Update() {
  if (IsKeyPressed(KEY_A)) {
    commands.emplace_back(std::make_unique<LeftCommand>(this));
  }
  if (IsKeyPressed(KEY_D)) {
    commands.emplace_back(std::make_unique<RightCommand>(this));
  }

  if (IsKeyPressed(KEY_W)) {
    commands.emplace_back(std::make_unique<JumpCommand>(this));
  }

  if (IsKeyPressed(KEY_ENTER) && !commands.empty()) {
    execute = true;
  }

  if (execute) {
    auto go_next = commands.at(current_cmd_idx)->Apply();
    if (go_next) {
      current_cmd_idx = (current_cmd_idx + 1) % commands.size();
    }
  }
}

void Player::Draw() {
  DrawTexture(*texture, ToInt(x), ToInt(y) - texture->height, WHITE);
}

Player::Player(const Texture2D* texture, int x, int y) : texture(texture), x(x), y(y) {}
double Player::GetMiddleX() const {
  return x + texture->width / 2.0;
}
