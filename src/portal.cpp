#include "portal.h"

#include "consts.h"

void Portal::Draw() {
  anim->Draw(x, y - height);
}
void Portal::Update() {}
Portal::Portal(Animation* animation, float x, float y, int width, int height)
    : anim(animation), x(x), y(y), width(width), height(height) {}
Rectangle Portal::GetRec() const {
  auto w = static_cast<float>(width) / 2;
  auto h = static_cast<float>(height) / 2;
  return Rectangle{x + ToFloat(width) / 2 - w / 2, y - ToFloat(height) / 2 - h / 2, w, h};
}
