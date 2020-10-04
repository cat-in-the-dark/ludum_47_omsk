#include "command.h"

#include <raylib.h>

#include "consts.h"
#include "player.h"

bool LeftCommand::Apply() {
  auto step = player->step_x * GetFrameTime();
  player->x -= step;
  distance += step;
  player->direction = -1;
  player->is_running = true;
  if (distance >= player->velocity_x) {
    distance = 0;
    player->x = ToFixedPosX(player->x);
    player->is_running = false;
    TraceLog(LOG_INFO, "done LeftCommand");
    return true;
  }
  return false;
}
LeftCommand::LeftCommand(Player* player) : player(player) {
  TraceLog(LOG_INFO, "LeftCommand");
}

RightCommand::RightCommand(Player* player) : player(player) {
  TraceLog(LOG_INFO, "RightCommand");
}
bool RightCommand::Apply() {
  auto step = player->step_x * GetFrameTime();
  player->x += step;
  distance += step;
  player->is_running = true;
  player->direction = 1;
  if (distance >= player->velocity_x) {
    player->is_running = false;
    distance = 0;
    player->x = ToFixedPosX(player->x);
    TraceLog(LOG_INFO, "done RightCommand");
    return true;
  }
  return false;
}
JumpCommand::JumpCommand(Player* player) : player(player) {
  TraceLog(LOG_INFO, "JumpCommand");
}
bool JumpCommand::Apply() {
  if (player->isJumping) {
    if (player->isGrounded) {
      player->isJumping = false;
      player->y = ToFixedPosY(player->y);
      player->velocity_y = 0;
      TraceLog(LOG_INFO, "done JumpCommand");
      return true;
    }
    return false;
  }

  if (!player->isGrounded) {
    // cannot jump in this state
    // go to the next state
    TraceLog(LOG_INFO, "skip JumpCommand");
    return false;
  }

  player->isJumping = true;
  player->isGrounded = false;
  player->velocity_y = player->init_jump_velocity;

  return false;
}
bool JumpLeftCommand::Apply() {
  if (!complete_jump) {
    complete_jump = jump.Apply();
  }
  if (!complete_left) {
    complete_left = left.Apply();
  }
  if (complete_jump && complete_left) {
    TraceLog(LOG_INFO, "done JumpLeftCommand");
    complete_jump = false;
    complete_left = false;
    return true;
  }
  return false;
}
JumpLeftCommand::JumpLeftCommand(Player* player) : jump(player), left(player) {}
JumpRightCommand::JumpRightCommand(Player* player) : jump(player), right(player) {}
bool JumpRightCommand::Apply() {
  if (!complete_jump) {
    complete_jump = jump.Apply();
  }
  if (!complete_right) {
    complete_right = right.Apply();
  }
  if (complete_jump && complete_right) {
    TraceLog(LOG_INFO, "done JumpRightCommand");
    complete_right = false;
    complete_jump = false;
    return true;
  }
  return false;
}
AttackCommand::AttackCommand(Player* player) : player(player) {}
bool AttackCommand::Apply() {
  if (player->is_attacking) {
    if (player->direction == 1 && player->anim_attack_right->IsFinished()) {
      player->is_attacking = false;
      return true;
    }
    if (player->direction == -1 && player->anim_attack_left->IsFinished()) {
      player->is_attacking = false;
      return true;
    }
    return false;
  }
  player->is_attacking = true;
  return false;
}
