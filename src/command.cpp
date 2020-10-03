#include "command.h"

#include <raylib.h>

#include "player.h"
bool LeftCommand::Apply() {
  auto step = player->step_x * GetFrameTime();
  player->x -= step;
  distance += step;
  if (distance >= player->velocity_x) {
    distance = 0;
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
    TraceLog(LOG_INFO, "done RightCommand");
    return true;
  }
  return false;
}
