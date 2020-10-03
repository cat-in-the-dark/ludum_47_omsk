#pragma once

#include <memory>

#include "assets.h"
#include "scene_manager.h"

class Context {
 public:
  std::unique_ptr<Assets> assets;
  SceneManager scene_manager{};

  Context();
  void Update();
  ~Context();
};

Context* GetContext();
void SetContext(Context* context);