#include "assets.h"

#include <raylib.h>

Assets::Assets()
    : title(LoadTexture("title.png")),
      player(LoadTexture("player.png")),
      platform_1(LoadTexture("platform_1.png")),
      fon_7(LoadTexture("fon_7.png")) {}
