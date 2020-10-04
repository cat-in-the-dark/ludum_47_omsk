#pragma once

#include <string>

class Player;

class ICommand {
 public:
  virtual bool Apply() = 0;
  virtual std::string GetName() const = 0;
  virtual ~ICommand() = default;
};

class LeftCommand : public ICommand {
  Player* player;
  double distance = 0;

 public:
  explicit LeftCommand(Player* player);
  bool Apply() override;
  std::string GetName() const override {
    return "MOV LEFT";
  }
};

class RightCommand : public ICommand {
  Player* player;
  double distance = 0;

 public:
  explicit RightCommand(Player* player);
  bool Apply() override;
  std::string GetName() const override {
    return "MOV RIGHT";
  }
};

class JumpCommand : public ICommand {
  Player* player;
 public:
  explicit JumpCommand(Player* player);
  bool Apply() override;
  std::string GetName() const override {
    return "CALL JUMP";
  }
};
class JumpLeftCommand: public ICommand {
  JumpCommand jump;
  LeftCommand left;
  bool complete_jump = false;
  bool complete_left = false;
 public:
  explicit JumpLeftCommand(Player* player);
  bool Apply() override;
  std::string GetName() const override {
    return "CALL JUMP_LEFT";
  }
};
class JumpRightCommand: public ICommand {
  JumpCommand jump;
  RightCommand right;
  bool complete_jump = false;
  bool complete_right = false;
 public:
  explicit JumpRightCommand(Player* player);
  bool Apply() override;
  std::string GetName() const override {
    return "CALL JUMP_RIGHT";
  }
};
