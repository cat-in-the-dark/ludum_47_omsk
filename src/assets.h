#pragma once

#include <raylib.h>

#include "animation.h"

class Assets {
 public:
  const Texture2D title;
  const Texture2D art;
  const Texture2D player;
  const Texture2D platform_1;
  const Texture2D fon_10;
  const Texture2D player_run;
  const Texture2D player_idle;
  const Texture2D player_jump;
  const Texture2D player_attack;

  Animation player_run_right_anim;
  Animation player_run_left_anim;
  Animation player_idle_anim;
  Animation player_jump_anim;
  Animation player_attack_right_anim;
  Animation player_attack_left_anim;

  Assets();
};
