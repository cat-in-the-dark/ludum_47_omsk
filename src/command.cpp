#include "command.h"

#include <raylib.h>

#include "consts.h"
#include "player.h"

bool LeftCommand::Apply() {
  auto step = player->step_x * GetFrameTime();
  player->x -= step;
  distance += step;
  if (distance >= player->velocity_x) {
    distance = 0;
    player->x = ToFixedPosX(player->x);
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
  if (distance >= player->velocity_x) {
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
  if (isJumping) {
    if (player->isGrounded) {
      isJumping = false;
      player->y = ToFixedPosY(player->y);
      TraceLog(LOG_INFO, "done JumpCommand");
      return true;
    }
    return false;
  }

  if (!player->isGrounded) {
    // cannot jump in this state
    // go to the next state
    TraceLog(LOG_INFO, "skip JumpCommand");
    return true;
  }

  isJumping = true;
  player->isGrounded = false;
  player->velocity_y = player->init_jump_velocity;

  return false;
}
