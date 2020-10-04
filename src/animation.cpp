#include "animation.h"

#include "consts.h"

Animation::Animation(const Texture2D& texture, int width, int height, double frame_time,
                     bool cycled, bool horizontal_flip)
    : texture(texture), width(width), height(height), frame_time(frame_time), cycled(cycled) {
  int rows = texture.height / height;
  int columns = texture.width / width;
  float h_flip = 1;
  if (horizontal_flip) {
    h_flip = -1;
  }
  frames.resize(rows * columns);
  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      auto idx = i + j * columns;
      frames[idx] = Rectangle{ToFloat(i * width), ToFloat(j * height), ToFloat(width) * h_flip,
                              ToFloat(height)};
    }
  }
  TraceLog(LOG_INFO, "Animation n_frames=%d id=%d", frames.size(), texture.id);
}
void Animation::Draw(float x, float y, Color tint) {
  time += GetFrameTime();
  if (time >= frame_time) {
    time = 0;
    if (!cycled && current_frame + 1 == frames.size()) {
      // stack on last frame
    } else {
      current_frame = (current_frame + 1) % frames.size();
    }
  }

  DrawTextureRec(texture, frames.at(current_frame), Vector2{x, y}, tint);
}
void Animation::Reset() {
  current_frame = 0;
}
bool Animation::IsFinished() const {
  return current_frame == frames.size() - 1;
}
