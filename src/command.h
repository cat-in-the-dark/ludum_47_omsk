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
  bool isJumping = false;

 public:
  explicit JumpCommand(Player* player);
  bool Apply() override;
};
