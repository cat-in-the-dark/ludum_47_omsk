#include "assets.h"

#include <raylib.h>

Assets::Assets()
    : title(LoadTexture("title.png")),
      art(LoadTexture("art.png")),
      player(LoadTexture("player.png")),
      portal(LoadTexture("portal.png")),
      platform_1(LoadTexture("platform_1.png")),
      fon_10(LoadTexture("fon_10.png")),
      player_run(LoadTexture("player_run.png")),
      player_idle(LoadTexture("player_idle.png")),
      player_jump(LoadTexture("player_jump.png")),
      player_attack(LoadTexture("player_attack.png")),
      portal_anim(portal, 96, 96, 0.4, true),
      player_run_right_anim(player_run, 96, 96, 0.1, true),
      player_run_left_anim(player_run, 96, 96, 0.1, true, true),
      player_idle_anim(player_idle, 96, 96, 0.15, true),
      player_jump_anim(player_jump, 96, 96, 1 / 6.0, false),
      player_attack_right_anim(player_attack, 96, 96, 0.1, false),
      player_attack_left_anim(player_attack, 96, 96, 0.1, false, true) {}
