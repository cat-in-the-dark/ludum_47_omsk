#include "scene_game.h"

#include "context.h"
#include "level.h"
#include "player.h"
#include "tile.h"

void ApplyGravity(Player* player, Level* level) {
  if (!player->isGrounded) {
    player->velocity_y += player->g * GetFrameTime();
    player->y += player->velocity_y * GetFrameTime();
    // TODO(ilya): check hit the platform
  }
  auto* tile = level->Get(ToTileX(player->GetMiddleX()), ToTileY(player->y));
  if (tile != nullptr && tile->IsCollidable()) {
    player->isGrounded = true;
//    TraceLog(LOG_INFO, "touch down %d %d", ToTileX(player->GetMiddleX()), ToTileY(player->y));
  } else {
    if (player->y >= HEIGHT) {
      player->isGrounded = true;
      player->y = HEIGHT;
    } else {
      player->isGrounded = false;
    }
  }
}

void SceneGame::Dispose() {}
void SceneGame::Init() {}
bool SceneGame::Update() {
  //  TraceLog(LOG_INFO, "x=%f y=%f", player->x, player->y);
  ApplyGravity(player.get(), level.get());
  level->Update();
  player->Update();
  return false;
}
void SceneGame::Draw() {
  DrawTexture(GetContext()->assets->fon_10, 0, 0, WHITE);
  level->Draw();
  player->Draw();
}
SceneGame::SceneGame(Player* player, Level* level)
    : player(std::unique_ptr<Player>(player)), level(std::unique_ptr<Level>(level)) {}
