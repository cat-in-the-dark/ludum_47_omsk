#pragma once

#include <raylib.h>

#include <cmath>
#include <memory>
#include <vector>

#include "animation.h"
#include "command.h"
#include "consts.h"

class Player {
  std::vector<std::unique_ptr<ICommand>> commands;
  size_t current_cmd_idx = 0;
  bool execute = false;

  Animation* const anim_run;
  Animation* const anim_idle;
  Animation* const anim_jump;

 public:
  const float time_to_apex = 0.5;
  const float jump_height = BIG_TILE_HEIGHT + TILE_HEIGHT * 1.5;
  const float g = (2 * jump_height) / (time_to_apex * time_to_apex);
  const float init_jump_velocity = -std::sqrt(2 * g * jump_height);

  float x;
  float y;
  float step_x = BIG_TILE_WIDTH;
  float velocity_x = BIG_TILE_WIDTH;
  float velocity_y = 0;
  bool isGrounded = true;
  bool isJumping = false;
  bool is_idle = true;
  bool is_running = false;
  bool go_next = false;
  float cooler = 0;
  const float cooldown = 0.2;

  Player(Animation* anim_run, Animation* anim_idle, Animation* anim_jump, float x, float y);

  void Draw();
  void Update();

  [[nodiscard]] float GetMiddleX() const;

  [[nodiscard]] const std::vector<std::unique_ptr<ICommand>>& GetCommands() const;
  size_t GetCurrentCmdIdx() const;
  bool IsExecuting() const;
};
