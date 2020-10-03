#pragma once

#include <memory>

#include "assets.h"
#include "scene_manager.h"

class Context {
  bool shouldRestart = false;

 public:
  std::unique_ptr<Assets> assets;
  SceneManager scene_manager{};

  bool ShouldRestart() const;
  bool ShouldStop() const;
  Context();
  void Update();
  ~Context();
};

Context* GetContext();
void SetContext(Context* context);
