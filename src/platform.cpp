#include "platform.h"
void Platform::Draw() {
  DrawTexture(*texture, static_cast<int>(x), static_cast<int>(y), WHITE);
}
void Platform::Update() {}
Platform::Platform(const Texture2D* texture, int x, int y) : texture(texture), x(x), y(y) {}
int Platform::GetX() const {
  return x;
}
int Platform::GetY() const {
  return y;
}
bool Platform::IsCollidable() const {
  return is_collidable;
}
