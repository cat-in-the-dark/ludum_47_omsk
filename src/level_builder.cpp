#include "level_builder.h"

#include <utility>
#include <vector>

#include "assets.h"
#include "consts.h"
#include "level.h"
#include "platform.h"

Level* Level1(const Assets* assets) {
  auto* level = new Level(GAME_WIDTH / TILE_WIDTH, GAME_HEIGHT / TILE_HEIGHT);

  std::vector<std::tuple<int, int, int>> tiles{
      {4, 4, 0}, {5, 4, 1}, {6, 4, 2}, {7, 4, 3}, {8, 8, 0}, {9, 8, 1}, {10, 8, 2}, {11, 8, 3}, {4, 8, 0}, {5, 8, 1}, {6, 8, 2}, {7, 8, 3},
  };

  for (auto& el : tiles) {
    level->Put(new Platform(&assets->platform_1, ToRealX(std::get<0>(el)), ToRealY(std::get<1>(el)),
                            std::get<2>(el)));
  }

  return level;
}
