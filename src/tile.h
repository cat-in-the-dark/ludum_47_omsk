#pragma once

class Tile {
 public:
  [[nodiscard]] virtual int GetX() const = 0;
  [[nodiscard]] virtual int GetY() const = 0;
  [[nodiscard]] virtual bool IsCollidable() const = 0;
  virtual void Update() = 0;
  virtual void Draw() = 0;
  virtual ~Tile() = default;
};
