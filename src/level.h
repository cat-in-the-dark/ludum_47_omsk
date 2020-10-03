#pragma once

#include <memory>
#include <vector>

class Tile;

class Level {
  std::vector<std::unique_ptr<Tile>> tiles;

 public:
  const int width;
  const int height;

  Level(int width, int height);
  [[nodiscard]] Tile* Get(int x, int y) const;
  void Put(Tile* tile);
  void Draw();
  void Update();
  ~Level();
};
