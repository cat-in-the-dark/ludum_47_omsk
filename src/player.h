#pragma once

#include <cmath>
#include <memory>
#include <vector>

#include "command.h"

class Player {
  std::vector<std::unique_ptr<ICommand>> commands;
  size_t current_cmd_idx = 0;
  bool execute = false;

 public:
  const double time_to_apex = 0.5;
  const double jump_height = 96+32;
  const double g = (2 * jump_height) / (time_to_apex * time_to_apex);
  const double init_jump_velocity = -std::sqrt(2 * g * jump_height);

  double x;
  double y;
  double step_x = 96;
  double velocity_x = 96;
  double velocity_y = 0;
  bool isGrounded = true;

  Player(int x, int y);

  void Draw();
  void Update();
};
