#pragma once

#include "raylib.h"
class SceneGame;

class UI {
  SceneGame* parent_{};
  RenderTexture2D target;
  const int width;
  const int height;
  int posX;
  int posY;

  int blink_counter=0;
  const int no_blink_frames=16;
 public:
  UI(int width, int height, int posX, int posY);
  void Draw();
  void Update();
  void SetParent(SceneGame *parent);
  ~UI();
};
