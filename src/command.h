#pragma once

class Player;

class ICommand {
 public:
  virtual bool Apply() = 0;
  virtual ~ICommand() = default;
};

class LeftCommand : public ICommand {
  Player* player;
  double distance = 0;

 public:
  explicit LeftCommand(Player* player);
  bool Apply() override;
};

class RightCommand : public ICommand {
  Player* player;
  double distance = 0;

 public:
  explicit RightCommand(Player* player);
  bool Apply() override;
};

class JumpCommand : public ICommand {
  Player* player;
 public:
  explicit JumpCommand(Player* player);
  bool Apply() override;
};
class JumpLeftCommand: public ICommand {
  JumpCommand jump;
  LeftCommand left;
  bool complete_jump = false;
  bool complete_left = false;
 public:
  explicit JumpLeftCommand(Player* player);
  bool Apply() override;
};
class JumpRightCommand: public ICommand {
  JumpCommand jump;
  RightCommand right;
  bool complete_jump = false;
  bool complete_right = false;
 public:
  explicit JumpRightCommand(Player* player);
  bool Apply() override;
};
