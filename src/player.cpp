#include "player.h"

#include "command.h"
#include "consts.h"

void Player::Update() {
  if (!execute) {
    if (IsKeyPressed(KEY_A)) {
      commands.emplace_back(std::make_unique<LeftCommand>(this));
    }
    if (IsKeyPressed(KEY_D)) {
      commands.emplace_back(std::make_unique<RightCommand>(this));
    }

    if (IsKeyPressed(KEY_W)) {
      commands.emplace_back(std::make_unique<JumpCommand>(this));
    }

    if (IsKeyPressed(KEY_Q)) {
      commands.emplace_back(std::make_unique<JumpLeftCommand>(this));
    }
    if (IsKeyPressed(KEY_E)) {
      commands.emplace_back(std::make_unique<JumpRightCommand>(this));
    }

    if (IsKeyPressed(KEY_ENTER) && !commands.empty()) {
      TraceLog(LOG_INFO, "Execute");
      execute = true;
    }
  }

  if (execute) {
    if (!go_next) {
      go_next = commands.at(current_cmd_idx)->Apply();
    } else {
      cooler += GetFrameTime();
      if (cooler >= cooldown) {
        cooler = 0;
        go_next = false;
        current_cmd_idx = (current_cmd_idx + 1) % commands.size();
      }
    }
  }
}

void Player::Draw() {
  auto drawY = y - anim_idle->GetHeight();

  if (is_running) {
    anim_run->Draw(x, drawY);
  } else if (isJumping) {
    anim_jump->Draw(x, drawY);
  } else {
    anim_idle->Draw(x, drawY);
  }

  if (!isJumping) {
    anim_jump->Reset();
  }
}

float Player::GetMiddleX() const {
  return x + anim_idle->GetWidth() / 2.0F;
}
Player::Player(Animation* anim_run, Animation* anim_idle, Animation* anim_jump, float x, float y)
    : anim_run(anim_run), anim_idle(anim_idle), anim_jump(anim_jump), x(x), y(y) {}
