#include "player.h"

#include "command.h"
#include "consts.h"
#include "context.h"

void ApplyGravity(Player* player) {
  if (!player->isGrounded) {
    player->velocity_y += player->g * GetFrameTime();
    player->y += player->velocity_y * GetFrameTime();
    // TODO(ilya): check hit the platform
  }
  if (player->y >= HEIGHT - TILE_HEIGHT) {
    player->isGrounded = true;
    player->y = HEIGHT - TILE_HEIGHT;
  }
}

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

  ApplyGravity(this);

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
