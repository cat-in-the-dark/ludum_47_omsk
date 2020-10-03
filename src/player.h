#pragma once

#include <memory>
#include <vector>

class ICommand;

class Player {
  std::vector<std::unique_ptr<ICommand>> commands;
  size_t current_cmd_idx = 0;
  bool execute = false;

 public:
  double x;
  double y;
  double step_x = 96;
  double velocity_x = 96;
  double velocity_y = 0;
  double jump_imp = 3;

  Player(int x, int y);

  void Draw();
  void Update();
  ~Player();
};
