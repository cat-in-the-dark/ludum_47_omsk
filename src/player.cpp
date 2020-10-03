#include "player.h"

#include "command.h"
#include "context.h"

void Player::Update() {
  if (IsKeyPressed(KEY_LEFT)) {
    commands.emplace_back(std::make_unique<LeftCommand>(this));
  }
  if (IsKeyPressed(KEY_RIGHT)) {
    commands.emplace_back(std::make_unique<RightCommand>(this));
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
  DrawTexture(GetContext()->assets->player, static_cast<int>(x), static_cast<int>(y), WHITE);
}

Player::Player(int x, int y) : x(x), y(y) {}
Player::~Player() {}
