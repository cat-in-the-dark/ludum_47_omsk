#pragma once

#include "scene.h"

#include <vector>
#include <memory>

class SceneManager {
  std::vector<std::unique_ptr<IScene>> scenes;
  int current_scene = 0;
  int prev_scene = -1;
  int next_scene = 0;
 public:
  template<typename TScene, typename... TParam>
  SceneManager& Register(TParam &&... params) {
    scenes.emplace_back(std::make_unique<TScene>(std::forward<TParam>(params)...));
    return *this;
  }
  void Update();
  void Draw();
};
