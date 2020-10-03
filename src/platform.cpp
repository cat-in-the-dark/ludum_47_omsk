#include "platform.h"

#include "consts.h"

void Platform::Draw() {
  DrawTextureRec(*texture, rec, pos, WHITE);
}
void Platform::Update() {}
Platform::Platform(const Texture2D* texture, float x, float y, int texture_idx)
    : texture(texture), pos({x, y}), rec({ToFloat(texture_idx * TILE_WIDTH), 0, TILE_WIDTH, TILE_HEIGHT}) {}
int Platform::GetX() const {
  return ToInt(pos.x);
}
int Platform::GetY() const {
  return ToInt(pos.y);
}
bool Platform::IsCollidable() const {
  return is_collidable;
}
