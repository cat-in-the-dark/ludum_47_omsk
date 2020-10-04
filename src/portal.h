#pragma once

#include <raylib.h>

#include "animation.h"

class Portal {
 public:
  Animation* anim;
  float x;
  float y;
  const int width;
  const int height;
  Portal(Animation* animation, float x, float y, int width, int height);
  void Draw();
  void Update();
  [[nodiscard]] Rectangle GetRec() const;
};
