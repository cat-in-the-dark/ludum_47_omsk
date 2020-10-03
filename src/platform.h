#pragma once

#include <raylib.h>

#include "consts.h"
#include "tile.h"

class Platform : public Tile {
  bool is_collidable = true;
  const Texture2D* texture;
  Vector2 pos;
  Rectangle rec;

 public:
  Platform(const Texture2D* texture, float x, float y, int texture_idx=0);
  void Draw() override;
  void Update() override;
  [[nodiscard]] int GetX() const override;
  [[nodiscard]] int GetY() const override;
  [[nodiscard]] bool IsCollidable() const override;
};
