#include "assets.h"

#include <raylib.h>

Assets::Assets()
    : title(LoadTexture("title.png")),
      player(LoadTexture("player.png")),
      platform_1(LoadTexture("platform_1.png")),
      fon_10(LoadTexture("fon_10.png")) {}
