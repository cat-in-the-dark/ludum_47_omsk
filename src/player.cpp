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
    if (IsKeyPressed(KEY_X)) {
      commands.emplace_back(std::make_unique<AttackCommand>(this));
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
  auto drawY = y - ToFloat(anim_idle->GetHeight());

  if (is_running) {
    if (direction == -1) {
      anim_run_left->Draw(x, drawY);
    } else {
      anim_run_right->Draw(x, drawY);
    }
  } else if (isJumping) {
    anim_jump->Draw(x, drawY);
  } else if (is_attacking) {
    if (direction == -1) {
      anim_attack_left->Draw(x, drawY);
    } else {
      anim_attack_right->Draw(x, drawY);
    }
  } else {
    anim_idle->Draw(x, drawY);
  }

  if (!isJumping) {
    anim_jump->Reset();
  }
  if (!is_attacking) {
    anim_attack_right->Reset();
    anim_attack_left->Reset();
  }
}

float Player::GetMiddleX() const {
  return x + anim_idle->GetWidth() / 2.0F;
}
Player::Player(Animation* anim_attack_left, Animation* anim_attack_right, Animation* anim_run_left,
               Animation* anim_run_right, Animation* anim_idle, Animation* anim_jump, float x,
               float y)
    : anim_attack_left(anim_attack_left),
      anim_attack_right(anim_attack_right),
      anim_run_left(anim_run_left),
      anim_run_right(anim_run_right),
      anim_idle(anim_idle),
      anim_jump(anim_jump),
      x(x),
      y(y) {}
const std::vector<std::unique_ptr<ICommand>>& Player::GetCommands() const {
  return commands;
}
size_t Player::GetCurrentCmdIdx() const {
  return current_cmd_idx;
}
bool Player::IsExecuting() const {
  return execute;
}
