#pragma once

#include <memory>
#include <vector>


class Tile;
class Portal;
class SceneGame;

class Level {
  std::vector<std::unique_ptr<Tile>> tiles;
  std::unique_ptr<Portal> portal_;
  SceneGame* parent_;

 public:
  const int width;
  const int height;

  Level(int width, int height);
  [[nodiscard]] Tile* Get(int x, int y) const;
  void Put(Tile* tile);
  void SetPortal(Portal* portal);
  void Draw();
  void Update();
  void SetParent(SceneGame* parent);
  ~Level();
};
