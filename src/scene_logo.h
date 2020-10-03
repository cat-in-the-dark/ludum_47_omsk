#pragma once

#include "scene.h"

class SceneLogo : public IScene {
  double time = 0;
  const double show_time = 2;

 public:
  void Dispose() override;
  void Init() override;
  bool Update() override;
  void Draw() override;
};
