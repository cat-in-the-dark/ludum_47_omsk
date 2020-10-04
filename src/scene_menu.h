#pragma once

#include "consts.h"
#include "scene.h"

class SceneMenu : public IScene {
  int blink_counter=0;
  const int no_blink_frames=16;
 public:
  void Dispose() override;
  void Init() override;
  bool Update() override;
  void Draw() override;
};
