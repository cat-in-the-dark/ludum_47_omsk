#pragma once

#include <raylib.h>

#include "animation.h"

class Assets {
 public:
  const Texture2D title;
  const Texture2D player;
  const Texture2D platform_1;
  const Texture2D fon_10;
  const Texture2D player_run;
  const Texture2D player_idle;
  const Texture2D player_jump;

  Animation player_run_anim;
  Animation player_idle_anim;
  Animation player_jump_anim;

  Assets();
};
