#pragma once

#include <raylib.h>

#include "tile.h"

class Platform : public Tile {
  bool is_collidable = true;
  const Texture2D* texture;
  int x;
  int y;

 public:
  Platform(const Texture2D* texture, int x, int y);
  void Draw() override;
  void Update() override;
  [[nodiscard]] int GetX() const override;
  [[nodiscard]] int GetY() const override;
  [[nodiscard]] bool IsCollidable() const override;
};
