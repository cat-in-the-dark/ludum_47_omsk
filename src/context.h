#pragma once

#include <memory>

#include "assets.h"
#include "scene_manager.h"

class Context {
 public:
  const int width = 960;
  const int height = 544;
  std::unique_ptr<Assets> assets;
  SceneManager scene_manager{};

  Context();
  void Update();
  ~Context();
};

Context* GetContext();
void SetContext(Context* context);