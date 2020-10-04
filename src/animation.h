#pragma once

#include <raylib.h>
#include <vector>

class Animation {
  const Texture2D texture;
  const int width;
  const int height;
  double frame_time;

  std::vector<Rectangle> frames{};
  size_t current_frame = 0;
  double time = 0;

  bool cycled;
 public:
  Animation(const Texture2D& texture, int width, int height, double frame_time, bool cycled, bool horizontal_flip=false);
  void Draw(float x, float y, Color tint = WHITE);
  void Reset();
  bool IsFinished() const;

  [[nodiscard]] int GetWidth() const {
    return width;
  }
  [[nodiscard]] int GetHeight() const {
    return height;
  }
};
