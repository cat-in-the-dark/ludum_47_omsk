#pragma once

#include "consts.h"
#include "scene.h"

class SceneLogo : public IScene {
  double time = 0;
  const double show_time = LOGO_SHOW_TIME;

 public:
  void Dispose() override;
  void Init() override;
  bool Update() override;
  void Draw() override;
};
